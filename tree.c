#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

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

void tree_print(tree_t *tree) {
    
}