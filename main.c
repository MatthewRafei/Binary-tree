#include "tree.h"
#include "stack.h"

int main(void) {

  tree_t tree = tree_create();

  #if 1
  int arr[] = {100,50,150,25,75,140,170,15,30,80,180,171,172,173,174,176,175,178};

  for (int i = 0; i < sizeof(arr)/sizeof(*arr); ++i) {
      tree_insert(&tree, arr[i]);
  }
  #endif

  //tree_insert(&tree, 0);

  stack_bt stack = stack_create();

  tree_print(&tree, &stack);

  stack_delete(&stack);
  //tree_delete(tree.root);



  //printf("Is the stack empty? : %d\n", stack_empty(&stack));

  //stack_push(&stack, tree.root);

  return 0;
}
