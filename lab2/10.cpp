#include <iostream>

void ShiftArrayRight(int array[4][6]) { 
    int size=24;
    int tempArr[24];
    int index=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<6;j++){
            tempArr[index++]=array[i][j];
        }
    } 
    int last = tempArr[size - 1];
    int j=0;
    for(int i = size - 1; i > 0; i--){
        tempArr[i] = tempArr[i - 1];
    }
    tempArr[0] = last; // put last element at first position

    
    index = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            array[i][j] = tempArr[index++];
        }
    }
}

void printArr(int arr[4][6]){
    for(int i=0;i<4;i++){
        for(int j=0;j<6;j++){
            std::cout<<arr[i][j]<<", ";
        }
        std::cout<<std::endl;
    }

}
int main(){
    int array[4][6] = {
        {12, 45, 67, 0, 8, 5},
        {56, 78, 0, 12, 34, 56},
        {91, 82, 0, 8, 5, 91},
        {0, 8, 91, 40, 50, 60}
    };
    ShiftArrayRight(array);
    printArr(array);
}