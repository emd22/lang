#include <keywords/let.h>
#include <stdlib.h>

static variable_t *variables;
static unsigned    variable_index = 0;

void variables_alloc() {
    variables = malloc(sizeof(variable_t)*512);
}

void variables_add(char *label, char *value) {
    variables[variable_index  ].label = label;
    variables[variable_index++].value = value;
}

variable_t *variable_get(unsigned index) {
    if (index >= 0 && index <= variable_index) {
        return &variables[index];
    }
    return (void *)0;
}

void variables_free() {
    free(variables);
}