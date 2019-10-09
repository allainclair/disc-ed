#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sll.h"


/* Test the slist_create comparing with a zero size field. */
void test_create() {
    Node *head = NULL;

    head = sllist_create();
    assert (head == NULL);
}

void test_cpy() {
    int B[] = {1, 2, 3, 4, 5, 6};

    Node *head = cpy(B, 6);
    sllist_print(head);
}

/* Test insertions into the list. */
void test_insert() {
    Node *head = NULL;

    // printf("head %d\n", head);
    for (int i=0; i<20; i++) {
        head = sllist_insert(head, i);
        sllist_print(head);
        printf("\n");
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


void test_remove() {
    Node *head = NULL;
    int index;

    // printf("head %d\n", head);
    for (int i=0; i<10; i++) {
        head = sllist_insert(head, i);
        sllist_print(head);
        printf("\n");
    }

    // Remove the value 5
    int value = 9;
    head = sllist_remove(head, value);
    printf("Removed value list. Value %d\n", value);
    sllist_print(head);
    // assert(index == 6);
}


void test_remove_() {
    Node *head = NULL;
    int index;

    // printf("head %d\n", head);
    for (int i=0; i<10; i++) {
        head = sllist_insert(head, i);
        sllist_print(head);
        printf("\n");
    }

    // Remove the value 5
    int value = 9;
    int i = sllist_remove_(&head, value);
    printf("Removed value list. Value %d index %d\n", value, i);
    sllist_print(head);
    // assert(index == 6);
}

void test_eh_crescente() {
    Node *head = NULL;
    int index;

    // printf("head %d\n", head);
    for (int i=0; i<10; i++) {
        head = sllist_insert(head, i);
        sllist_print(head);
        printf("\n");
    }

    assert (!eh_crescente(head));
}


void test_size() {
    Node *head = NULL;
    int size;

    for (int i=0; i<10; i++)
        head = sllist_insert(head, i);
    sllist_print(head);

    size = sllist_size(head);
    printf("Tamanho: %d\n", size);
    assert (sllist_size(head) == 10);
}


int main() {
    // test_create();
    test_cpy();
    // test_insert();
    // test_eh_crescente();
    // test_remove();
    // test_remove_();
    // test_search();
    // test_update();
    // slist_print(list);
    // printf("%d\n", ret);
    // test_size();
}
