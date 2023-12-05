#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }
    printf("Node with data %d inserted.\n", data);
}

// Function to delete a node at a given position
void deleteNode(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (position == 0) {
        struct Node* temp = *head;
        struct Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        *head = (*head)->next;
        current->next = *head;
        free(temp);
        printf("Node at position 0 deleted.\n");
        return;
    }
    struct Node* current = *head;
    struct Node* prevNode = NULL;
    int i = 0;
    while (current->next != *head && i < position) {
        prevNode = current;
        current = current->next;
        i++;
    }
    if (i != position) {
        printf("Invalid position. Node not found.\n");
        return;
    }
    prevNode->next = current->next;
    free(current);
    printf("Node at position %d deleted.\n", position);
}

// Function to display the elements of the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("List elements: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf(" (Circular)\n");
}

int main() {
    struct Node* head = NULL;
    int size, choice, data, position;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (size > 0) {
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    insertNode(&head, data);
                    size--;
                } else {
                    printf("List is full. Cannot insert.\n");
                }
                break;
            case 2:
                if (size < 0) {
                    printf("List is empty. Nothing to delete.\n");
                } else {
                    printf("Enter position to delete: ");
                    scanf("%d", &position);
                    if (position < 0 || position >= size) {
                        printf("Invalid position. Cannot delete.\n");
                    } else {
                        deleteNode(&head, position);
                        size++;
                    }
                }
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
