#include <stdlib.h>
#include <stdio.h>
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
 
void insert(struct Node *node, int index, int data)
{
    int count = 0;
    while(count < index-1)
    {
        node = node->next;
        count++;
    }
    struct Node *insert = (struct Node *)malloc(sizeof(struct Node));
    if(index == 0)
    {
        int shift_data = node->data;    // copy original node_0 data
        node->data = data;              // reassign data to the new data
        struct Node *next = node->next; // copy next pointer
        node->next = insert;            // inserting node to next index
        insert->data = shift_data;    // shifting original node_0 data to next node data
        insert->next = next;            // re-link the list
    }
    else if(index == -1)
    {
        append(node, data);
    }

    else
    {
        struct Node *prev = node;
        struct Node *next = node->next;
        prev->next = insert;
        insert->data = data;
        insert->next = next;        
    }
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


/**
 * does nothing if first node is NULL
 * 
 * 
 */
void delete_node(struct Node* node, int value)
{
    if(node == NULL)
        return;

    struct Node* prev_node = NULL;
     
    while(node != NULL)
    {
        /**
         * CASE 1-- head node contains value, next null
         * CASE 2-- head node contains value, next non-null
         * CASE 3-- tail node contains value
         * CASE 4-- default: non-edge node, next non-null
         **/

        if(node->data == value)
        {
            // CASE 1
            if(node->next == NULL && prev_node == NULL)
            {
                // ????????????????????
                free(node);
            } else if (prev_node == NULL)
            // CASE 2
            {
                struct Node* address_next = node->next;
                *node = *address_next;
                free(address_next);
                return;
            } else if (node->next == NULL)
            // CASE 3
            {
                prev_node->next = NULL;
                free(node);
                return;
            } else if (node->next != NULL && prev_node != NULL)
            // CASE 4--all cases should now be resolved
            {
                struct Node* address_next = node->next;
                prev_node->next = address_next;
                free(node);
                return;
            } else {
                printf("ERROR: Unresolved cases for node removal");
                abort();
            }
        }
        prev_node = node;
        node = node->next;
    }
}
    
void print_list(const struct Node* node)
{
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


