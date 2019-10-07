#include <stdio.h>
#include <stdlib.h>

#include "sll.h"


static Node *create(int value) {
    Node *new_node = (Node*) malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }

    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

Node *sllist_create() {
    Node *head = NULL;
    return head;
}


int eh_crescente(Node *head) {
    if (!head)
        return 1;

    for (Node *cur=head; cur->next; cur=cur->next)
        if (cur->value > cur->next->value)
            return 0;
    return 1;
}


/* Remove a Node with the "value"
 * Return new head if needed;
*/
Node *sllist_remove(Node *head, int value) {
    Node
        *prev = NULL;

    for(Node *cursor = head; cursor; cursor=cursor->next) {
        if (cursor->value == value) {  // value found!.
            // remove = cursor;
            if (prev != NULL) {
                prev->next = cursor->next;
                free(cursor);
                return head;
            }
            else {  // Removing first node (head).
                printf("First node.\n");
                prev = head;
                head = head->next;
                free(prev);
                return head;
            }
        }
        prev = cursor;
    }
    return head;
}


Node *sllist_insert(Node *head, int new_value) {
    Node *new_node = create(new_value);
    new_node->next = head;
    head = new_node;
    return head;
}


int sllist_size(Node *head) {
    Node *aux = head;
    int size = 0;

    while (aux != NULL) {
        aux = aux->next;
        size++;
    }
    return size;
}


int sllist_search(Node *head, int value) {
    Node *cursor = head;
    int index = 0;

    while (cursor != NULL) {
        if (cursor->value == value)
            return index;
        index++;
        cursor = cursor->next;
    }
    return -1;

}

void sllist_print(Node *head) {
    Node *cursor = head;

    while (cursor != NULL) {
        printf("%d ", cursor->value);
        cursor = cursor->next;
    }
    printf("\n");
}