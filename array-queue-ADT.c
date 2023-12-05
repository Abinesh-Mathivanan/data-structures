#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure for the queue
struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Function to insert data into the queue
void insert(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot insert %d.\n", data);
    } else {
        if (isEmpty(queue)) {
            queue->front = queue->rear = 0;
        } else {
            queue->rear++;
        }
        queue->arr[queue->rear] = data;
        printf("%d inserted into the queue.\n", data);
    }
}

// Function to delete data from the queue
int delete(struct Queue* queue) {
    int data;
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot delete.\n");
        return -1; // Return a sentinel value indicating an error
    } else {
        data = queue->arr[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front++;
        }
        printf("%d deleted from the queue.\n", data);
        return data;
    }
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue queue;
    initialize(&queue);
    int choice, data;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&queue, data);
                break;
            case 2:
                data = delete(&queue);
                if (data != -1) {
                    printf("%d deleted from the queue.\n", data);
                }
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
