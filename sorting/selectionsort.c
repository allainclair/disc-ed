void selection_sort(int array[], int size) {
    int
        lower_index,
        aux;

    for (int i=0; i < size-1; i++) {
        lower_index = i;
        for (int j=i+1; j < size; j++)
            if (array[j] < array[lower_index])
                lower_index = j;
        aux = array[i];
        array[i] = array[lower_index];
        array[lower_index] = aux;
    }
}
