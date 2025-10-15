#include <iostream>
using namespace std;

// Find any horizontal sequence of 3 consecutive cells matching the 
// given pattern. Replace with - 1 and return matches found.

int ReplaceRowPattern(int array[4][6], int pattern[3])
{
	int matches = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            // checking for the pattern
            if(array[i][j] == pattern[0] && 
            array[i][j+1] == pattern[1] && 
            array[i][j+2] == pattern[2]){

                // replacing with -1
                array[i][j] = -1;
                array[i][j+1] = -1;
                array[i][j+2] = -1;
                matches++;
            }
        }
    } return matches;
}

void printArr(int arr[4][6], int matches){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            cout << arr[i][j] << ", ";
        }
        cout << endl;
        cout << "Number of patterns matched: " << matches << endl;
    }
}

int main(){
    int array[4][6] = {
        {0,0,3,1,3,4},
        {0,0,2,3,4,3},
        {0,0,1,3,3,2},
        {0,0,2,2,2,2} 
    };

    int pattern[3] = {2,2,2};
    int matches = ReplaceRowPattern(array, pattern);
    printArr(array, matches); // using printArr to print the array
    
}
