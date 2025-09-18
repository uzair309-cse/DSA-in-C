//Move the last node to the front

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// function to create a new node
struct node * createnode(int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node ->data = data;
    new_node->next = NULL;

    return new_node;
}

//function to print the linked list

void printlist(struct node *head){
    struct node *temp = head;
    while(temp!= NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//move last node to front
struct node * mlntf(struct node * head){

    //if list is empty or has one node
    if(head == NULL || head->next == NULL){
        return head;
    }

    struct node * s2 = NULL;
    struct node * s1 = head;

//traverse
    while(s1->next != NULL){
        s2 = s1;
        s1 = s1->next;
    }

    //s2 becomes now the end
    s2->next = NULL;

    //s1 points to current head
    s1->next = head;
    head = s1;

    return head;
}

int main(){

    //e.g let the given linked list be : 3->7->4->Null
    //Now it will be as : 4->3->7->Null

    struct node *head = createnode(3);
    head->next = createnode(7);
    head->next->next = createnode(4);

    printf("Before:\n");
    printlist(head);

    head = mlntf(head);

    printf("After:\n");
    printlist(head);

    return 0;
}



