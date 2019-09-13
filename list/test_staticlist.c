#include <stdio.h>
#include <assert.h>

#include "staticlist.h"


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
        index = slist_search(list, input_array[i]);
        // printf("\nindex: %d i: %d\n", index, i);
        assert(index == i);
    }

    assert (slist_search(list, 100) == -1);
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
    test_create();
    test_insert();
    // test_remove();
    test_search();
    test_update();
    // slist_print(list);
    // printf("%d\n", ret);
}
