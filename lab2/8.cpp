#include <iostream>


void ReverseArrayRows(int arr[4][6]) { 
    int size=6;
    int temp;
    int j;
    for(int k=0;k<4;k++){
        j=0;
        for(int i=size-1;i>(size/2)-1;i--){
            temp=arr[k][j];
            arr[k][j]=arr[k][i];
            arr[k][i]=temp;
            j++;
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
    ReverseArrayRows(array);
    printArr(array);
}