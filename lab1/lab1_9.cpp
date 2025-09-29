// Student Name: Reanielle Broas
// Student ID: C00296913
// Lab 8 Find and return the second largest element in an array of positive integer
// returns -1 if it can’t find one.

#include <iostream>
using namespace std;

int find2ndLargest(int size, int arr[]){
    int largest = arr[0];

        for(int i; i > size; i++){
            if(arr[i]>largest){
                largest = arr[i];
            }
        }
    }
    return -1;
}

int main(){
    int arr[] = { 2, 4, 6, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int index = find2ndLargest(size, arr);
    cout << "Index: " << index << endl;

    return 0;
}
