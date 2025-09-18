
// This program creates a linked list with three nodes, allowing the user to input data for each node.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node {
    int data;
    struct node *next;
};

// Function prototypes
void createLL(struct node **start);
void display(struct node *start);

int main() 
{
    struct node *head = NULL; 

    // Create three nodes in the linked list
    createLL(&head);
    createLL(&head);
    createLL(&head);

    // Display the linked list
    printf("Linked List: ");
    display(head);

    return 0;
}

// Function to create a new node and add it to the linked list
void createLL(struct node **start) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the value of Data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;  

    if (*start == NULL) {
        *start = newNode;  // If the list is empty, set newNode as the head
    } else {
        struct node *current = *start;

        // Traverse to the end of the list
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;  // Link the new node at the end
    }
}

// Function to display the linked list
void display(struct node *start) {
    struct node *current = start;

    // Traverse through the linked list and print each node's data
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");  // Indicate the end of the list
}
