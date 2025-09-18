//Implementation of queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = 0;
struct node *rear = 0;

void enqueue(int x){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    if(rear == 0){
        front=rear=newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

void display(){
    struct node *temp = front;
    if(front == 0 && rear == 0){
        printf("Queue is empty!");
    }
    else{printf("The elements in the queue are:");
        while(temp != 0){
            
            printf("%d->",temp->data);
            temp = temp->next;
        }
    }
    printf("NULL\n");
}

void dequeue(){
    struct node *temp;
    temp = front;
    if(front == 0 && rear == 0){
        printf("Queue is empty!");
    }
    else{
        printf("The dequeued element is:%d\n",front->data);
        front = front->next;
        free(temp);
    }
}

void peek(){
    if(front == 0 && rear == 0){
        printf("Queue is empty!");
    }
    else{
        printf("The front element is:%d\n",front->data);
    }
}

void main(){
    enqueue(6);
    enqueue(7);
    enqueue(2);
    display();
    dequeue();
    peek();
    display();
}
