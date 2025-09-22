// Student Name: Reanielle Broas
// Student ID: C00296913
// Lab 6 Nested loops output (2 for loops)
/* utput:
    A
    AA
    AAA
    AAAA
*/

#include <iostream>
using namespace std;

int main(){
    //initialise variables
    int rows = 4;

    // outer loop for number of rows
    for (int i = 1; i <= rows; i++){
        
        // inner loop for number of columns
        for (int j = 1; j <= i; j++){
            cout << "A"; // print A
        }

        cout << endl; // move to next line after each row
    }
    return 0;
}