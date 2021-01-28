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

#define INT_TYPE 0
#define FLOAT_TYPE 1
#define DOUBLE_TYPE 2

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
    if(new == NULL) abort();
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
        struct NodeB *tail = (struct NodeB *)malloc(sizeof(struct NodeB) + sizeof(int));
        if(tail == NULL) abort();
        tail->p_data = tail + 1;
        *((int*)tail->p_data) = value;
        
        tail->type = INT_TYPE;
        tail->next = NULL;
        node->next = tail;
        return;
    }
    append_int(node->next, value);    
}

void append_float(struct NodeB *node, float value)
{
    if (node->next == NULL)
    {
        struct NodeB *tail = (struct NodeB *)malloc(sizeof(struct NodeB) + sizeof(float));
        if(tail == NULL) abort();
        tail->p_data = tail + 1;
        *((float*)tail->p_data) = value;
        tail->type = FLOAT_TYPE;
        tail->next = NULL;
        node->next = tail;
        return;
    }
    append_float(node->next, value);
}

void append_double(struct NodeB *node, double value)
{
    if (node->next == NULL)
    {
        struct NodeB *tail = (struct NodeB *)malloc(sizeof(struct NodeB) + sizeof(double));
        if(tail == NULL) abort();
        tail->p_data = tail + 1;
        *((double*)tail->p_data) = value;
        tail->type = DOUBLE_TYPE;
        tail->next = NULL;
        node->next = tail;
        return;
    }
    append_double(node->next, value);    
}

void print_list_b(struct NodeB* node)
{
    if(node == NULL) 
    {
        printf("\n");
        return;
    }
    switch(node->type)
    {
        case INT_TYPE:
            printf("%d\t", *((int*)node->p_data));
            break;
        case FLOAT_TYPE:
            printf("%f\t", *((float*)node->p_data));
            break;
        case DOUBLE_TYPE:
            printf("%lf\t", *((double*)node->p_data));
            break;
        // default:
    }
    print_list_b(node->next);
}

void free_list_b(struct NodeB* node)
{
    if(node->next != NULL) free_list_b(node->next);
    free(node);
}



int main()
{
    printf("--------------------Part 1--------------------\n");
    struct NodeA* node_0 = (struct NodeA*) malloc(sizeof(struct NodeA));
    if(node_0 == NULL) abort();
    node_0->data = 3;
    node_0->next = NULL;
    append(node_0, 7);
    append(node_0, 2);
    append(node_0, 9);
    append(node_0, 12);
    append(node_0, 1);
    
    print_list(node_0);
    print_list_recursive(node_0);


    printf("--------------------Part 2--------------------\n");
    struct NodeB* node_1 = (struct NodeB*)malloc(sizeof(struct NodeB));
    if(node_1 == NULL) abort();

    /* TODO: make function to initialize */
    node_1->type = INT_TYPE;
    int* node_value_address = malloc(sizeof(int)); /*freed in free_list_b*/
    if(node_value_address == NULL) abort();
    *node_value_address = 0;
    node_1->p_data = node_value_address;
    node_1->next = NULL;

    append_float(node_1, 1.0f);
    append_double(node_1, 2.2);
    append_float(node_1, 4.8f);
    append_float(node_1, 6.4f);
    append_int(node_1, 8);
    append_int(node_1, 1);
    append_int(node_1, 3);

    print_list_b(node_1);
    
    free_list(node_0);
    free_list_b(node_1);
    return 0;
}