#ifndef TREE_H
#define TREE_H
#include "stack.h"

typedef struct node_t {
    int value;
    struct node_t *left;
    struct node_t *right;
} node_t;

typedef struct tree_t {
    node_t *root;
} tree_t;

tree_t tree_create(void);
node_t *node_alloc(int value);
void tree_insert(tree_t *tree, int value);
void tree_remove(tree_t *tree, int value); // remove `value` from the tree
void tree_free(tree_t *tree); // free all memory allocated from the nodes

void tree_print(tree_t *tree, stack_bt *stack);

void tree_delete(node_t *node);


#endif // TREE_H
