#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Define a structure for a queue node
struct QueueNode {
    struct Node* data;
    struct QueueNode* next;
};

// Define a structure for the queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new queue node
struct QueueNode* createQueueNode(struct Node* data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue a node into the queue
void enqueue(struct Queue* queue, struct Node* data) {
    struct QueueNode* newNode = createQueueNode(data);
    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue a node from the queue
struct Node* dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    } else {
        struct QueueNode* temp = queue->front;
        struct Node* data = temp->data;
        queue->front = queue->front->next;
        free(temp);
        return data;
    }
}

// Function to perform breadth-first tree traversal
void breadthFirstTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Queue queue;
    initializeQueue(&queue);
    enqueue(&queue, root);

    while (!isQueueEmpty(&queue)) {
        struct Node* current = dequeue(&queue);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(&queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(&queue, current->right);
        }
    }
}

int main() {
    // Create a sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Breadth-First Traversal: ");
    breadthFirstTraversal(root);
    printf("\n");

    return 0;
}
