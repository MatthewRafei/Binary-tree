/*
// O(log n)
13
        9
       / \
      2   12
    /  \    13
   1    6
         \
          7

              V
[img1, img2, img3]

// O(n)
lst = [9 2 6 7 1]
for all i in lst:
  if lst[i] == 7: return i;


    {3,2,7,15,18,19,1,9,13,17}
    sort = O(n log n)

                  v
    {1,2,3,7,9,13,15,17,18,19}

    O(log n)

    O(n log^2n)

    depth first search
    breadth first search
    dijsktras algorithm
    A*
    Prim's minimum spanning tree

        N   N
       / \ /
      N   N
     / \ / \
    N  N N  N
*/

#ifndef TREE_H
#define TREE_H

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
void tree_print(tree_t *tree);
void tree_print2(tree_t *tree);
void tree_insert2(tree_t *tree, int value);
void tree_remove(tree_t *tree, int value); // remove `value` from the tree
void tree_free(tree_t *tree); // free all memory allocated from the nodes

#endif // TREE_H