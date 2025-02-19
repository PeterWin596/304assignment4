#include "LinkedList.h"
#include <stdlib.h>  
#include <string.h>  

// Create a new node
struct Node* createNode(char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        perror("Failed to allocate memory");
        return NULL;
    }

    // Allocate memory for data and copy it
    newNode->data = (char*)malloc(strlen(data) + 1);
    if (!newNode->data) {
        free(newNode);
        perror("Failed to allocate memory for data");
        return NULL;
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Insert at the end
void insertAtEnd(struct Node** head, struct Node* newNode) {
    if (!head || !newNode) return;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Create a list from a file
struct Node* createList(FILE* inf) {
    if (!inf) return NULL;

    struct Node* head = NULL;
    char buffer[100];

    while (fgets(buffer, 100, inf)) {
        buffer[strcspn(buffer, "\n")] = 0;  // Remove newline
        struct Node* newNode = createNode(buffer);
        insertAtEnd(&head, newNode);
    }
    return head;
}

// Remove a node
struct Node* removeNode(struct Node** head, int index) {
    if (!head || !(*head) || index < 0) return NULL;

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (index == 0) {
        *head = temp->next;
        temp->next = NULL;
        return temp;
    }

    for (int i = 0; temp && i < index; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) return NULL;  // Index out of bounds

    prev->next = temp->next;
    temp->next = NULL;
    return temp;
}

// Traverse the list
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

// Free a single node
void freeNode(struct Node* aNode) {
    if (!aNode) return;
    free(aNode->data);
    free(aNode);
}

// Free the entire list
void freeList(struct Node** head) {
    if (!head || !(*head)) return;

    struct Node* temp = *head;
    while (temp) {
        struct Node* nextNode = temp->next;
        freeNode(temp);
        temp = nextNode;
    }
    *head = NULL;
}
