#include <lexer.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static tokens_t tokens_info;

int is_space(char c) {
    if (c == '\t' || c == '\n' || c == ' ' || c == '\0') {
        return 1;
    }
    return 0;
}

void tokens_set(vector_t *tokens) {
    tokens_info.tokens = tokens;
    tokens_info.pos = 0;
}

char *tokens_peek() {
    return vector_get(tokens_info.tokens, tokens_info.pos+1);
}

char *tokens_read() {
    return vector_get(tokens_info.tokens, tokens_info.pos++);
}

char *tokens_peek_stat() {
    return vector_get(tokens_info.tokens, tokens_info.pos);
}

char *tokens_read_past() {
    return vector_get(tokens_info.tokens, tokens_info.pos--);
}

char *tokens_peek_past() {
    return vector_get(tokens_info.tokens, tokens_info.pos-1);
}

//knockoff strcmp
char *cmp_str(char *str, int start_i, char *need) {
    int index = 0;
    if (str[start_i] == need[index]) {
        while (str[start_i+index] == need[index]) {
            index++;
            if (need[index] == '\0')
                return need;
        }
        return NULL;
    }
    return NULL;
}

void lex(char *in, vector_t *out) {
    unsigned dat_i = 0;
    unsigned len = strlen(in);

    token_t *token = malloc(sizeof(token_t));
    token->token = malloc(256);

    int i;
    for (i = 0; i < len; i++) {
        if (is_space(in[i])) {
            token->type = 0;
            vector_add(out, token);
            token = malloc(sizeof(token_t));
            token->token = malloc(256);
            dat_i = 0;
        }
        else {
            if (cmp_str(in, i, "=") ||
                cmp_str(in, i, "+") {

            }
            token->token[dat_i++] = in[i];
        }
    }
}