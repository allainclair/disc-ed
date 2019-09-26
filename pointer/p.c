#include <stdio.h>

void foo(int value, int *p_value, int **pp_value) {
    printf("\n");
    printf("&value: %p\n", &value);
    printf("&p_value: %p\n", &p_value);
    printf("&pp_value: %p\n", &pp_value);
}

int main() {
    int
        value,
        *p_value,
        **pp_value;

    value = 10;
    printf("value: %d\n", value);
    printf("&value: %p\n", &value);

    p_value = &value;
    printf("*p_value: %d\n", *p_value);
    printf("p_value: %p\n", p_value);
    printf("&p_value: %p\n", &p_value);

    printf("*(&value): %d\n", *(&value));

    pp_value = &p_value;
    printf("\n");
    printf("*pp_value: %p\n", *pp_value);
    printf("pp_value: %p\n", pp_value);
    printf("&pp_value: %p\n", &pp_value);

    foo(value, p_value, pp_value);

}
