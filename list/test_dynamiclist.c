#include <assert.h>

#include "dynamiclist.h"


/* Test the slist_create comparing with a zero size field. */
void test_create() {
    DynamicList list;

    dlist_create(&list);
    assert (list.size == 0);
}


/* Test insertions into the list. */
void test_insert() {
    DynamicList list;
    int index;

    dlist_create(&list);

    for (int i=0; i<100; i++) {
        index = dlist_insert(&list, i);
        dlist_print(list);
        assert (index == i);
        assert (list.values[i] == i);
    }

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
