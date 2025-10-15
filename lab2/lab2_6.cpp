using namespace std;
#include <iostream>

int replaceBorder(int array[4][6]){
    // first row
    for(int j=0;j<6;j++){
        array[0][j]=-1;
    }

    // last row
    for(int j=0;j<6;j++){
        array[3][j]=-1;
    }
    
    // first column
    for(int i=0;i<4;i++){
        array[i][0]=-1;
    }

    // last column
    for(int i=0;i<4;i++){
        array[i][5]=-1;
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
        {0,0,3,1,3,4},
        {0,0,2,3,4,3},
        {0,0,1,3,3,2},
        {0,0,2,2,2,2}
    };
    replaceBorder(array);
    printArr(array);
}