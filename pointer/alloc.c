#include <stdio.h>
#include <stdlib.h>


int main() {
    int *data = NULL;

    data = (int *) malloc(sizeof(int));

    printf("sizeof(int): %lu\n", sizeof(int));
    printf("data: %p\n", data);
    *data = 100;
    printf("*data: %d\n", *data);
    printf("data: %p\n", data);
    printf("sizeof(data): %lu\n", sizeof(data));

    data[0] = 200;
    data[1] = 300;
    printf("data 1: %d\n", data[0]);
    printf("data 0: %d\n", data[1]);

    data = (int *) realloc(data, sizeof(int) * 100);

    data[99] = 1000;

    printf("data 99: %d\n", data[99]);

    free(data);
}
