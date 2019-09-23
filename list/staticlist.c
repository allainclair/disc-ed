#include <stdio.h>

#include "staticlist.h"


int slist_create(StaticList *list) {
    list->size = 0;
}


/* return > -1: Indice do novo "value" inserido.
 * return <= -1: Nao deu pra inserir.
*/
int slist_insert(StaticList *list, int new_value) {
    if (list->size >= MAX)
        return -1;
    list->values[list->size++] = new_value;
    return list->size - 1;
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
    if (index > -1){
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
    for (int i=0; i<list->size; i++)
        if (list->values[i] == value)
            return i;
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
