#include <stdio.h>

#define MAX 100


void array_function(int array[], int size) {
  printf("Array function.\n");
  for (int i=0; i<size; i++)
    printf("%d ", array[i]);
  printf("\n");
}


int main() {
  int
    int_array[MAX],
    *pa = int_array;  // Ponteiro para int_array.

  printf("For loop to attrib.\n");
  for (int i=0; i<MAX; i++) {
    printf("%d ", i);
    int_array[i] = i;
  }
  printf("\n");

  array_function(int_array, MAX);
  // for (int i=0; i<MAX; i++)
    // printf("%d ", int_array[i]);
  // printf("\n");

  printf("For loop to print pointer.\n");
  for (int i=0; i<MAX; i++) {
    printf("%d ", *pa);
    pa++;
  }
}
