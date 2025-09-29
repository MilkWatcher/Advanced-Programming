// Student Name: Reanielle Broas
// Student ID: C00296913
// Lab 10 Copy all elements from an arr1 to  arr2. Both arrays are the same size.
#include <iostream>
using namespace std;

void copyArraytoArray(int size, int arr1[], int arr2[]){
    for(int i = 0; i < size; i++){
        arr2[i] = arr1[i];
    }
    return;
}

int main(){

    int arr1[] = { 1, 4, 6, 4, 5};
    int arr2[5];
    int size = sizeof(arr1) / sizeof(arr1[0]);

    copyArraytoArray(size, arr1, arr2);
    
    // output array 1
    cout << "Array 1: ";
    for(int i = 0; i < size; i++) {
        cout << arr1[i] << " ";
    }

    cout << endl;

    // output array 2
    cout << "Array 2: ";
    for(int i = 0; i < size; i++) {
        cout << arr2[i] << " ";
    }
    
    cout << endl;
}