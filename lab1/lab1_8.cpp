// Student Name: Reanielle Broas
// Student ID: C00296913
// Lab 8 Find an element in an array and prints out the index where 
// it was found and -1 if it was not found.

#include <iostream>
using namespace std;

int find(int size, int arr[], int toFind){
    for(int i = 0; i < size; i++){
        if(arr[i] == toFind){
            return i;
        }
    }
    return -1;
}

int main(){
    int toFind;
    int arr[] = { 1, 2, 3, 4, 5};

    cout << "Enter element to find: ";
    cin >> toFind;

    int index = find(5, arr, toFind);
    cout << "Index: " << index << endl;

    return 0;
}

