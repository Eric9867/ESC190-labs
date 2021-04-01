#include <stdlib.h>
#include <stdio.h>
#include "queue_ll.h"

void enqueue(queue_node_t* node, void* data)
{
	if(! node)
	{
		printf("ERROR-- enqueuing onto nothing");
		abort();
	}

	// queue_node_t* cur_node = queue;

	while(node->next)
	{
		node = node->next;
	}

	node->next = (queue_node_t*)malloc(sizeof(queue_node_t));
	node = node->next;
	node->next = NULL;
	node->data = data;
}

void* dequeue(queue_node_t** node)
{
	if(!*node)
	{
		return NULL;
	}
	
	queue_node_t* head = *node;
	void* data = head->data;
	*node = head->next;
	free(head);
	return data;
}