#include <stdlib.h>
#include <stdio.h>

#define INT_TYPE 0
#define FLOAT_TYPE 1
#define DOUBLE_TYPE 2

struct Node
{
    union {
        int d;
        float f;
        double lf;
    } data;
    int type;
    struct Node *next;
};

void append_int(struct Node *node, int value)
{
    if (node->next == NULL)
    {
        struct Node *tail = (struct Node *)malloc(sizeof(struct Node));
        tail->data.d = value;
        tail->type = INT_TYPE;
        tail->next = NULL;
        node->next = tail;
        return;
    }
    append_int(node->next, value);    
}

void append_float(struct Node *node, float value)
{
    if (node->next == NULL)
    {
        struct Node *tail = (struct Node *)malloc(sizeof(struct Node));
        tail->data.f = value;
        tail->type = FLOAT_TYPE;
        tail->next = NULL;
        node->next = tail;
        return;
    }
    append_float(node->next, value);    
}

void append_double(struct Node *node, double value)
{
    if (node->next == NULL)
    {
        struct Node *tail = (struct Node *)malloc(sizeof(struct Node));
        tail->data.lf = value;
        tail->type = DOUBLE_TYPE;
        tail->next = NULL;
        node->next = tail;
        return;
    }
    append_double(node->next, value);    
}

void print_list(struct Node* node)
{
    if(node == NULL) 
    {
        printf("\n");
        return;
    }
    switch(node->type)
    {
        case INT_TYPE:
            printf("%d\t", node->data.d);
            break;
        case FLOAT_TYPE:
            printf("%f\t", node->data.f);
            break;
        case DOUBLE_TYPE:
            printf("%lf\t", node->data.lf);
            break;
        // default:
    }
    print_list(node->next);
}

void free_list(struct Node* node)
{
    if(node->next != NULL) free_list(node->next);
    free(node);
}


int main()
{
    printf("--------------------Question 3 - with unions--------------------\n");
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    /* TODO: make function to initialize */
    node->type = INT_TYPE;
    node->data.d = 0;
    node->next = NULL;

    append_float(node, 1.0);
    append_double(node, 2.2);
    append_float(node, 4.8);
    append_float(node, 6.4);
    append_int(node, 8);
    append_int(node, 1);
    append_int(node, 3);

    print_list(node);
    
    free_list(node);
    return 0;
}