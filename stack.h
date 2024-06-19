#ifndef STACK_H
#define STACK_H

typedef struct stack_t {
    void *data; // resize by cap*2*elem_size
    size_t elem_size;
    size_t cap;
    size_t len;
} stack_t;

stack_t stack_create(void);
stack_t stack_push(stack_t stack, void *elem);
stack_t stack_pop(stack_t stack, void *elem);
void stack_free(stack_t stack);
void stack_print(stack_t stack);

#endif // STACK_H