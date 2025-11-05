int sum_array(int *arr, int size) {
    int sum = 0;
    int *ptr = arr;
    for (int i = 0; i < size; i++) {
        sum += *ptr;
        ptr++;
    }
    return sum;
}
