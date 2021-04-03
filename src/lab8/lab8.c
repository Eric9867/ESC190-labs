#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bag.h"

int cmp(bag_elem_t a, bag_elem_t b)
{
	return (int)a < (int)b;
}

void print_elem(bag_elem_t e)
{
	printf("%i", (int)e);
}

int main()
{
	printf("1\n");
	bag_t* tree = bag_create(cmp);
	bag_t* avl_tree = bag_create(cmp);
	for(int i = 0; i < 10; i++)
	{
		printf("1\n");

		bag_insert_norot(avl_tree, (bag_elem_t)(rand()));		
		bag_insert_norot(tree, (bag_elem_t)(rand()));
	 	printf("1\n");
	}

    printf("REC NON-AVL: %d\n",is_avl_subtree_rec_helper(tree->root));
    printf("REC AVL: %d\n",is_avl_subtree_rec(avl_tree->root));
    printf("NON-REC NON-AVL: %d\n",is_avl_tree(tree));
    printf("NON-REC AVL: %d\n",is_avl_tree(avl_tree));

	bag_print(tree, 3, print_elem);
   return 0;
}