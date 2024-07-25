#include <bits/types/stack_t.h>
#include <stdlib.h>
#include "stack.h"
#include "tree.h"

stack_bt stack_create() {
    stack_bt stack;
    stack.head = NULL;
    stack.stride = 0;

    return stack;
}

int stack_empty(stack_bt *stack) {
    return (stack->head == NULL) ? 1 : 0;
}

void stack_push(stack_bt *stack, node_t *value) {

    //stack->head = value;
    for(int i = 0; i < stack->stride; i++) {
        //stack
    }


}

void stack_pop(stack_bt *stack, node_t *value) {
    if(stack_empty(stack) == 0){
        printf("This stack is empty");
        return;
    }
}

void stack_print(stack_t stack) {

}
