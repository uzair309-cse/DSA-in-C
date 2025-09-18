#include <stdio.h> 
#define MAX 5 // Maximum size of the stack 

int stack[MAX], top = -1; 

// Function to push
void push() { 
    int x; 
    if (top == MAX - 1) { 
        printf("\nStack Overflow!\n"); 
    } else { 
        printf("Enter the value to push: "); 
        scanf("%d", &x); 
        top++; 
        stack[top] = x; 
        printf("%d pushed into the stack.\n", x);
    }
} 

// Function to pop 
void pop() { 
    if (top == -1) { 
        printf("\nStack Underflow!\n"); 
    } else { 
        int y = stack[top]; 
        top--; 
        printf("%d popped from the stack.\n", y); 
    } 
} 

// Function to display 
void display() { 
    if (top == -1) { 
        printf("\nStack is empty!\n"); 
    } else { 
        printf("\nStack elements: "); 
        for (int i = top; i >= 0; i--) { 
            printf("%d ", stack[i]); 
        } 
        printf("\n"); 
    } 
} 

// Function to peek 
void peek() { 
    if (top == -1) { 
        printf("\nStack is empty!\n"); 
    } else { 
        printf("\nTop element: %d\n", stack[top]); 
    } 
} 

int main() { 
    int choice; 
    do { 
        printf("\nStack Operations:\n"); 
        printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: push(); break; 
            case 2: pop(); break; 
            case 3: display(); break; 
            case 4: peek(); break; 
            case 5: printf("Exiting program...\n"); break; 
            default: printf("Invalid choice! Please enter a valid option.\n"); 
        } 
    } while (choice != 5); 
    
 return 0;
}
