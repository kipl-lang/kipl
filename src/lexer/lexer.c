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

Lexer* createLexer(char* source, char* fileName) {
    Lexer* lexer = (Lexer*)malloc(sizeof(Lexer));

    lexer->source = source;
    lexer->fileName = fileName;
    lexer->currentPosition = 0;
    lexer->currentLine = 1;
    lexer->currentColumn = 0;

    return lexer;
}

Token* scanner(char* source, char* fileName) {
    lexer = createLexer(source, fileName);

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
        return makeToken(TOKEN_EOF, "end",lexer->fileName, lexer->currentLine, lexer->currentColumn);


    //character
    char c = advance();

    switch(c) {
        case '+':
            if(isMatch('='))
                return makeToken(TOKEN_PLUS_EQUAL, "+=", lexer->fileName, lexer->currentLine, lexer->currentColumn);
            // if(isMatch('+'))
            //     return makeToken(TOKEN_PLUS_PLUS, "++", lexer->currentLine, lexer->currentColumn);
            return makeToken(TOKEN_PLUS, "+", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case '-':
            if(isMatch('='))
                return makeToken(TOKEN_MINUS_EQUAL, lexer->fileName, "-=", lexer->currentLine, lexer->currentColumn);
            // if(isMatch('-'))
            //     return makeToken(TOKEN_MINUS_MINUS, "--", lexer->currentLine, lexer->currentColumn);
            return makeToken(TOKEN_MINUS, "-", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case '*':
            if(isMatch('='))
                return makeToken(TOKEN_MULTIPLY_EQUAL, "*=", lexer->fileName, lexer->currentLine, lexer->currentColumn);
            if(isMatch('*')) {
                if(isMatch('='))
                    return makeToken(TOKEN_EQUAL_POWER, "**=", lexer->fileName, lexer->currentLine, lexer->currentColumn);
                return makeToken(TOKEN_POWER, "**", lexer->fileName, lexer->currentLine, lexer->currentColumn);
            }
            return makeToken(TOKEN_MULTPLY, "*", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case '/':
            if(isMatch('='))
                return makeToken(TOKEN_DIVIDE_EQUAL, "/=", lexer->fileName, lexer->currentLine, lexer->currentColumn);
            return makeToken(TOKEN_DIVIDE, "/", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case '%':
            if(isMatch('='))
                return makeToken(TOKEN_MODULUS_EQUAL, "%=", lexer->fileName, lexer->currentLine, lexer->currentColumn);
            return makeToken(TOKEN_MODULUS, "%", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case '(':
            return makeToken(TOKEN_BRACKET_ROUND_LEFT, "(", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case ')':
            return makeToken(TOKEN_BRACKET_ROUND_RIGHT, ")", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case '{':
            return makeToken(TOKEN_BRACKET_CURLY_LEFT, "{", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case '}':
            return makeToken(TOKEN_BRACKET_CURLY_RIGHT, "}", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case '[':
            return makeToken(TOKEN_BRACKET_SQUARE_LEFT, "[", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case ']':
            return makeToken(TOKEN_BRACKET_SQUARE_RITGHT, "]", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case '<':
            if(isMatch('='))
                return makeToken(TOKEN_LESS_EQUAL, "<=", lexer->fileName, lexer->currentLine, lexer->currentColumn);
            return makeToken(TOKEN_LESS, "<", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case '>':
            if(isMatch('='))
                return makeToken(TOKEN_GREAT_EQUAL, ">=", lexer->fileName, lexer->currentLine, lexer->currentColumn);
            return makeToken(TOKEN_GREAT, ">", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case '.':
            return makeToken(TOKEN_DOT, ".", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case ',':
            return makeToken(TOKEN_COMMA, ",", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case ':':
            return makeToken(TOKEN_COLON, ":", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case '!':
            if(isMatch('='))
                return makeToken(TOKEN_BANG_EQUAL, "!=", lexer->fileName, lexer->currentLine, lexer->currentColumn);
            return makeToken(TOKEN_BANG, "!", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case '=':
            if(isMatch('>'))
                return makeToken(TOKEN_ARROW, "=>", lexer->fileName, lexer->currentLine, lexer->currentColumn);
            if(isMatch('=')) {
                if(isMatch('='))
                    return makeToken(TOKEN_EQUAL_EQUAL, "===", lexer->fileName, lexer->currentLine, lexer->currentColumn);
                return makeToken(TOKEN_EQUAL_EQUAL, "==", lexer->fileName, lexer->currentLine, lexer->currentColumn);
            }
            return makeToken(TOKEN_EQUAL, "=", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case '&':
            if(isMatch('&'))
                return makeToken(TOKEN_AND, "&&", lexer->fileName, lexer->currentLine, lexer->currentColumn);
            return makeToken(TOKEN_ERROR, "Unexpected Token", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case '|':
            if(isMatch('|'))
                return makeToken(TOKEN_OR, "||", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        return makeToken(TOKEN_ERROR, "Unexpected Token", lexer->fileName, lexer->currentLine, lexer->currentColumn);
        case '"':
            return stringLiteral();
        default:
            if(isAlpha(c))
                return identifierLiteral(c);
            if(isDigit(c))
                return numberLiteral(c);

            return makeToken(TOKEN_ERROR, "Unexpected Token", lexer->fileName, lexer->currentLine, lexer->currentColumn);
    }
}

Token* stringLiteral()
{
    char *str = (char *)malloc(1);
    str[0] = '\0';

    while(peek() != '"' && !isAtEnd())
    {
        if (peek() == '\\')
        {
            advance();
            char escapeChar = advance();

            switch (escapeChar)
            {
                case 'n': escapeChar = '\n'; break;
                case 't': escapeChar = '\t'; break;
                case '\\': escapeChar = '\\'; break;
                case '"': escapeChar = '"'; break;
                default:
                    return makeToken(TOKEN_ERROR, "Invalid escape sequence", lexer->fileName, lexer->currentLine, lexer->currentColumn);
            }

            size_t len = strlen(str);
            str = (char *)realloc(str, len + 2);
            str[len] = escapeChar;
            str[len + 1] = '\0';
        }
        else
        {
            size_t len = strlen(str);
            str = (char *)realloc(str, len + 2);
            str[len] = peek();
            str[len + 1] = '\0';
            advance();
        }
    }

    //ERROR
    if (isAtEnd())
        return makeToken(TOKEN_ERROR, "Unterminated string.", lexer->fileName, lexer->currentLine, lexer->currentColumn);

    advance(); // Closing "
    return makeToken(TOKEN_STRING_LITERAL, str, lexer->fileName, lexer->currentLine, lexer->currentColumn);
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

    if(strcmp(lexeme, "import") == 0)
        return makeToken(TOKEN_IMPORT, lexeme, lexer->fileName,  lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "if") == 0)
        return makeToken(TOKEN_IF, lexeme, lexer->fileName,  lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "else") == 0)
        return makeToken(TOKEN_ELSE, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "for") == 0)
        return makeToken(TOKEN_FOR, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "continue") == 0)
        return makeToken(TOKEN_CONTINUE, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "break") == 0)
        return makeToken(TOKEN_BREAK, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "var") == 0)
        return makeToken(TOKEN_VAR, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "const") == 0)
        return makeToken(TOKEN_CONST, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "func") == 0)
        return makeToken(TOKEN_FUNC, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "switch") == 0)
        return makeToken(TOKEN_SWITCH, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "case") == 0)
        return makeToken(TOKEN_CASE, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "default") == 0)
        return makeToken(TOKEN_DEFAULT, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "out") == 0)
        return makeToken(TOKEN_OUT, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "true") == 0)
        return makeToken(TOKEN_BOOL_TRUE, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "false") == 0)
        return makeToken(TOKEN_BOOL_FALSE, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "i8") == 0)
        return makeToken(TOKEN_TYPE_I8, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "i16") == 0)
        return makeToken(TOKEN_TYPE_I16, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "i32") == 0)
        return makeToken(TOKEN_TYPE_I32, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "i64") == 0)
        return makeToken(TOKEN_TYPE_I64, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "i128") == 0)
        return makeToken(TOKEN_TYPE_I128, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "u8") == 0)
        return makeToken(TOKEN_TYPE_U8, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "u16") == 0)
        return makeToken(TOKEN_TYPE_U16, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "u32") == 0)
        return makeToken(TOKEN_TYPE_U32, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "u64") == 0)
        return makeToken(TOKEN_TYPE_U64, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "u128") == 0)
        return makeToken(TOKEN_TYPE_U128, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "f32") == 0)
        return makeToken(TOKEN_TYPE_F32, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "f64") == 0)
        return makeToken(TOKEN_TYPE_F64, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "bool") == 0)
        return makeToken(TOKEN_TYPE_BOOL, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "string") == 0)
        return makeToken(TOKEN_TYPE_STRING, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    if(strcmp(lexeme, "void") == 0)
        return makeToken(TOKEN_VOID, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
    return makeToken(TOKEN_IDENTIFIER, lexeme, lexer->fileName, lexer->currentLine, lexer->currentColumn);
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

    return makeToken(TOKEN_NUMBER_LITERAL, number, lexer->fileName, lexer->currentLine, lexer->currentColumn);
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