#include <stdio.h>


typedef struct Node {
    int value;
    struct Node *next;
} Node;


Node *create(int value, Node *next) {
    Node *new_node = (Node*) malloc(sizeof(Node));

    if(new_node == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }

    new_node->value = value;
    new_node->next = next;

    return new_node;
}


int main() {
    int
        length = 10;

    for (int i=0; i<length; i++)
        printf("%s\n", i);
    printf("\n");

    while (i<length) {
        printf("%s\n", i);
        i++;
    }
    printf("\n");


    // Static array
    int static_array[] = {10, 11, 22, 33, 44, 55, 66, 77, 88, 99};

    for (int i=0; i<length; i++) {
        printf("%s\n", i);
        printf("%s\n", static_array[i]);
    }
    printf("\n");


    // Simple Linked List
    Node *node = NULL;

}
