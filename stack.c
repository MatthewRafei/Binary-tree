#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack_t stack_create(void *elem) {
    stack_t stack;
    stack.data = malloc;
    stack.elem_size = 0;
    stack.cap = 0;
    stack.len = 0;
    return stack;
}

stack_t stack_push(stack_t stack, void *elem) {

}

stack_t stack_pop(stack_t stack) {

}

void stack_print(stack_t stack) {

}