#include <iostream>
using namespace std;

//Count all zero values and replace them with - 1. Return the count of zeros.
int CountAndReplaceZeros(int array[4][6]){
    int count = 0;

    // replacing 0s with -1 and counting them
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            if(array[i][j] == 0){
                array[i][j] = -1;
                count++;
            }
        }
    }
	return count;
}

void printArr(int arr[4][6]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            cout << arr[i][j] << ", ";
        }
        cout << endl;
        cout << "Number of 0s in the array: " << endl;
    }
}

int main(){
    int array[4][6] = {
        {0,0,3,1,3,4},
        {0,0,2,3,4,3},
        {0,0,1,3,3,2},
        {0,0,2,2,2,2} 
    };
    int count = CountAndReplaceZeros(array);
    printArr(array); // using printArr to print the array
}
