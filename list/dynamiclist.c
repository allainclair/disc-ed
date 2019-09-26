#include <stdio.h>
#include <stdlib.h>

#include "dynamiclist.h"


/* Increase the list->values size multiplying by 2.
return 1: it is all ok.
return -1: realloc could not get memory.
*/
static int increase_list(DynamicList *list) {
    int new_allocation_size;
    int *values = list->values;

    printf("list->capacity: %d\n", list->capacity);
    if (list->capacity > 0) {
        // Espaco disponivel dobrado.
        new_allocation_size = list->capacity * 2 * sizeof(int);

        list->values = (int *) realloc(values, new_allocation_size);
        // Retorna NULL se falhar.
        if (list->values == NULL)
            return 0;

        // A capacidade eh dada pela quantidade de "int"s que podemos
        // no momento colocar.
        list->capacity = new_allocation_size / sizeof(int);
        return 1;
    }
    if (list->capacity <= 0) {  // First allocation.
        int *data = (int *) malloc(1 * sizeof(int));
        list->values = data;
        list->capacity = sizeof(list->values) / sizeof(int);
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
    if (list->size + 1 > list->capacity)
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
int dlist_remove(DynamicList *list, int value) {
    return -1;
}


/* return > -1: Indice do "value" encontrado.
 * return <= -1: Nao encontrou "value" na lista.
*/
int dlist_search(DynamicList *list, int value) {
    return -1;
}


/* return > -1: Indice do "value" encontrado e atualizado para new_value.
 * return <= -1: Nao encontrou "value" na lista.
*/
int dlist_update(DynamicList *list, int value, int new_value) {
    return -1;
}
