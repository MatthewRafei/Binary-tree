#include <stdio.h>
#include <assert.h>
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

// This doesn't work because it doesn't go back up the tree
void tree_print2(tree_t *tree) {
    node_t **node = &tree->root;

    int count = 0;

    // How many times do we need to go left
    
    while(1) {
        if(&(*node)->value == NULL){
            break;
        }
        printf("%d\n", (*node)->value);
        //while()
        node = &(*node)->left;
        
    }


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

