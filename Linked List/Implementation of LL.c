// Implementation of LL

#include <stdio.h>
#include <stdlib.h>

// define our data type
struct node
{
    int data;
    struct node *next;
};

void lltraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element:%d \n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{

    struct node *head;
    struct node *second;
    struct node *third;

    // allocation in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 4;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 5;
    third->next = NULL;

    lltraversal(head);

    return 0;
}
