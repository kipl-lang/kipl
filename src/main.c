#include <stdio.h>
#include "lexer/lexer.h"

int main(void) {
    char* string = "var number: \n i32 = 5";
    Token* token =  scanner(string);

    while(token->type != TOKEN_EOF) {
        printf(token->value);
        printf("%d ", token->line);
        printf("%d\n", token->column);
        token = token->next;
    }
}
