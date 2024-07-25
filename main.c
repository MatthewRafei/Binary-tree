#include "tree.h"
#include "stack.h"

int main(void) {


  tree_t tree = tree_create();

  int arr[] = {100,50,150,25,75,140,170,15,30,80,180,171,172,173,174,176,175,178};

  for (int i = 0; i < sizeof(arr)/sizeof(*arr); ++i) {
      tree_insert(&tree, arr[i]);
  }

  tree_print(&tree);

  stack_t stack = stack_create();

  stack_push(stack, tree.root);

  return 0;
}
