#include <stdio.h>
#include <stdlib.h>
#include "tree.h"



int main(void)
{
    
    tree_t tree = tree_create();

    tree_insert(&tree, 100);
    tree_insert(&tree, 50);
    tree_insert(&tree, 150);
    tree_insert(&tree, 25);
    tree_insert(&tree, 75);
    tree_insert(&tree, 140);
    tree_insert(&tree, 170);
    tree_insert(&tree, 15);
    tree_insert(&tree, 30);
    tree_insert(&tree, 80);
    tree_insert(&tree, 180);
    tree_insert(&tree, 171);
    tree_insert(&tree, 172);
    tree_insert(&tree, 173);
    tree_insert(&tree, 174);
    tree_insert(&tree, 176);
    tree_insert(&tree, 175);
    tree_insert(&tree, 178);

    /*             100
                  /   \
                 /     \
                50      150
               / \     /  \
             25   75  140  170
            / \    \         \
          15  30    80       180
                             /
                           171
                             \
                             172
                               \ 
                               173
                                 \
                                 174
                                   \
                                   176
                                   /  \
                                 175   178


    */

    tree_print(&tree);

    printf("\n");

    tree_print2(&tree);

    return 0;
}


