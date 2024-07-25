#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include "tree.h"

typedef struct stack_t {
    int *data; // resize by cap*2*elem_size
    size_t len;
    struct stack_t *next;
} stack_t;

stack_t stack_create();
stack_t stack_push(stack_t stack, node_t *elem);
stack_t stack_pop(stack_t stack, node_t *elem);
void stack_free(stack_t stack);
void stack_print(stack_t stack);

#endif // STACK_H
