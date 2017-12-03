#ifndef LET_H
#define LET_H

typedef struct {
    char *label;
    char *value;
} variable_t;

void variables_alloc();
void variables_add(char *label, char *value);
variable_t *variable_get(unsigned index);
void variables_free();

#endif