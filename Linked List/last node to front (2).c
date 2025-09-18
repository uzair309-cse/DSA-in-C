// Move the last node to the front

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create a new node and append it to the list
struct node *create(struct node **head) {
    struct node *new = (struct node *)malloc(sizeof(struct node));

    if (new == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    printf("Enter the value of Data: ");
    scanf("%d", &new->data);
    new->next = NULL;

    if (*head == NULL) {
        *head = new;  // If the list is empty, set newNode as the head
    } else {
        struct node *current = *head;

        // Traverse to the end of the list
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;  // Link the new node at the end
    }

    return new;
}

// Function to print the linked list
void print(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to move the last node to the front
struct node *moveLastToFront(struct node *head) {
    // If the list is empty or has only one node, no changes are needed
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct node *secondLast = NULL;
    struct node *last = head;

    // Traverse to the last node
    while (last->next != NULL) {
        secondLast = last;
        last = last->next;
    }

    // Update the second last node to point to NULL
    secondLast->next = NULL;

    // Move the last node to the front
    last->next = head;
    head = last;

    return head;
}

int main() {
    struct node *head = NULL;

    // Create the linked list
    create(&head);
    create(&head);
    create(&head);

    printf("Before moving the last node to the front:\n");
    print(head);

    // Move the last node to the front
    head = moveLastToFront(head);

    printf("After moving the last node to the front:\n");
    print(head);

    return 0;
}
