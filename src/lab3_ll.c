#include <stdlib.h>
#include "lab3_ll.h"

void append(struct Node* head, int value)
{
    struct Node* node = head;
    while (node->next != NULL) node = node->next;
    struct Node* new = malloc(sizeof(struct Node));
    node->next = new;
    new->data = value;
    new->next = NULL;
}

void free_list(struct Node* node)
{
    struct Node* next;
    while(node != NULL)
    {
        next = node->next;
        free(node);
        node = next;
    }
}
