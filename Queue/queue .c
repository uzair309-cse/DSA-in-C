#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;


void enqueueFront() {
    if (front == 0) {
        printf("\nQueue is full at the front!\n");
        return;
    }
    if (front == -1) { // Queue is empty
        front = 0;
        rear = 0;
    } else {
        front--;
    }
    printf("Enter value to enqueue at front: ");
    scanf("%d", &queue[front]);
}


void enqueueRear() {
    if (rear == MAX - 1) {
        printf("\nQueue is full at the rear!\n");
        return;
    }
    if (rear == -1) { // Queue is empty
        front = 0;
        rear = 0;
    } else {
        rear++;
    }
    printf("Enter value to enqueue at rear: ");
    scanf("%d", &queue[rear]);
}


void dequeueFront() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty! Cannot dequeue from front.\n");
        return;
    }
    printf("Dequeued value from front: %d\n", queue[front]);
    front++;
}


void dequeueRear() {
    if (rear == -1 || front > rear) {
        printf("\nQueue is empty! Cannot dequeue from rear.\n");
        return;
    }
    printf("Dequeued value from rear: %d\n", queue[rear]);
    rear--;
}


void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty!\n");
        return;
    }
    printf("\nQueue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void menu() {
    printf("\nDouble-Ended Queue (Deque) Operations:");
    printf("\n1. Enqueue at Front");
    printf("\n2. Enqueue at Rear");
    printf("\n3. Dequeue from Front");
    printf("\n4. Dequeue from Rear");
    printf("\n5. Display Queue");
    printf("\n6. Exit");
}

int main() {
    int choice;
    do {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueueFront(); break;
            case 2: enqueueRear(); break;
            case 3: dequeueFront(); break;
            case 4: dequeueRear(); break;
            case 5: display(); break;
            case 6: printf("\nExiting...\n"); break;
            default: printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
