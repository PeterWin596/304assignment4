#include "LinkedList.h"

// Creates a new node and copies the data
Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory");
        return NULL;
    }

    // Allocate memory for data and copy string
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

// Inserts a node at the end of the list
void insertAtEnd(Node** head, Node* newNode) {
    if (!head || !newNode) return;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Reads a file and creates a linked list from its lines
Node* createList(FILE* inf) {
    if (!inf) return NULL;

    Node* head = NULL;
    char buffer[MAX_LINE_LENGTH];

    while (fgets(buffer, MAX_LINE_LENGTH, inf)) {
        buffer[strcspn(buffer, "\n")] = 0;  // Remove trailing newline
        Node* newNode = createNode(buffer);
        insertAtEnd(&head, newNode);
    }
    return head;
}

// Removes a node at the given index
Node* removeNode(Node** head, int index) {
    if (!head || !(*head) || index < 0) return NULL;

    Node* temp = *head;
    Node* prev = NULL;

    // Removing the head node
    if (index == 0) {
        *head = temp->next;
        temp->next = NULL;
        return temp;
    }

    // Traverse to the node to remove
    for (int i = 0; temp && i < index; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) return NULL;  // Index out of bounds

    prev->next = temp->next;
    temp->next = NULL;
    return temp;
}

// Traverses and prints the linked list
void traverse(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

// Frees a single node
void freeNode(Node* aNode) {
    if (!aNode) return;
    free(aNode->data);
    free(aNode);
}

// Frees the entire linked list
void freeList(Node** head) {
    if (!head || !(*head)) return;

    Node* temp = *head;
    while (temp) {
        Node* nextNode = temp->next;
        freeNode(temp);
        temp = nextNode;
    }
    *head = NULL;
}
