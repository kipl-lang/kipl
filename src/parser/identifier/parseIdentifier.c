//
// Created by Kerem on 20/08/2024.
//

#include "parseIdentifier.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../global.h"
#include "../error/error.h"
#include "../expressions/data.h"
#include "../expressions/parseExpressions.h"
#include "../helpers/dataLinkedList/dataLinkedList.h"
#include "../helpers/typeConversion/toString.h"

void parseIdentifier() {
    // FUNCTION
    if(currentToken->next->type == TOKEN_BRACKET_ROUND_LEFT) {
        char* funcName = currentToken->value;
        Function* func = getFunc(funcName);
        if(func != NULL) {
            createFuncCallStatus(openRoundBracket, openCurlyBracket);
            openRoundBracket++;

            currentToken = currentToken->next;
            currentToken = currentToken->next;

            // PARAMETRE DURUMLARI KONTROL EDILECEK
            // SONRASINDA ROUND-RIGHT TOKENDAN SONRA CURLY LEFT E GİDİLECEK VE PAREMTERLEER SCOPEA İŞLENECEK.


            // gelen parametreler
            DataLinkedList* dataList = NULL;

            while(currentToken->type != TOKEN_EOF) {
                if(currentToken->type == TOKEN_BRACKET_ROUND_RIGHT)
                    break;

                Data* getData = parseExpressions();

                if(getData != NULL) {
                    DataLinkedList* newListItem = (DataLinkedList*) malloc(sizeof(DataLinkedList));
                    newListItem->data = getData;
                    newListItem->next = NULL;

                    if(dataList == NULL) {
                        dataList = newListItem;
                    } else {
                        DataLinkedList* tempDL = dataList;
                        while(tempDL->next != NULL)
                            tempDL = tempDL->next;
                        tempDL->next = newListItem;
                    }

                    if(currentToken->type == TOKEN_COMMA)
                        currentToken = currentToken->next;
                    else
                        break;
                } else {
                    showError(ERROR_SYNTAX, "Expected argument");
                }
            }

            if(currentToken->type == TOKEN_BRACKET_ROUND_RIGHT) {
                openRoundBracket--;

                Token* copyTokens = copyTokensFromFunc(func);
                Token* funcLastToken = getLastToken(copyTokens);
                funcLastToken->next = currentToken->next;
                currentToken->next = copyTokens;
                currentToken = currentToken->next;

            } else {
                showError(ERROR_SYNTAX, "Expected ')'");
            }
        } else {
            char errMsg[256];
            sprintf(errMsg, "%s undefined", currentToken->value);
            showError(ERROR_RUNTIME, errMsg);
        }
    }
    // VARIABLE
    else {
        if(!isVariableInAllScope(currentToken->value)) {
            char errMsg[256];
            sprintf(errMsg, "%s undefined", currentToken->value);
            showError(ERROR_RUNTIME, errMsg);
        }

        char* varName = currentToken->value;

        currentToken = currentToken->next;

        if(currentToken->type == TOKEN_EOF)
            return;

        if(currentToken->type == TOKEN_EQUAL) {
            currentToken = currentToken->next;
            Data* data = parseExpressions();
            if(data != NULL) {
                assignToVariable(varName, data);
            } else {
                showError(ERROR_SYNTAX, "Expected <value> after var <name> : <type> = ");
            }
        } else if(currentToken->type == TOKEN_PLUS_EQUAL) {
            currentToken = currentToken->next;
            Data* data = parseExpressions();
            Data* lastData = getDataFromVariable(varName);

            if(data != NULL) {
                if(data->dataType == TYPE_STRING) {
                    char newValue[strlen(lastData->value) + strlen(data->value) + 1];
                    sprintf(newValue, "%s%s", lastData->value, data->value);
                    assignToVariable(varName, createData(TYPE_STRING, strdup(newValue)));
                } else if(dataTypeIsNumber(lastData->dataType) && dataTypeIsNumber(data->dataType)) {
                    double operand1 = atof(lastData->value);
                    double operand2 = atof(data->value);
                    char* result = doubleToString(operand1 + operand2);

                    assignToVariable(varName, createData(TYPE_F64, result));
                    freeData(lastData);
                    freeData(data);
                } else {
                    showError(ERROR_SYNTAX, "'+=' operator was used incorrectly");
                }
            } else {
                showError(ERROR_SYNTAX, "Expected <value> after <name>  += ");
            }
        } else if(currentToken->type == TOKEN_MINUS_EQUAL) {
            currentToken = currentToken->next;
            Data* data = parseExpressions();
            Data* lastData = getDataFromVariable(varName);

            if(data != NULL) {
                if(dataTypeIsNumber(lastData->dataType) && dataTypeIsNumber(data->dataType)) {
                    double operand1 = atof(lastData->value);
                    double operand2 = atof(data->value);
                    char* result = doubleToString(operand1 - operand2);

                    assignToVariable(varName, createData(TYPE_F64, result));
                    freeData(lastData);
                    freeData(data);
                } else {
                    showError(ERROR_SYNTAX, "'-=' operator was used incorrectly");
                }
            } else {
                showError(ERROR_SYNTAX, "Expected <value> after <name>  -= ");
            }
        } else if(currentToken->type == TOKEN_MULTIPLY_EQUAL) {
            currentToken = currentToken->next;
            Data* data = parseExpressions();
            Data* lastData = getDataFromVariable(varName);

            if(data != NULL) {
                if(dataTypeIsNumber(lastData->dataType) && dataTypeIsNumber(data->dataType)) {
                    double operand1 = atof(lastData->value);
                    double operand2 = atof(data->value);
                    char* result = doubleToString(operand1 * operand2);

                    assignToVariable(varName, createData(TYPE_F64, result));
                    freeData(lastData);
                    freeData(data);
                } else {
                    showError(ERROR_SYNTAX, "'-=' operator was used incorrectly");
                }
            } else {
                showError(ERROR_SYNTAX, "Expected <value> after <name>  *= ");
            }

        } else if(currentToken->type == TOKEN_DIVIDE_EQUAL) {
            currentToken = currentToken->next;
            Data* data = parseExpressions();
            Data* lastData = getDataFromVariable(varName);

            if(data != NULL) {
                if(dataTypeIsNumber(lastData->dataType) && dataTypeIsNumber(data->dataType)) {
                    double operand1 = atof(lastData->value);
                    double operand2 = atof(data->value);
                    if(operand2 == 0)
                        showError(ERROR_RUNTIME, "Division by zero");
                    char* result = doubleToString(operand1 / operand2);

                    assignToVariable(varName, createData(TYPE_F64, result));
                    freeData(lastData);
                    freeData(data);
                } else {
                    showError(ERROR_SYNTAX, "'/=' operator was used incorrectly");
                }
            } else {
                showError(ERROR_SYNTAX, "Expected <value> after <name>  /= ");
            }

        } else if(currentToken->type == TOKEN_MODULUS_EQUAL) {
            currentToken = currentToken->next;
            Data* data = parseExpressions();
            Data* lastData = getDataFromVariable(varName);

            if(data != NULL) {
                if(dataTypeIsNumber(lastData->dataType) && dataTypeIsNumber(data->dataType)) {
                    double operand1 = atof(lastData->value);
                    double operand2 = atof(data->value);
                    if(operand2 == 0)
                        showError(ERROR_RUNTIME, "Modulus by zero");
                    char* result = __uint128_tToString((int) operand1 % (int) operand2);

                    assignToVariable(varName, createData(TYPE_F64, result));
                    freeData(lastData);
                    freeData(data);
                } else {
                    showError(ERROR_SYNTAX, "'%=' operator was used incorrectly");
                }
            } else {
                showError(ERROR_SYNTAX, "Expected <value> after <name>  %= ");
            }

        } else if(currentToken->type == TOKEN_EQUAL_POWER) {
            currentToken = currentToken->next;
            Data* data = parseExpressions();
            Data* lastData = getDataFromVariable(varName);

            if(data != NULL) {
                if(dataTypeIsNumber(lastData->dataType) && dataTypeIsNumber(data->dataType)) {
                    double operand1 = atof(lastData->value);
                    double operand2 = atof(data->value);
                    char* result = doubleToString(pow(operand1, operand2));

                    assignToVariable(varName, createData(TYPE_F64, result));
                    freeData(lastData);
                    freeData(data);
                } else {
                    showError(ERROR_SYNTAX, "'**=' operator was used incorrectly");
                }
            } else {
                showError(ERROR_SYNTAX, "Expected <value> after <name>  **= ");
            }

        } else {
            char errMsg[50];
            sprintf(errMsg, "%s is not used", varName);
            showError(ERROR_SYNTAX, errMsg);
        }
    }
}
