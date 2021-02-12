#include "lab3_ll.h" // now for lab4 as well
#include <stdlib.h>
#include <stdio.h>

int main()
{
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    head->next = NULL;
    head->data = 0;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);
    append(head, 6);
    append(head, 7);

    printf("insert test\n");
    print_list(head);
    insert(head, 0, 5);
    print_list(head);
    insert(head, 5, 100);
    print_list(head);
    insert(head, 10, 120);
    insert(head, -1, 1000);
    

    print_list(head);
    delete_node(head, 3);
    print_list(head);
    delete_node(head, 21);
    print_list(head);
    delete_node(head, 3);
    print_list(head);
    delete_node(head, 1);
    print_list(head);
    delete_node(head, 0);
    print_list(head);
    delete_node(head, 1);
    print_list(head);

    printf("SUCCESS!");
    free_list(head);
}