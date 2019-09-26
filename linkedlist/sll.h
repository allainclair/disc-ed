typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct SimpleLinkedList {
    Node *head;
    int size;
} SimpleLinkedList;



Node *sllist_create();
Node *sllist_insert(Node *head, int new_value);
void sllist_print(Node *head);
int sllist_remove(SimpleLinkedList *list, int value);
int sllist_search(SimpleLinkedList *list, int value);
int sllist_update(SimpleLinkedList *list, int value, int new_value);
