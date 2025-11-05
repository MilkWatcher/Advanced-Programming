void reverse_array(int *arr, int size){
  int *start = arr;
  int *end = arr + size - 1;
  while(start < end){
    swap_ints(start, end);
    start++;
    end--;
  }
}
