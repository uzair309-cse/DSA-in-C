// Operations on circular singly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void createCircularList(struct Node **head);
void displayCircularList(struct Node *head);
void insertAtFront(struct Node **head);
void insertAtRear(struct Node **head);
void insertBeforeData(struct Node **head, int y);
void deleteAtFront(struct Node **head);
void deleteAtRear(struct Node **head);
void deleteData(struct Node **head, int x);

int main()
{
    struct Node *head = NULL;
    int choice, y, x;
    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Create Circular Linked List\n");
        printf("2. Display Circular Linked List\n");
        printf("3. Insert at Front\n");
        printf("4. Insert at Rear\n");
        printf("5. Insert Before Data Y\n");
        printf("6. Delete at Front\n");
        printf("7. Delete at Rear\n");
        printf("8. Delete Data X\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createCircularList(&head);
            break;
        case 2:
            displayCircularList(head);
            break;
        case 3:
            insertAtFront(&head);
            break;
        case 4:
            insertAtRear(&head);
            break;
        case 5:
            printf("Enter data Y: ");
            scanf("%d", &y);
            insertBeforeData(&head, y);
            break;
        case 6:
            deleteAtFront(&head);
            break;
        case 7:
            deleteAtRear(&head);
            break;
        case 8:
            printf("Enter data X: ");
            scanf("%d", &x);
            deleteData(&head, x);
            break;
        case 9:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void createCircularList(struct Node **head)
{
    int data, choice;
    struct Node *newNode, *last = NULL;
    *head = NULL;
    do
    {
        printf("Enter data: ");
        scanf("%d", &data);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        if (*head == NULL)
        {
            *head = newNode;
            newNode->next = *head;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            newNode->next = *head;
            last = newNode;
        }
        printf("Add another node? (1-Yes, 0-No): ");
        scanf("%d", &choice);
    } while (choice == 1);
}

void displayCircularList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Circular Linked List: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

void insertAtFront(struct Node **head)
{
    int data;
    printf("Enter data to insert at front: ");
    scanf("%d", &data);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct Node *last = *head;
    while (last->next != *head)
        last = last->next;
    newNode->next = *head;
    last->next = newNode;
    *head = newNode;
}

void insertAtRear(struct Node **head)
{
    int data;
    printf("Enter data to insert at rear: ");
    scanf("%d", &data);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct Node *last = *head;
    while (last->next != *head)
        last = last->next;
    last->next = newNode;
    newNode->next = *head;
}

void insertBeforeData(struct Node **head, int y)
{
    int data;
    printf("Enter data to insert before %d: ", y);
    scanf("%d", &data);

    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node *curr = *head, *prev = NULL;
    do
    {
        if (curr->data == y)
            break;
        prev = curr;
        curr = curr->next;
    } while (curr != *head);

    if (curr->data != y)
    {
        printf("Data %d not found in the list.\n", y);
        free(newNode);
        return;
    }

    if (curr == *head)
    {
        // Insert before head
        struct Node *last = *head;
        while (last->next != *head)
            last = last->next;
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
    }
    else
    {
        newNode->next = curr;
        prev->next = newNode;
    }
}

void deleteAtFront(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head;
    if (temp->next == temp)
    {
        free(temp);
        *head = NULL;
        printf("Front node deleted.\n");
        return;
    }
    struct Node *last = *head;
    while (last->next != *head)
        last = last->next;
    last->next = temp->next;
    *head = temp->next;
    free(temp);
    printf("Front node deleted.\n");
}

void deleteAtRear(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head;
    if (temp->next == temp)
    {
        free(temp);
        *head = NULL;
        printf("Last node deleted.\n");
        return;
    }
    struct Node *prev = NULL;
    while (temp->next != *head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = *head;
    free(temp);
    printf("Last node deleted.\n");
}

void deleteData(struct Node **head, int x)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *curr = *head, *prev = NULL;
    do
    {
        if (curr->data == x)
            break;
        prev = curr;
        curr = curr->next;
    } while (curr != *head);

    if (curr->data != x)
    {
        printf("Data %d not found in the list.\n", x);
        return;
    }

    if (curr == *head)
    {
        // Deleting head node
        if (curr->next == curr)
        {
            free(curr);
            *head = NULL;
            printf("Node with data %d deleted.\n", x);
            return;
        }
        struct Node *last = *head;
        while (last->next != *head)
            last = last->next;
        last->next = curr->next;
        *head = curr->next;
        free(curr);
        printf("Node with data %d deleted.\n", x);
    }
    else
    {
        prev->next = curr->next;
        free(curr);
        printf("Node with data %d deleted.\n", x);
    }
