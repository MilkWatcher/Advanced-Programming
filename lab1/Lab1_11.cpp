// Student Name: Reanielle Broas
// Student ID: C00296913
// Lab 11
// Insert an element in an array at a specified position. 

// Insert an element at a particular index in the array and shift 
// the elements further in the array to the right.

// Use a variable called count to track the number of elements in the array. 

// The count cannot exceed the size of the array. 

// Return true if an element was inserted, otherwise return false.
#include <iostream>
using namespace std;

bool insertElement( int size, int count, int arr[],
                    int elementToInsert, int insertIndex){
    
    
    return false;
}

int main(){
    const int size = 6; // maximum capacity of the array
    int arr[size] = { 9, 4, 1, 2 ,3};
    int count = 5; // current number of elements in the array
    
    insertElement(size, count, arr, 4, 5);

    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "New Array: " << arr[i] << " ";
    return 0;
}
