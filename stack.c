#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack_t stack_create(void) {
    stack_t stack;
    stack.data = NULL;
    stack.elem_size = 0;
    stack.cap = 0;
    stack.len = 0;
    return stack;
}

stack_t stack_push(stack_t stack, void *elem) {
    stack.data = &elem;
    stack.elem_size++;

    // If push was not possible because cap is reached, allocate size * 2 and then recall function with value?
}