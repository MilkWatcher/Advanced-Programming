using namespace std;
#include <iostream>

int FindColummSum(int array[4][6], int col){
    int sum = 0;
    for (int i = 0; i < 4; i++){
        sum += array[i][col];
    }
    return sum;
}

void printArr(int arr[4][5], int col, int sum){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            cout << arr[i][j] << ", ";
        }
        cout << endl;
        cout << "Sum of column " << col << " is: " << sum << endl;
    }
}

int main(){
    int array[4][6] = {
        {0,0,3,1,3,4},
        {0,0,2,3,4,3},
        {0,0,1,3,3,2},
        {0,0,2,2,2,2} 
    };
    int col = 2; // specify the column to sum
    int sum = FindColummSum(array, col);
}