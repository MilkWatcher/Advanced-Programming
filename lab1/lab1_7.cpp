// Student Name: Reanielle Broas
// Student ID: C00296913
// Lab 7 Nested loops output (2 for loops, 1 if and else statement)

// References: https://www.geeksforgeeks.org/c/pattern-programs-in-c/
/*
A
AA
AAA
AAAA
AAA
AA
A*/
#include <iostream>
using namespace std;

int main(){
    // initialise variables
    int rows = 4;
    int totalLines = 2 * rows - 1; // number of lines in the up-then-down pattern

    // outer loop: iterate each line. Inner loop: print the appropriate number of 'A's for that line.
    for (int i = 1; i <= totalLines; ++i) {

        // determine the number of 'A's to print on the current line
        int count;

        if (i <= rows){
            count = i; // ascending part
        }

        else{
             count = 2 * rows - i; // descending part
        }
        
        for (int j = 1; j <= count; ++j){
            cout << "A";
        }

        cout << endl;
        
    }
    return 0;
}