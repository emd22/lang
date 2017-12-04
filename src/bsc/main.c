#include <keywords/let.h>
#include <parser.h>
#include <vector.h>
#include <lexer.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char in[255];
    vector_t out;

    strcpy(in, "let x1=4\n");

    vector_init(&out);
    tokens_set(&out);

    lex(in, &out);

    parse(&out);
    int i;
    token_t *tok;

    for (i = 0; i < out.used; i++) {
        tok = (token_t *)vector_get(&out, i);
        printf("token: '%s' : %d\n", tok->token, tok->type);
        //free(tok);
    }

    vector_free(&out);

    return 0;
}