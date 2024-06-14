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


void tree_print2(tree_t *tree) {

    node_t **current_node = &tree->root;
    node_t **left_node = NULL;

    // this is assuming no negative numbers :/
    int last_printed = 0;
    int saved = 0;

    // Having trouble finding a exit condition for this algorithm but maybe....
    // maybe if saved the last printed number and do a equivlentcy comparison
    while(*current_node) {

        // Go right until NULL then print number
        if((*current_node)->right == NULL) {
            
            // if we've already printed it, dont print again
            if((*current_node)->value > last_printed) {
                printf("%d\n", (*current_node)->value);
            }

            // If node has left set current node and continue going right
            if((*current_node)->left) {
                current_node = &(*current_node)->left;
            }
            else {
                last_printed = (*current_node)->value;
            }
        }

        if((*current_node)->right->value == last_printed) {
            printf("%d\n", (*current_node)->value);
        }

        current_node = &(*current_node)->right;

        //printf("%d\n", last_printed);

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

