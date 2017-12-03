#ifndef PARSER_H
#define PARSER_H

#include <vector.h>

enum TOKEN_TYPES {
    ERROR,
    INT,
    STRING,
    LABEL,
};

void parse(vector_t *tokens);

#endif