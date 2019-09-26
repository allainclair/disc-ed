#define MAX 100


typedef struct StaticList {
    int values[MAX];
    int size;
} StaticList;

int slist_binsearch(StaticList *list, int value);
void slist_create(StaticList *list);
int slist_insert(StaticList *list, int new_value);
int slist_insert_sorted(StaticList *list, int new_value);
void slist_print(StaticList list);
int slist_remove(StaticList *list, int value);
int slist_search(StaticList *list, int value);
int slist_update(StaticList *list, int value, int new_value);
