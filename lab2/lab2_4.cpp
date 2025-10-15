#include <iostream>
using namespace std;

// Swap two specified rows in the array.
void SwapRows(int array[4][6], int row1, int row2)
{
    int temp; // Temporary variable for swapping

    // Swapping the rows
    for(int i = 0; i < 6; i++){
        int temp = array[row1][i];
        array[row1][i] = array[row2][i];
        array[row2][i] = temp;
    }
}

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

    SwapRows(array, 0, 1);
    printArr(array); // using printArr to print the array
    
}
