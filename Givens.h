#ifndef GIVENS_H
#define GIVENS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100  // Maximum line size for input files

// Node struct definition
typedef struct Node {
    char* data;
    struct Node* next;
} Node;

#endif // GIVENS_H
