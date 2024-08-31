/**
 The Kipl Programming Language

 File: lexer/lexer.h

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#ifndef LEXER_H
#define LEXER_H

#include "../token/token.h"
#include "stdbool.h"

typedef struct _lexer {
    char* source;
    const char* fileName;
    unsigned int currentPosition;
    unsigned int currentLine;
    unsigned int currentColumn;
} Lexer;

/*
 * @function: createLexer
 * @description: create a lexer
 * @arguments: char* source, char* fileName
 * @return: Lexer*
 */
Lexer* createLexer(char* source, const char* fileName);

/*
 * @function: scanner
 * @description: main lexer func. Return first token
 * @arguments: char* source, char* fileName
 * @return: Token*
 */
Token* scanner(char* source, char* fileName);

/*
 * @function: scanToken
 * @description: Scan token
 * @arguments: nothing
 * @return: Token*
 */
Token* scanToken();

/*
 * @function: stringLiteral
 * @description: Crate STRING_LITERAL token and return
 * @arguments: nothing
 * @return: Token*
 */
Token* stringLiteral();

/*
 * @function: identifierLiteral
 * @description: Crate IDENTIFIER_LITERAL token and return
 * @arguments: char c
 * @return: Token*
 */
Token* identifierLiteral(char c);

/*
 * @function: numberLiteral
 * @description: Crate NUMBER_LITERAL token and return
 * @arguments: char c
 * @return: Token*
 */
Token* numberLiteral(char c);

/*
 * @function: skipWhiteSpace
 * @description: skip white space and skip comment lines
 * @arguments: nothing
 * @return: void
 */
void skipWhiteSpace();

/*
 * @function: isMatch
 * @description: check next peek is match
 * @arguments: char c
 * @return: bool
 */
bool isMatch(char c);

/*
 * @function: peek
 * @description: get last char
 * @arguments: nothing
 * @return: void
 */
char peek();

/*
 * @function: nextPeek
 * @description: get last char's next
 * @arguments: nothing
 * @return: void
 */
char nextPeek();

/*
 * @function: advance
 * @description: advance position and return now position
 * @arguments: nothing
 * @return: char
 */
char advance();

/*
 * @function: isAlpha
 * @description: char is in alphabet? true or false
 * @arguments: char c
 * @return: bool
 */
bool isAlpha(char c);

/*
 * @function: isDigit
 * @description: char is numeric? true or false
 * @arguments: char c
 * @return: bool
 */
bool isDigit(char c);

/*
 * @function: isAtEnd
 * @description: position is at end? true or false
 * @arguments: nothing
 * @return: bool
 */
bool isAtEnd();

/*
 * @function: freeLexer
 * @description: free allocated memory
 * @arguments: nothing
 * @return: void
 */
void freeLexer();

#endif //LEXER_H
