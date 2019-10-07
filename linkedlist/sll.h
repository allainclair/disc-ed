typedef struct Node {
    int value;
    struct Node *next;
} Node;


Node *sllist_create();
Node *sllist_insert(Node *head, int new_value);
int eh_crescente(Node *head);
Node *sllist_remove(Node *head, int value);
int sllist_size(Node *head);
void sllist_print(Node *head);
// int sllist_remove(SimpleLinkedList *list, int value);
// int sllist_search(SimpleLinkedList *list, int value);
// int sllist_update(SimpleLinkedList *list, int value, int new_value);
