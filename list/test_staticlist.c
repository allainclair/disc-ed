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


int main() {
    test_create();
    test_insert();
    test_remove();
    // test_search();
    // test_update();
    // slist_print(list);
    // printf("%d\n", ret);
}
