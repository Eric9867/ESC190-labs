#ifndef LAB3_LL_H_
#define LAB3_LL_H_

struct Node
{
    int data;
    struct Node* next; /* NULL if current node is last node */
};
void append(struct Node* head, int value);
void free_list(struct Node* node);

#endif
