#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sll.h"


/* Test the slist_create comparing with a zero size field. */
void test_create() {
    Node *head;

    head = sllist_create();
    assert (head == NULL);
}


/* Test insertions into the list. */
void test_insert() {
     Node *head = NULL;

    printf("head %d\n", head);
    for (int i=0; i<100; i++) {
        head = sllist_insert(head, i);
        // printf("%d ", head->value);

        // assert (list.values[i] == i);
    }
    // while (head != NULL) {
    //     printf("Head->next: %d\n", head->value);
    //     head = head->next;
    // }
    sllist_print(head);

    /* Full list returns -1. */
    // assert (dlist_insert(&list, 100) == -1);
}


int main() {
    test_create();
    test_insert();
    // test_remove();
    // test_search();
    // test_update();
    // slist_print(list);
    // printf("%d\n", ret);
}
