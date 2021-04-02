#ifndef QUEUE_LL_H_
#define QUEUE_LL_H_

typedef struct queue_node
{
	queue_node_t* next;
	void* data;
} queue_node_t;


void enqueue(queue_node_t* node, void* data);
void* dequeue(queue_node_t** node);

#endif // QUEUE_LL_H_
