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
	for(int i = 0; i < 10; i++)
	{
		printf("1\n");
		
		bag_insert_norot(tree, (bag_elem_t)(rand()));
	 	printf("1\n");
	}

	bag_print(tree, 3, print_elem);
   return 0;
}