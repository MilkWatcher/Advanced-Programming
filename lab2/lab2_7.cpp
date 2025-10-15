#include <iostream>
using namespace std;
//Count how many different unique values exist in the array(ignore 0 and -1).
int countUniqueValues(int array){
    int count = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            // logic to count unique values
            if(array[i][j] != 0 && array[i][j] != -1){
                count++;
            }

        }
    }
}