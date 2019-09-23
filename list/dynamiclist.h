typedef struct DynamicList {
    int *values;
    int size;
    int capacity;
} DynamicList;

int dlist_create(DynamicList *list);
int dlist_insert(DynamicList *list, int new_value);
void dlist_print(DynamicList list);
int dlist_remove(DynamicList *list, int value);
int dlist_search(DynamicList *list, int value);
int dlist_update(DynamicList *list, int value, int new_value);
