#include <stdio.h>
#include <assert.h>

#include "staticlist.h"


void test_slist_binsearch() {
    StaticList list;
    int index;

    slist_create(&list);

    for (int i=0; i<MAX; i++)
        index = slist_insert(&list, i);

    for (int i=0; i<MAX; i++) {
        index = slist_binsearch(&list, i);
        assert (index == i);
    }
}

void test_slist_search() {
    StaticList list;
    int index;

    slist_create(&list);

    for (int i=0; i<MAX; i++)
        index = slist_insert(&list, i);

    for (int i=0; i<MAX; i++) {
        index = slist_search(&list, i);
        assert (index == i);
    }
}

/* Test the slist_create comparing with a zero size field. */
void test_create() {
    StaticList list;

    slist_create(&list);
    assert (list.size == 0);
}


/* Test MAX + 1 insertions into the list. */
void test_insert() {
    StaticList list;
    int index;

    slist_create(&list);

    for (int i=0; i<MAX; i++) {
        index = slist_insert(&list, i);
        assert (index == i);
        assert (list.values[i] == i);
    }

    /* Full list returns -1. */
    assert (slist_insert(&list, 100) == -1);
}


/* Test MAX + 1 sorted insertions into the list. */
void test_insert_sorted() {
    StaticList list;
    int index, j;

    slist_create(&list);

    for (int i = MAX-1; i >= 0; i--) {
        index = slist_insert_sorted(&list, i);
        // printf("Index: %d\n", index);
        // printf("Value: %d\n", i);
        assert (index == 0);
        // assert (list.values[i] == i);
    }
    // slist_print(list);

    /* Full list returns -1. */
    assert (slist_insert(&list, 100) == -1);
}


void test_insert_sorted_2() {
    StaticList list;
    int index;
    int values[] = {1, 5, 10, 15, 2, 3, 11};
    int values_sorted[] = {1, 2, 3, 5, 10, 11, 15};
    int indices[] = {0, 1, 2, 3, 1, 2, 5};

    slist_create(&list);

    for (int i=0; i<MAX; i++) {
        index = slist_insert_sorted(&list, i);
        assert (list.values[i] == i);
    }

    /* Full list returns -1. */
    assert (slist_insert(&list, 100) == -1);

}


void test_remove() {
    StaticList list;
    int
        input_array[] = {1, 2, 0, -1, 10, 11, 3, 20, -100, 7, 200},
        output_array[] = {1, 2, 0, -1, 11, 3, 20, -100, 7, 200},
        size = 11,
        index;

        // Inicializando a lista.
        //printf("Print\n");
        slist_create(&list);
        for (int i=0; i<size; i++)
            index = slist_insert(&list, input_array[i]);


        // printf("Print\n");
        // slist_print(list);
        index = slist_remove(&list, 10);
        //printf("Print index %d\n", index);
        assert(index == 4);

        for (int i=0; i<size-1; i++)
            assert(list.values[i] == output_array[i]);

}


void test_search() {
    StaticList list;
    int
        input_array[] = {1, 2, 0, -1, 10, 11, 3, 20, -100, 7, 200},
        size = 11,
        index;

    // Inicializando a lista.
    slist_create(&list);
    for (int i=0; i<size; i++)
        index = slist_insert(&list, input_array[i]);

    for (int i=0; i<size; i++) {
        index = slist_search(&list, input_array[i]);
        // printf("\nindex: %d i: %d\n", index, i);
        assert(index == i);
    }

    assert (slist_search(&list, 100) == -1);
}


void test_update() {
    StaticList list;
    int
        input_array[] = {1, 2, 0, -1, 10, 11, 3, 20, -100, 7, 200},
        size = 11,
        index,
        return_index,
        old_value,
        new_value;

    // Inicializando a lista.
    slist_create(&list);
    for (int i=0; i<size; i++)
        index = slist_insert(&list, input_array[i]);

    old_value = 3;
    new_value = 30;
    index = slist_update(&list, old_value, new_value);
    assert (index == 6);
    assert (list.values[index] == 30);
}


int main() {
    // test_create();
    // test_insert();
    // test_insert_sorted();
    // test_remove();
    // test_search();
    // test_update();

     test_slist_binsearch();
    //test_slist_search();
    // slist_print(list);
    // printf("%d\n", ret);
}
