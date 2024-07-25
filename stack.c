#include <stdlib.h>
#include "stack.h"
#include "tree.h"

stack_t stack_create() {
    stack_t stack;
    stack.data = NULL;
    stack.len = 0;
    stack.next = NULL;

    return stack;
}

int is_empty(stack_t stack) {
    return (stack.data == NULL) ? 1 : 0;
}

stack_t stack_push(stack_t stack, node_t *elem) {
    stack.data = &elem->value;


}

stack_t stack_pop(stack_t stack, node_t *elem) {
    //free from stack struct

}

void stack_print(stack_t stack) {

}
