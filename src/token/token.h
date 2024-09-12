/**
 The Kipl Programming Language

 File: token/token.h

 ||  //  ||  ||===\\  ||
 ||//    ||  ||   ||  ||
 ||||    ||  ||===//  ||
 || \\   ||  ||       ||
 ||  \\  ||  ||       ||=====


**/

#ifndef TOKEN_H
#define TOKEN_H



typedef enum _token_type {
    TOKEN_EOF,
    TOKEN_ERROR,

    TOKEN_STRING_LITERAL,
    TOKEN_NUMBER_LITERAL,

    TOKEN_IDENTIFIER,

    TOKEN_TYPE_I8,
    TOKEN_TYPE_I16,
    TOKEN_TYPE_I32,
    TOKEN_TYPE_I64,
    TOKEN_TYPE_I128,

    TOKEN_TYPE_U8,
    TOKEN_TYPE_U16,
    TOKEN_TYPE_U32,
    TOKEN_TYPE_U64,
    TOKEN_TYPE_U128,

    TOKEN_TYPE_F32,
    TOKEN_TYPE_F64,

    TOKEN_TYPE_BOOL,
    TOKEN_TYPE_STRING,

    TOKEN_BOOL_TRUE,
    TOKEN_BOOL_FALSE,

    TOKEN_VOID,

    // one char
    TOKEN_PLUS,                         // +
    TOKEN_MINUS,                        // -
    TOKEN_MULTPLY,                      // *
    TOKEN_DIVIDE,                       // /
    TOKEN_MODULUS,                      // %
    TOKEN_EQUAL,                        // =
    TOKEN_BRACKET_ROUND_LEFT,           // (
    TOKEN_BRACKET_ROUND_RIGHT,          // )
    TOKEN_BRACKET_SQUARE_LEFT,          // [
    TOKEN_BRACKET_SQUARE_RITGHT,        // ]
    TOKEN_BRACKET_CURLY_LEFT,           // {
    TOKEN_BRACKET_CURLY_RIGHT,          // }
    TOKEN_LESS,                         // <
    TOKEN_GREAT,                        // >
    TOKEN_DOT,                          // .
    TOKEN_COMMA,                        // ,
    TOKEN_COLON,                        // :
    TOKEN_BANG,                         // !

    // two char
    TOKEN_EQUAL_EQUAL,                  // ==
    TOKEN_LESS_EQUAL,                   // <=
    TOKEN_GREAT_EQUAL,                  // >=
    TOKEN_BANG_EQUAL,                   // !=
    TOKEN_PLUS_EQUAL,                   // +=
    TOKEN_MINUS_EQUAL,                  // -=
    TOKEN_MULTIPLY_EQUAL,               // *=
    TOKEN_DIVIDE_EQUAL,                 // /=
    TOKEN_MODULUS_EQUAL,                // %=
    TOKEN_PLUS_PLUS,                    // ++
    TOKEN_MINUS_MINUS,                  // --
    TOKEN_POWER,                        // **
    TOKEN_COLONCOLON,                   // ::
    TOKEN_AND,                          // &&
    TOKEN_OR,                           // ||

    // three char
    TOKEN_EQUAL_EQUAL_EQUAL,            // **
    TOKEN_EQUAL_POWER,                  // **=

    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_FOR,
    TOKEN_FUNC,
    TOKEN_RETURN,
    TOKEN_VAR,
    TOKEN_CONST,
    TOKEN_IMPORT,
    TOKEN_PACKAGE,
    TOKEN_SWITCH,
    TOKEN_CASE,
    TOKEN_DEFAULT,
    TOKEN_BREAK,
    TOKEN_CONTINUE,
    TOKEN_OUT
} TokenType;

typedef struct _token {
    TokenType type;
    char* value;
    char* fileName;
    unsigned int line;
    unsigned int column;
    struct _token* next;
} Token;


/*
 * @function: makeToken
 * @description: create a token and return the token
 * @arguments: TokenType type, char* value, char* fileName, unsigned int line, unsigned int column
 * @return: Token*
 */
Token* makeToken(TokenType type, char* value, char* fileName, unsigned int line, unsigned int column);

/*
 * @function: getLastToken
 * @description: get last created token in loop. This is a recursive func.
 * @arguments: Token* token
 * @return: Token*
 */
Token* getLastToken(Token* token);

/*
 * @function: getLastTokenWithOutEOF
 * @description: get last created token in loop without EOF_TOKEN. This is a recursive func.
 * @arguments: Token* token
 * @return: Token*
 */
Token* getLastTokenWithOutEOF(Token* token);

/*
 * @function: freeTokens
 * @description: free allocated memories
 * @arguments: Token* token
 * @return: void
 */
void freeTokens(Token* token);

#endif //TOKEN_H
