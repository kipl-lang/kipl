/**
The Kipl Programming Language

 File: lexer/lexer.c

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#include "lexer.h"
#include <stdlib.h>
#include <string.h>

Lexer* lexer;

Lexer* createLexer(char* source) {
    Lexer* lexer = (Lexer*)malloc(sizeof(Lexer));

    lexer->source = source;
    lexer->currentPosition = 0;
    lexer->currentLine = 1;
    lexer->currentColumn = 0;

    return lexer;
}

Token* scanner(char* source) {
    lexer = createLexer(source);

    Token* firstToken = NULL;

    do {
        Token* tempToken = scanToken();

        if(firstToken == NULL)
            firstToken = tempToken;
        else
            getLastToken(firstToken)->next = tempToken;

    } while(getLastToken(firstToken)->type != TOKEN_EOF);

    freeLexer();
    return firstToken;
}

Token* scanToken() {
    skipWhiteSpace();

    if(isAtEnd())
        return makeToken(TOKEN_EOF, "end", lexer->currentLine, lexer->currentColumn);


    //character
    char c = advance();

    switch(c) {
        case '+':
            if(isMatch('='))
                return makeToken(TOKEN_PLUS_EQUAL, "+=", lexer->currentLine, lexer->currentColumn);
            if(isMatch('+'))
                return makeToken(TOKEN_PLUS_PLUS, "++", lexer->currentLine, lexer->currentColumn);
            return makeToken(TOKEN_PLUS, "+", lexer->currentLine, lexer->currentColumn);
        case '-':
            if(isMatch('='))
                return makeToken(TOKEN_MINUS_EQUAL, "-=", lexer->currentLine, lexer->currentColumn);
            if(isMatch('-'))
                return makeToken(TOKEN_MINUS_MINUS, "--", lexer->currentLine, lexer->currentColumn);
            return makeToken(TOKEN_MINUS, "-", lexer->currentLine, lexer->currentColumn);
        case '*':
            if(isMatch('='))
                return makeToken(TOKEN_MULTIPLY_EQUAL, "*=", lexer->currentLine, lexer->currentColumn);
            if(isMatch('*')) {
                if(isMatch('='))
                    return makeToken(TOKEN_EQUAL_POWER, "**=", lexer->currentLine, lexer->currentColumn);
                return makeToken(TOKEN_POWER, "**", lexer->currentLine, lexer->currentColumn);
            }
            return makeToken(TOKEN_MULTPLY, "*", lexer->currentLine, lexer->currentColumn);
        case '/':
            if(isMatch('='))
                return makeToken(TOKEN_DIVIDE_EQUAL, "/=", lexer->currentLine, lexer->currentColumn);
            return makeToken(TOKEN_DIVIDE, "/", lexer->currentLine, lexer->currentColumn);
        case '%':
            if(isMatch('='))
                return makeToken(TOKEN_MODULUS_EQUAL, "%=", lexer->currentLine, lexer->currentColumn);
            return makeToken(TOKEN_MODULUS, "%", lexer->currentLine, lexer->currentColumn);
        case '(':
            return makeToken(TOKEN_BRACKET_ROUND_LEFT, "(", lexer->currentLine, lexer->currentColumn);
        case ')':
            return makeToken(TOKEN_BRACKET_ROUND_RIGHT, ")", lexer->currentLine, lexer->currentColumn);
        case '[':
            return makeToken(TOKEN_BRACKET_SQUARE_LEFT, "[", lexer->currentLine, lexer->currentColumn);
        case ']':
            return makeToken(TOKEN_BRACKET_SQUARE_RITGHT, "]", lexer->currentLine, lexer->currentColumn);
        case '<':
            if(isMatch('='))
                return makeToken(TOKEN_LESS_EQUAL, "<=", lexer->currentLine, lexer->currentColumn);
            return makeToken(TOKEN_LESS, "<", lexer->currentLine, lexer->currentColumn);
        case '>':
            if(isMatch('='))
                return makeToken(TOKEN_GREAT_EQUAL, ">=", lexer->currentLine, lexer->currentColumn);
            return makeToken(TOKEN_GREAT, ">", lexer->currentLine, lexer->currentColumn);
        case '.':
            return makeToken(TOKEN_DOT, ".", lexer->currentLine, lexer->currentColumn);
        case ',':
            return makeToken(TOKEN_COMMA, ",", lexer->currentLine, lexer->currentColumn);
        case ':':
            return makeToken(TOKEN_COLON, ":", lexer->currentLine, lexer->currentColumn);
        case '!':
            if(isMatch('='))
                return makeToken(TOKEN_BANG_EQUAL, "!=", lexer->currentLine, lexer->currentColumn);
            return makeToken(TOKEN_BANG, "!", lexer->currentLine, lexer->currentColumn);
        case '=':
            if(isMatch('=')) {
                if(isMatch('='))
                    return makeToken(TOKEN_EQUAL_EQUAL, "===", lexer->currentLine, lexer->currentColumn);
                return makeToken(TOKEN_EQUAL_EQUAL, "==", lexer->currentLine, lexer->currentColumn);
            }
            return makeToken(TOKEN_EQUAL, "=", lexer->currentLine, lexer->currentColumn);
        case '"':
            return stringLiteral();
        default:
            if(isAlpha(c))
                return identifierLiteral(c);
            if(isDigit(c))
                return numberLiteral(c);

            return makeToken(TOKEN_ERROR, "Unexpected Token", lexer->currentLine, lexer->currentColumn);
    }
}

Token* stringLiteral()
{
    char *str = (char *)malloc(1);
    str[0] = '\0';

    while(peek() != '"' && !isAtEnd())
    {
        size_t len = strlen(str);
        str = (char *)realloc(str, len + 2);
        str[len] = peek();
        str[len + 1] = '\0';
        advance();
    }

    //ERROR
    if (isAtEnd())
        return makeToken(TOKEN_ERROR, "Unterminated string.", lexer->currentLine, lexer->currentColumn);

    advance();
    return makeToken(TOKEN_STRING_LITERAL, str, lexer->currentLine, lexer->currentColumn);
}

Token* identifierLiteral(char c)
{
    char *lexeme = (char *)malloc(2);
    lexeme[0] = c;
    lexeme[1] = '\0';

    while(isAlpha(peek()) || isDigit(peek()))
    {
        size_t len = strlen(lexeme);
        lexeme = (char *)realloc(lexeme, len + 2);
        lexeme[len] = peek();
        lexeme[len + 1] = '\0';
        advance();
    }

    if(strcmp(lexeme, "if") == 0)
        return makeToken(TOKEN_IF, lexeme,  lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "else") == 0)
        return makeToken(TOKEN_ELSE, lexeme, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "for") == 0)
        return makeToken(TOKEN_FOR, lexeme, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "var") == 0)
        return makeToken(TOKEN_FOR, lexeme, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "func") == 0)
        return makeToken(TOKEN_FUNC, lexeme, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "true") == 0)
        return makeToken(TOKEN_BOOL_TRUE, lexeme, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "false") == 0)
        return makeToken(TOKEN_BOOL_FALSE, lexeme, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "i8") == 0)
        return makeToken(TOKEN_TYPE_I8, lexeme, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "i16") == 0)
        return makeToken(TOKEN_TYPE_I16, lexeme, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "i32") == 0)
        return makeToken(TOKEN_TYPE_I32, lexeme, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "i64") == 0)
        return makeToken(TOKEN_TYPE_I64, lexeme, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "i128") == 0)
        return makeToken(TOKEN_TYPE_I128, lexeme, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "f32") == 0)
        return makeToken(TOKEN_TYPE_F32, lexeme, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "f64") == 0)
        return makeToken(TOKEN_TYPE_F64, lexeme, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "bool") == 0)
        return makeToken(TOKEN_TYPE_BOOL, lexeme, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "string") == 0)
        return makeToken(TOKEN_STRING_LITERAL, lexeme, lexer->currentLine, lexer->currentColumn);



    return makeToken(TOKEN_IDENTIFIER, lexeme, lexer->currentLine, lexer->currentColumn);
}


Token* numberLiteral(char c)
{
    char *number = (char *)malloc(2);
    number[0] = c;
    number[1] = '\0';

    while(isDigit(peek()))
    {
        size_t len = strlen(number);
        number = (char *)realloc(number, len + 2);
        number[len] = peek();
        number[len + 1] = '\0';
        advance();
    }

    if(isMatch('.'))
    {
        size_t length = strlen(number);
        number = (char *)realloc(number, length + 2);
        number[length] = '.';
        number[length + 1] = '\0';

        while(isDigit(peek()) || isDigit(peek()))
        {
            size_t len = strlen(number);
            number = (char *)realloc(number, len + 2);
            number[len] = peek();
            number[len + 1] = '\0';
            advance();
        }
    }

    return makeToken(TOKEN_NUMBER_LITERAL, number, lexer->currentLine, lexer->currentColumn);
}

void skipWhiteSpace()
{
    while(1) {
        char c = peek();

        switch(c) {
            case ' ':
            case '\t':
            case '\r':
                advance();
            break;
            case '\n':
                lexer->currentLine++;
                lexer->currentColumn = 0;
                advance();
            break;

            // COMMENTS LINES
            case '/':
                if(nextPeek() == '/') {
                    while(peek() != '\n' && !isAtEnd())
                        advance();
                    skipWhiteSpace();
                }
                else if (nextPeek() == '*') {
                    while(!(peek() == '*' && nextPeek() == '/') && !isAtEnd()) {
                        advance();
                    }
                    lexer->currentPosition += 2;
                    skipWhiteSpace();
                }

            default:
                return;
        }
    }
}

bool isMatch(char c) {
    if(isAtEnd() || peek() != c)
        return 0;

    advance();
    return 1;
}

char peek() {
    return lexer->source[lexer->currentPosition];
}

char nextPeek() {
    return lexer->source[lexer->currentPosition+1];
}

char advance() {
    lexer->currentColumn++;
    return lexer->source[lexer->currentPosition++];
}

bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isAtEnd() {
    return lexer->currentPosition == strlen(lexer->source);
}

void freeLexer() {
    if(lexer != NULL)
        free(lexer);
}