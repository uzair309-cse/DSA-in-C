// address of last node

#include <stdio.h>
#include <stdlib.h>

// define our data type
struct node
{
    int data;
    struct node *next;
};

void sna(struct node *ptr)
{
    if (ptr == NULL)
    {
        printf("List is Empty!");
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
    }
    printf("Address of last node:%p \n", ptr);
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

    sna(head);

    return 0;
}
