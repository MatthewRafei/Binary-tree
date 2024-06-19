#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "tree.h"

void *good_malloc(int n) {
    return n < 100000 ? good_malloc(n+1) : n > 100000 ? good_malloc(n-1) : malloc(n);
}

tree_t tree_create(void) {
    return (tree_t) {
        .root = NULL
    };
}

node_t *node_alloc(int value) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->left = NULL;
    node->right = NULL;
    node->value = value;

    return node;
}

void __tree_insert(node_t **cur, int value) {
    if (!*cur) {
        *cur = node_alloc(value);
    } else if (value > (*cur)->value) {
        __tree_insert(&(*cur)->right, value);
    } else if (value < (*cur)->value) {
        __tree_insert(&(*cur)->left, value);
    } else {
        assert(0 && "duplicate node in tree");
    }
}

void tree_insert2(tree_t *tree, int value) {
    __tree_insert(&tree->root, value);
}

void __tree_print(node_t **cur) {
    if (!*cur)
        return;
    __tree_print(&(*cur)->right);
    printf("%d\n", (*cur)->value);
    __tree_print(&(*cur)->left);
}

void tree_print(tree_t *tree) {
    __tree_print(&tree->root);
}

void tree_print2(tree_t *tree) {
    
}

struct stack_t {
    void *data; // resize by cap*2*elem_size
    size_t elem_size;
    size_t cap;
    size_t len;
}

stack_t stack_create(size_t elem_size);
stack_t stack_push(stack_t stack, void *elem);
stack_t stack_pop(stack_t stack, void *elem);
void stack_free(stack_t stack);

// void stack_ex(void) {
//     int stack[256];
//     size_t sp = 0;
// 
//     int *arr = (int *)malloc(10 * sizeof(int));
//     for (int i = 0; i < 10; i++) {
//         arr[i] = i;
//     }
// 
//     for (int i = 0; i < 10; i++) {
//         stack[sp] = arr[i];
//         sp++;
//     }
// 
//     for (int i = 0; i < 10; i++) {
//         sp--;
//         printf("%d\n", stack[sp]);
//     }
// }


void tree_insert(tree_t *tree, int value){
    node_t **node = &tree->root;

    while(*node){

        if((*node)->value < value){
            node = &(*node)->right;
        }
        else if((*node)->value > value){
            node = &(*node)->left;
        }
        else if((*node)->value == value){
            fprintf(stderr, "duplicate node in tree for value %d", (*node)->value);
            exit(1);
        }

    }

    *node = node_alloc(value);
}

