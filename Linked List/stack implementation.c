//Implementing stack using linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *top = 0;

void push(int x){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}

void display(){
    struct node *temp;
    temp = top;
    if(top == NULL){
printf("It is empty!");
    }
    else{
        printf("The elements are:");
        while(temp != NULL){
            printf("%d->",temp->data);
            temp = temp->link;
        }
    }
    printf("NULL\n");
}

void peek(){
    if(top == NULL){
        printf("Empty!");
    }
    else{
        printf("\nTop element is: %d",top->data);
    }
}

void pop(){
    struct node *temp;
    temp = top;
    if(top==NULL){
        printf("Empty!");
    }
    else{
        printf("\nThe popped element is: %d\n",top->data);
        top = top ->link;
        free(temp);
    }
}

void main(){
    push(2);
    push(5);
    push(7);
    display();
    peek();
    pop();
    display();
    peek();
}
