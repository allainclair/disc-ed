#include <stdio.h>


int main() {
    int
        value,
        *p_value;

    value = 10;
    printf("value: %d\n", value);
    printf("&value: %p\n", &value);

    p_value = &value;
    printf("*p_value: %d\n", *p_value);
    printf("p_value: %p\n", p_value);
    printf("&p_value: %p\n", &p_value);

    printf("*(&value): %d\n", *(&value));

}
