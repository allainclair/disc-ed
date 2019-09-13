#include <stdio.h>
#include <assert.h>

#include "selectionsort.h"


void test_selection() {
    int
        input_array[] = {1, 2, 0, -1, 10, 11, 3, 20, -100, 2, 0},
        size = 8,
        prox;

    selection_sort(input_array, size);
    for (int i=0; i < size-1; i++) {
        prox = input_array[i+1];
        assert (prox >= input_array[i]);
    }
    printf("\n");
}


int main() {
    test_selection();
}
