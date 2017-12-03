#include <parser.h>
#include <lexer.h>
#include <vector.h>

#include <string.h>

int check_int(char *token) {
    int i;
    int len = strlen(token);
    for (i = 0; i < len; i++) 
        if (!(token[i] >= '0' && token[i] <= '9')) return 0;
    return 1;
}

int check_label(char *token) {
    int i;
    int len = strlen(token);
    int contain_num = 0;
    int contain_alpha = 0;
    for (i = 0; i < len; i++) {
        if (token[i] >= 'a' && token[i] <= 'z' ||
            token[i] >= 'A' && token[i] <= 'Z') {
            contain_alpha = 1;       
        }
        if (token[i] >= '0' && token[i] <= '9') {
            contain_num = 1;
        }
    }
    if (contain_num && contain_alpha) {
        return 1;
    }
    return 0;
}

void parse(vector_t *tokens) {
    int i;
    token_t *token;
    for (i = 0; i < tokens->used; i++) {
        token = vector_get(tokens, i);

        if (check_int(token->token)) {
            token->type = INT;
        }
        else if (check_label(token->token)) {
            token->type = LABEL;
        }
        else {
            token->type = ERROR;
        }
    }
}