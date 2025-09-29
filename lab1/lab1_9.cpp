// Student Name: Reanielle Broas
// Student ID: C00296913
// Lab 8 Find and return the second largest element in an array of positive integer
// returns -1 if it can’t find one.

#include <iostream>
using namespace std;

int find2ndLargest(int size, int arr[]){
    // finding largest
    int largest = arr[0];
    int secondLargest = -1;

    for(int i = 0; i < size; i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i]>secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }
        return secondLargest;
}

int main(){
    int arr[] = { 2, 4, 6, 3, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    int index = find2ndLargest(size, arr);
    cout << "Second Largest Number: " << index << endl;

    return 0;
}
