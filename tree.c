#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"

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

#if 1
void tree_print(tree_t *tree, stack_bt *stack) {

    node_t *tmp = NULL;
    node_t *current = tree->root;

    while(1) {
        if(current) {
            stack_push(stack, current);
            current = current->left;
        }
        else{
            if(!stack_empty(stack)) {
                stack_pop(stack);
                current = stack_top(stack);
                printf("current: %d\n", current->value);
                current = current->right;
            }
            else{
                break;
            }
        }
    }
}
#endif

#if 0
void tree_delete(node_t *node) {

    if (node == NULL) {
        return;
    }

    printf("%d\n", node->value);
    tree_delete(node->left);
    tree_delete(node->right);
}
#endif
