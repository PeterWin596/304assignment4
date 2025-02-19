#include "Testing.h"

int main() {
    char filepath[100];

    // Prompt user for a valid file path
    FILE* infile = NULL;
    while (!infile) {
        printf("Enter a valid file path: ");
        scanf("%s", filepath);
        infile = fopen(filepath, "r");
        if (!infile) {
            printf("Invalid file path. Try again.\n");
        }
    }

    // Create a linked list from the file
    Node* head = createList(infile);
    fclose(infile);

    // Display the list
    printf("\nLinked List Contents:\n");
    traverse(head);

    // Test removeNode
    printf("\nRemoving node at index 1...\n");
    Node* removedNode = removeNode(&head, 1);
    if (removedNode) {
        printf("Removed: %s\n", removedNode->data);
        freeNode(removedNode);
    } else {
        printf("Failed to remove node.\n");
    }

    // Display updated list
    printf("\nUpdated Linked List:\n");
    traverse(head);

    // Free all nodes
    freeList(&head);

    return 0;
}
