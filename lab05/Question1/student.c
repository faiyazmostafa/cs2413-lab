/*
Question 1: Two Sum
...
*/
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define TABLE_SIZE 1009

static int hash(int key);
static void insert(Node* table[], int key, int value);
static int find(Node* table[], int key, int* value);
static void freeTable(Node* table[]);

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Node* table[TABLE_SIZE] = {NULL};

    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int foundIndex;

        if (find(table, complement, &foundIndex)) {
            result[0] = foundIndex;
            result[1] = i;
            freeTable(table);
            return result;
        }

        insert(table, nums[i], i);
    }

    // No solution found (problem guarantees one exists)
    *returnSize = 0;
    free(result);
    freeTable(table);
    return NULL;
}

static int hash(int key) {
    // Handle negative keys by taking absolute value first
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

static void insert(Node* table[], int key, int value) {
    int index = hash(key);

    Node* newNode = malloc(sizeof(Node));
    newNode->key   = key;
    newNode->value = value;
    newNode->next  = table[index];  // prepend to chain
    table[index]   = newNode;
}

static int find(Node* table[], int key, int* value) {
    int index = hash(key);
    Node* current = table[index];

    while (current != NULL) {
        if (current->key == key) {
            *value = current->value;
            return 1;
        }
        current = current->next;
    }

    return 0;
}

static void freeTable(Node* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        table[i] = NULL;
    }
}
