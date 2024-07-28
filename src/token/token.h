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
    TOKEN_LES,                          // <
    TOKEN_GREAT,                        // >
    TOKEN_DOT,                          // .
    TOKEN_COMMA,                        // ,
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
    TOKEN_BREAK,
    TOKEN_CONTINUE


} TokenType;

typedef struct _token {
    TokenType type;
    const char* value;
    unsigned int position;
    unsigned int line;
    unsigned int column;
    struct _token* next;
} Token;


/*
 * @function: makeToken
 * @description: check a char is a-z or A-Z or _
 * @arguments: char c is a character input
 * @return: bool, true or false
 */
Token* makeToken(TokenType type);

Token* getLastToken(Token* token);

#endif //TOKEN_H
