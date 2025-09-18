
// To find the middle of a linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


struct node *create(struct node **head, int data) {
    struct node *new = (struct node *)malloc(sizeof(struct node));

    if (new == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    new->data = data;
    new->next = NULL;

    if (*head == NULL) {
        *head = new;  
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


void print(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to find the middle of the linked list
void findMiddle(struct node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *slow = head;
    struct node *fast = head;

    // Move `fast` two steps and `slow` one step at a time
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("The middle of the linked list is: %d\n", slow->data);
}

int main() {
    struct node *head = NULL;

    create(&head, 10);
    create(&head, 20);
    create(&head, 30);
    create(&head, 40);
    create(&head, 50);

    printf("The linked list is:\n");
    print(head);

   //  middle of the linked list
    findMiddle(head);

    return 0;
}
