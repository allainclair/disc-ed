int eh_crescente(Node *head) {
    if (!head)
        return 1;

    for (Node *cur=head; cur->next; cur=cur->next)
        if (cur->value > cur->next->value)
            return 0;
    return 1;
}


int min(Node *head) {
    int
        i,
        min_value,
        min_index;

    if (head) {
        min_value = head->value;
        i = min_index = 0;
    }
    else
        return -1;
    Node *cur = head->next;
    while (cur) {
        i++;
        if (cur->value < min_value) {
            min_value = cur->value;
            min_index = i;
        }
    }
    return min_index;
}

int main() {

}
