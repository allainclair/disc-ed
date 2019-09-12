#include  <stdio.h>


int sequecial_search(int array[], int size, int element) {
  for (int i=0; i<size; i++) {
      if (array[i] == element)
        return i;
  }
  return -1;
}


int main() {
  int
    array[] = {1, 2, 3, 4, 5, 6, 7, 8};

  printf("%d", sequecial_search(array, 6, 10));
}
