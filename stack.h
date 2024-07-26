#ifndef STACK_H
#define STACK_H
#include <stdio.h>

/*
                                (Head)
NULL <- node3 <- node2 <- node1 <- node0
*/

typedef struct stack_node {
    struct node_t *value;
    struct stack_node *next;
} stack_node;

typedef struct stack_bt {
  stack_node *head;
  struct node_t *top;
} stack_bt;

stack_bt stack_create();
void stack_push(stack_bt *stack, struct node_t *node);
void stack_pop(stack_bt *stack);
struct node_t *stack_top(stack_bt *stack);
int stack_empty(stack_bt *stack);
void stack_delete(stack_bt *stack);

#endif // STACK_H
