#include <iostream>

int ReplaceWithMinusOne(int array[4][6]){
    int score=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){//usr this one for the 3 aswell just ad an extra score if the fourth is found !!!
            if(array[i][j]==array[i][j+1]&&array[i][j]==array[i][j+2]&&array[i][j]==array[i][j+3]){//checks the rows
                
                //score calculation
                if(array[i][j]==array[i][j+4]){
                    score+=array[i][j]+array[i][j+1]+array[i][j+2]+array[i][j+3]+array[i][j+4];
                }
                score+=array[i][j]+array[i][j+1]+array[i][j+2]+array[i][j+3];

                
                
            }
        }
        if(array[i][0]==array[i][1]&&array[i][0]==array[i][2]&&array[i][0]==array[i][3]){
            score+=array[i][0]+array[i][1]+array[i][2]+array[i][3];
        }
    }
    return score;
}
void printArr(int arr[4][6]){
    for(int i=0;i<4;i++){
        for(int j=0;j<6;j++){
            std::cout<<arr[i][j]<<", ";
        }
        std::cout<<std::endl;
    }

}
//we want to find any duplicates of 3 or more and add up what they are to get a score to return.
int main(){
    int array[4][6] = {
        {2, 3, 4, 2, 2, 0},
        {2, 78, 0, 12, 34, 56},
        {2, 2, 2, 2, 2, 2},
        {2, 8, 91, 40, 50, 60}
    };
    int score=ReplaceWithMinusOne(array);
    std::cout<<score<< " is the score"<<std::endl;

    printArr(array);
}