#if 0
1. For a linked list struct defined as below, write a function that prints out all 
   the data in the linked list. Do not use recursion.

struct node{
    int data; 
    struct node *next; 
};

2. Same as (1), but now use recursion.

3. Implement a linked list (with print and append) that can store objects of
   type int, float, and double. Use the following struct:

struct node
{
    (void *)p_data; //a pointer to data (allocated with malloc)
    int type; // 0 if int, 1 if float, 2 if double
    struct node *next;
}

You may like to write the functinos append_int, append_float, and append_double separately
#endif

#include <stdio.h>
#include <stdlib.h>

struct NodeA
{
    int data; /* in Python: void* data, also need data type */
    struct NodeA* next; /* NULL if current node is last node */
};

void append(struct NodeA* head, int value)
{
    struct NodeA* node = head;
    while (node->next != NULL) node = node->next;
    struct NodeA* new = (struct NodeA*) malloc(sizeof(struct NodeA));
    node->next = new;
    new->data = value;
    new->next = NULL;
}

void free_list(struct NodeA* node)
{
    if(node->next != NULL) free_list(node->next);
    free(node);
}

/*** Part 1 ***/
void print_list(struct NodeA* head)
{
    struct NodeA *cur = head;
    while(cur != NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

/*** Part 2 ***/
void print_list_recursive(struct NodeA* node)
{
    if(node == NULL) 
    {
        printf("\n");
        return;
    }
    printf("%d\t", node->data);
    print_list_recursive(node->next);
}

/*** Part 3 ***/
struct NodeB
{
    void *p_data; //a pointer to data (allocated with malloc)
    int type; // 0 if int, 1 if float, 2 if double
    struct NodeB *next;
};

void append_int(struct NodeB *node, int value)
{
    if (node->next == NULL)
    {
        struct NodeB *tail = (struct NodeB *)malloc(sizeof(struct NodeB));
        *((int*)tail->p_data) = value;
        tail->type = 0;
        node->next = tail;
        return;
    }
    
    append_int(node->next, value);    
}

void append_float(struct NodeB *node, float value)
{
    if (node->next == NULL)
    {
        struct NodeB *tail = (struct NodeB *)malloc(sizeof(struct NodeB));
        *((float*)tail->p_data) = value;
        tail->type = 1;
        node->next = tail;
        return;
    }
    
    append_float(node->next, value);    
}

void append_double(struct NodeB *node, double value)
{
    if (node->next == NULL)
    {
        struct NodeB *tail = (struct NodeB *)malloc(sizeof(struct NodeB));
        *((double*)tail->p_data) = value;
        tail->type = 2;
        node->next = tail;
        return;
    }
    
    append_double(node->next, value);    
}


  
void print_list_B(struct NodeB* node)
{
    if(node == NULL) 
    {
        printf("\n");
        return;
    }
    switch(node->type)
    {
        case 0:
            printf("%d\t", *((int*)node->p_data));
            break;
        case 1:
            printf("%f\t", *((float*)node->p_data));
            break;
        case 2:
            printf("%lf\t", *((double*)node->p_data));
            break;
        // default:
    }
    print_list_B(node->next);
}




int main()
{
    printf("--------------------Part 1--------------------");
    struct NodeA* node_0 = (struct NodeA*) malloc(sizeof(struct NodeA));
    node_0->data = 3;
    append(node_0, 7);
    append(node_0, 2);
    append(node_0, 9);
    append(node_0, 12);
    append(node_0, 1);
    
    print_list(node_0);
    print_list_recursive(node_0);


    printf("--------------------Part 2--------------------");
    

    
    free_list(node_0);
    return 0;
}