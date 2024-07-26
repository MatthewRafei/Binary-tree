#include "stack.h"
#include "tree.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

stack_bt stack_create() {
    stack_bt stack;
    stack.head = NULL;

    return stack;
}

static stack_node *stack_node_alloc(node_t *tree_node) {
    stack_node *node = (stack_node *)malloc(sizeof(stack_node));
    node->value = tree_node;

    return node;
}

int stack_empty(stack_bt *stack) {
    return !stack->head;
}

void stack_push(stack_bt *stack, struct node_t *node) {
    stack_node *tmp = stack->head;
    stack->head = stack_node_alloc(node);
    stack->head->next = tmp;
}

void stack_pop(stack_bt *stack) {
    if(stack_empty(stack)){
        printf("This stack is empty\n");
        exit(1);
    }

    stack_node *tmp = stack->head;
    stack->head = stack->head->next;
    stack->top = tmp->value;
}

node_t *stack_top(stack_bt *stack) {
    return stack->top;
}

void stack_delete(stack_bt *stack) {

    stack_node *tmp = NULL;

    while(stack->head) {
        tmp = stack->head;
        stack->head = stack->head->next;
        free(tmp);
    }

    free(stack->top);
}
