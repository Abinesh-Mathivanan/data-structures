#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of slots in the hash table
#define MAX_SLOTS 100

// Define a structure for a linked list node
struct ListNode {
    int data;
    struct ListNode* next;
};

// Define a structure for a hash table slot
struct HashSlot {
    struct ListNode* head;
};

// Function to initialize the hash table
void initializeHashTable(struct HashSlot hashTable[], int numSlots) {
    for (int i = 0; i < numSlots; i++) {
        hashTable[i].head = NULL;
    }
}

// Function to compute the hash value for a key
int hashFunction(int key, int numSlots) {
    return key % numSlots;
}

// Function to insert a key into the hash table
void insert(struct HashSlot hashTable[], int numSlots, int key) {
    int slot = hashFunction(key, numSlots);
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = key;
    newNode->next = hashTable[slot].head;
    hashTable[slot].head = newNode;
}

// Function to search for a key in the hash table
int search(struct HashSlot hashTable[], int numSlots, int key) {
    int slot = hashFunction(key, numSlots);
    struct ListNode* current = hashTable[slot].head;
    while (current != NULL) {
        if (current->data == key) {
            return 1; // Key found
        }
        current = current->next;
    }
    return 0; // Key not found
}

int main() {
    int numSlots, numKeys;
    printf("Enter the number of slots in the hash table: ");
    scanf("%d", &numSlots);

    struct HashSlot hashTable[MAX_SLOTS];
    initializeHashTable(hashTable, numSlots);

    printf("Enter the number of keys to insert: ");
    scanf("%d", &numKeys);

    printf("Enter the keys to insert:\n");
    for (int i = 0; i < numKeys; i++) {
        int key;
        scanf("%d", &key);
        insert(hashTable, numSlots, key);
    }

    printf("Enter a key to search for: ");
    int searchKey;
    scanf("%d", &searchKey);

    if (search(hashTable, numSlots, searchKey)) {
        printf("Key %d found in the hash table.\n", searchKey);
    } else {
        printf("Key %d not found in the hash table.\n", searchKey);
    }

    return 0;
}
