// Student Name: Reanielle Broas
// Student ID: C00296913
// Lab 1

// dont use cout in any of the functions apart from PrintArray();
//Find the largest value in the entire array and replace all occurrences with - 1. Return the largest value found.
#include <iostream>
using namespace std;

int ReplaceLargestValue(int array[4][6]){
    int largest = array[0][0];

    // getting the largest
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            if(array[i][j] > largest){
                largest = array[i][j];
            }
        }
    }
    // replacing the largest with -1
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            if(array[i][j] == largest){
                array[i][j] = -1;
            }
        }
    }
    return largest;
}


// function to print the array
void printArr(int arr[4][6]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            cout << arr[i][j] << ", ";
        }
        cout << endl;
    }
}

int main(){
    int array[4][6] = {
        {0,0,3,1,3,4},
        {0,0,2,3,4,3},
        {0,0,1,3,3,2},
        {0,0,2,2,2,2} 

    };

    int largest = ReplaceLargestValue(array);
    printArr(array); // using printArr to print the array
    
}