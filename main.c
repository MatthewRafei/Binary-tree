#include <stdio.h>
#include <stdlib.h>
#include "tree.h"



int main(void)
{
    
    tree_t tree = tree_create();

    tree_insert(&tree, 9);
    tree_insert(&tree, 3);
    tree_insert(&tree, 4);
    tree_insert(&tree, 1);
    tree_insert(&tree, 11);
    tree_insert(&tree, 10);

    /*              9
                  /   \
                 /     \
                3       11
               / \     /  \
              1   4   10   NULL
             / \ / \ /  \
          NULL NULL NULL NULL
    */

    tree_print(&tree);

    printf("\n");

    tree_print2(&tree);

    return 0;
}


