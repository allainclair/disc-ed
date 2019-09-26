#include <stdio.h>
#include <stdlib.h>

#include "sll.h"


static Node *create(int value, Node *next) {
    Node *new_node = (Node*) malloc(sizeof(Node));

    if(new_node == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }

    new_node->value = value;
    new_node->next = next;

    return new_node;
}

Node *sllist_create() {
    Node *head = NULL;
    return head;
}


Node *sllist_insert(Node *head, int new_value) {
    Node *new_node = create(new_value, head);
    head = new_node;
    return head;
}

void sllist_print(Node *head) {
    Node *cursor = head;

    while (cursor != NULL) {
        printf("%d ", cursor->value);
        cursor = cursor->next;
    }
    printf("\n");
}
