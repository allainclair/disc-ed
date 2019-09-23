#include <stdio.h>

#include "staticlist.h"


/* return > -1: Indice do novo "value" inserido.
 * return <= -1: Nao deu pra inserir.
*/

int slist_binsearch(StaticList *list, int value) {
    int
        i = 0,
        j = list->size -1,
        mid = list->size / 2;

    while (i <= j) {
        mid = (i + j) / 2;
        if (value < list->values[mid]) {
            j = mid - 1;
        } else if (value > list->values[mid]) {
            i = mid + 1;
        } else
            return mid;
    }
    return -1;
}


void slist_create(StaticList *list) {
    list->size = 0;
}


int slist_insert(StaticList *list, int new_value) {
    if (list->size >= MAX)
        return -1;
    list->values[list->size++] = new_value;
    return list->size - 1;
}

/* return > -1: Indice do novo "value" inserido.
 * return <= -1: Nao deu pra inserir.
*/
int slist_insert_sorted(StaticList *list, int new_value) {
    int
        insert_index,
        prev,
        save;

    if (list->size >= MAX)
        return -1;

    for (insert_index=0; insert_index<list->size; insert_index++) {
        // printf("List->values[insert_inidex] %d\n", list->values[insert_index]);
        // printf("New value %d\n", list->values[insert_index]);
        if (new_value < list->values[insert_index]) {
            prev = list->values[insert_index];
            // printf("Prev %d\n", prev);
            for (int i=insert_index+1; i < list->size+1; i++) {

                save = list->values[i];
                // printf("save %d\n", save);
                list->values[i] = prev;
                // printf("prev %d\n", prev);
                prev = save;
            }
            break;
        }
    }
    // printf("Insert index: %d\n", insert_index);
    list->values[insert_index] = new_value;
    list->size++;
    return insert_index;
}


void slist_print(StaticList list) {
    printf("List: ");
    for (int i=0; i<list.size; i++) {
        printf("%d ", list.values[i]);
    }
    printf("\n");
}


/* return > -1: Indice do "value" encontrado e removido.
 * return <= -1: Nao encontrou "value" na lista.
*/
int slist_remove(StaticList *list, int value) {
    int
        index = -1;

    index = slist_search(list, value);
    if (index > -1) {
        for (int i=index; i < list->size-1; i++)
            list->values[i] = list->values[i+1];
        list->size--;
    }
    return index;
}


/* return > -1: Indice do "value" encontrado.
 * return <= -1: Nao encontrou "value" na lista.
*/
int slist_search(StaticList *list, int value) {
    for (int i=0; i<list->size; i++) {
        if (list->values[i] == value)
            return i;
    }
    return -1;
}


/* return > -1: Indice do "value" encontrado e atualizado para new_value.
 * return <= -1: Nao encontrou "value" na lista.
*/
int slist_update(StaticList *list, int value, int new_value) {
    int index;

    index = slist_search(list, value);
    if (index > -1)
        list->values[index] = new_value;
    return index;
}
