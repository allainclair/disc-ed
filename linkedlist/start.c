#include <stdio.h>
#include <stdlib.h>  // To use malloc() and free().


typedef struct Node {
    int value;
    struct Node *next;
} Node;


Node *create(int value) {
    Node *new_node = (Node*) malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }

    new_node->value = value;
    new_node->next = NULL;  // Se nao tem valor, aponte ponteiros para nulo.
    return new_node;
}


int main() {
    int length = 10;

    printf("For\n");
    for (int i=0; i<length; i++)  // Complexidade O(n);
        printf("%d\n", i);
    printf("\n");

    printf("While\n");
    int i = 0;
    while (i<length) {  // Complexidade O(n);
        printf("%d\n", i);
        i++;
    }
    printf("\n");


    // Static array
    int static_array[] = {10, 11, 22, 33, 44, 55, 66, 77, 88, 99};
    printf("Static Array\n");
    for (int i=0; i<length; i++) {  // Complexidade O(n).
        printf("%d\n", i);
        printf("%d\n", static_array[i]);
    }
    printf("\n");


    // Simple Linked List
    Node *head = NULL; // The first node already points to NULL.
    int value;  // Value to be put in the linkedlist.

    // Creating nodes and linking them
    for (int i=0; i<length; i++) {  // Complexidade O(n).
        value = static_array[i];
        Node *new_node = create(value);
        new_node->next = head;
        head = new_node;
    }

    Node *cursor = head;  // Aux variable for not losing the head.

    printf("Linked List\n");
    i = 0;
    while (cursor != NULL) {  // Complexidade O(n).
        printf("i %d\n", i);
        printf("cursor->value %d\n", cursor->value);
        cursor = cursor->next;
        i++;
    }
    printf("\n");

    cursor = head;
    i = 0;
    while (cursor != NULL) {  // Complexidade O(n).
        printf("Node i to be freed: %d\n", i);
        printf("Node value: %d\n", cursor->value);
        head = cursor;
        cursor = cursor->next;
        free(head);
        i++;
    }
}
