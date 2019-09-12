#include <stdio.h>
#include <stdlib.h>

#include "dynamiclist.h"


static int increase_list(DynamicList *list) {
    int new_capacity;
    int *values = list->values;

    if (list->capacity > 0) {
        new_capacity = sizeof(list->values) * 2;
        if (realloc(values, new_capacity) == NULL)
            return 0;
        list->capacity = new_capacity;
        return 1;
    }
    if (list->capacity <= 0) {  // First allocation.
        int *data = malloc(1 * sizeof(int));
        list->values = data;
        list->capacity++;
        return 1;
    }
}


int dlist_create(DynamicList *list) {
    list->size = 0;
    list->capacity = 0;
    list->values = NULL;
}


/* return > -1: Indice do novo "value" inserido.
 * return <= -1: Nao deu pra inserir.
*/
int dlist_insert(DynamicList *list, int new_value) {
    // Try to get more memory.
    if (list->size + 1 >= list->capacity)
        if (!increase_list(list))
            return -1;
    list->values[list->size++] = new_value;
    return list->size - 1;
}


void dlist_print(DynamicList list) {
    printf("List capacity: %d\n", list.capacity);
    printf("List size: %d\n", list.size);
    for (int i=0; i<list.size; i++) {
        printf("%d ", list.values[i]);
    }
    printf("\n");
}


/* return > -1: Indice do "value" encontrado e removido.
 * return <= -1: Nao encontrou "value" na lista.
*/
int dlist_remove(DynamicList list, int value) {
    return -1;
}


/* return > -1: Indice do "value" encontrado.
 * return <= -1: Nao encontrou "value" na lista.
*/
int dlist_search(DynamicList list, int value) {
    return -1;
}


/* return > -1: Indice do "value" encontrado e atualizado para new_value.
 * return <= -1: Nao encontrou "value" na lista.
*/
int dlist_update(DynamicList list, int value, int new_value) {
    return -1;
}
