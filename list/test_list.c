#include <stdio.h>

#define MAX 1000

//  tentar mesmo nome struck e typedef
typedef struct StaticListStruct {
    int values[MAX];
    int size;
} StaticList;


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
int slist_remove(StaticList list, int value) {
    return -1;
}


/* return > -1: Indice do "value" encontrado.
 * return <= -1: Nao encontrou "value" na lista.
*/
int slist_search(StaticList list, int value) {

    return -1;
}


/* return > -1: Indice do "value" encontrado e atualizado para new_value.
 * return <= -1: Nao encontrou "value" na lista.
*/
int slist_update(StaticList list, int value, int new_value) {
    return -1;
}


int main() {
    StaticList list;

    int
        index,
        value = 1;

    slist_create(&list);
    index = slist_insert(&list, 10);
    printf("index: %d\n", index);
    slist_print(list);
    // printf("%d\n", ret);
}
