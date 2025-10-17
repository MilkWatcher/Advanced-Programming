#include <iostream>

int FindMostFrequent(int array[4][6]) { 
    int mostFreq=array[0][0];
    int maxCount=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<6;j++){
            int option=array[i][j];
            int count=0;
            if(option==0||option==-1){
                continue;
            }
            for(int x=0;x<4;x++){
                for(int y=0;y<6;y++){
                    if(array[x][y]==option){
                        count++;
                    }
                }
            }
            if(maxCount<count){
                maxCount=count;
                mostFreq = option;
            }
        }
    }
    return mostFreq; 
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
    int count=FindMostFrequent(array);
    std::cout<<"The most frequent element is: "<<count<<std::endl;
    printArr(array);
}