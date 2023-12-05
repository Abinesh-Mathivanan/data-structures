#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure for the stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to push data onto the stack
void push(struct Stack* stack, int data) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push %d.\n", data);
    } else {
        stack->arr[++stack->top] = data;
        printf("%d pushed onto the stack.\n", data);
    }
}

// Function to pop data from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value indicating an error
    } else {
        int data = stack->arr[stack->top--];
        printf("%d popped from the stack.\n", data);
        return data;
    }
}

// Function to display the elements of the stack
void display(struct Stack stack) {
    if (stack.top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack.top; i++) {
            printf("%d ", stack.arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);
    int choice, data;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                data = pop(&stack);
                if (data != -1) {
                    printf("%d popped from the stack.\n", data);
                }
                break;
            case 3:
                display(stack);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
