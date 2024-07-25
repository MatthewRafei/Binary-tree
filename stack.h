#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include "tree.h"

typedef struct stack_bt {
  struct node_t *head;
  size_t stride;
} stack_bt;

stack_bt stack_create();
void stack_push(stack_bt *stack, node_t *value);
void stack_pop(stack_bt *stack, node_t *value);
void *stack_top(stack_bt *stack);
int stack_empty(stack_bt *stack);

#endif // STACK_H
