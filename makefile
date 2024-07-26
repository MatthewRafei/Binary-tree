bst: main.c stack.c tree.c
	gcc -ggdb -o bst main.c stack.c tree.c

clean:
	rm bst
