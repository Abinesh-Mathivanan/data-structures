#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Node
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the Queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize the queue
void initialize(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enQueue (insert) an element into the queue
void enQueue(struct Queue* queue, int value) {
    // Create a new Node with the given value
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;

    // If the queue is empty, set both front and rear to the new Node
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Otherwise, add the new Node to the rear of the queue
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("%d enQueued into the queue.\n", value);
}

// Function to deQueue (delete) an element from the queue
void deQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty! Deletion is not possible.\n");
        return;
    } else {
        // Remove the front Node and update the front
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        printf("Element deQueued from the queue.\n");
    }
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        struct Node* current = queue->front;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue queue;
    initialize(&queue);
    int choice, data;

    while (1) {
        printf("\n1. EnQueue\n2. DeQueue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enQueue: ");
                scanf("%d", &data);
                enQueue(&queue, data);
                break;
            case 2:
                deQueue(&queue);
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
