#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Givens.h"

// Function prototypes
Node* createNode(char* data);
void insertAtEnd(Node** head, Node* newNode);
Node* createList(FILE* inf);
Node* removeNode(Node** head, int index);
void traverse(Node* head);
void freeNode(Node* aNode);
void freeList(Node** head);

#endif // LINKEDLIST_H
