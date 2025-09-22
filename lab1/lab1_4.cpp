// Student Name: Reanielle Broas
// Student ID: C00296913
// Lab4 Binary to Decimal Converter
// This program converts a binary number to its decimal equivalent.

// Formula: decimal = Σ (binary_digit * 2^position)

#include <iostream>
using namespace std;

int main(){
    //initalise variables
    int binary, decimal = 0, base = 1, lastDigit;

    // get user input
    cout << "Enter a binary number: ";
    cin >> binary;

    // convert binary to decimal
    while (binary > 0){
        lastDigit = binary % 10; // get the last digit
        binary = binary / 10; // remove the last digit
        decimal += lastDigit * base; // add to decimal
        base *= 2; // increase base by power of 2
    }

    // display result
    cout << "Decimal equivalent: " << decimal << endl;

    return 0;
}