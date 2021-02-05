#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "lab3_ll.h"

/* Part 1 */
char* my_strcat(char* dest, char* src)
{
	// undefined behaviour if dest array is not large enough for both strings
	int i = 0;
	while (dest[i] != '\0') i++;
	int j = 0;
	for (; src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';

	return dest;
}

/* Part 2 */
int my_strcmp_rec(char* str1, char* str2)
{
	if (!*str1 || !*str2)
	{
		if (!*str1 && !*str2) return 0;
		else return (int)(*str1 - *str2);
	} 
	else if ( !(*str1 - *str2) )
	{
		return my_strcmp_rec(str1 + 1, str2 + 1);
	}
	else
	{
		return (int)(*str1 - *str2);
	}
}

/* Part 3 */

int digits_to_int(struct Node* node)
{
	int result = 0;
	while (node != NULL)
	{
		result *= 10;
		result += node->data;
		node = node->next;
	}
	return result;
}

int my_atoi(char* str)
{
	struct Node *node_0 = (struct Node *)malloc(sizeof(struct Node));
	node_0->data = 0;
	node_0->next = NULL;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (isdigit(str[i]))
		{
			append(node_0, str[i]-'0');
		}
	}

	return digits_to_int(node_0);
}

/* Part 4 */

/**
 * Note that this sequence must behave like a function
 * a given value in the sequence can only map to one value
 */
int floyd(struct Node* head)
{
	if(head == NULL || head->next == NULL)
		return 0;
	struct Node* tortoise = head;
	struct Node* hare = head->next->next;

	while (tortoise != hare)
	{
		if ( hare == NULL || hare->next == NULL ) return 0;
		tortoise = tortoise->next;
		hare = hare->next->next;
	}
	return 1;
}

int main(void)
{
	printf("-----------------Part 1-----------------\n");
	char* str_a = "First";
	char* str_b = "Second";
	char* str_c = (char*) malloc(64); // sizeof(char) is guaranteed to be 1 by the C standard
	if (str_c == NULL)
	{
		printf("Error: Unable to allocate memory. aborting...\n");
		abort();
	}
	str_c[0] = '\0';
	my_strcat(str_c, str_a);
	my_strcat(str_c, str_b);
	printf("%s\n",str_c);
	free(str_c);

	printf("-----------------Part 2-----------------\n");
	str_a = "Dairy Queen";
	str_b = "Dairy Queen";
	printf("String comparison [%s] vs. [%s]:  %d\n", str_a, str_b, my_strcmp_rec(str_a, str_b));

	printf("-----------------Part 3-----------------\n");
	str_a = "test 1 test 2 test 3 test 756";
	str_b = "the quick 123 brown 65 fox jumped over 0 the 54lazy 1 dog";
	printf("%d\n", my_atoi(str_a));
	printf("%d\n", my_atoi(str_b));

	printf("-----------------Part 4-----------------\n");
	struct Node* node0 = (struct Node*) malloc(sizeof(struct Node));
	node0->data = 0;
	node0->next = NULL;

	append(node0, 3);
	append(node0, 5);
	append(node0, 1);
	append(node0, 2);
	// append(node0, 1);
	
	/* Set the next pointer from the 2 node to the pointer to the 3 node */
	//node0->next->next->next->next = node0->next;

	printf("%d test\n", floyd(node0));

	free_list(node0);
	return 0;
}