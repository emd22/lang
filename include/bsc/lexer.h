#ifndef LEXER_H
#define LEXER_H

#include <vector.h>

typedef struct {
    int type;
    char *token;
} token_t;

typedef struct {
    int pos;
    vector_t *tokens;
} tokens_t;

typedef struct {
    char *data;
    int size;
} between_t;

void tokens_set(vector_t *tokens);
char *tokens_peek();
char *tokens_read();
char *tokens_peek_stat();
char *tokens_read_past();
char *tokens_peek_past();
void lex(char *in, vector_t *out);

#endif