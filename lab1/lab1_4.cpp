// Student Name: Reanielle Broas
// Student ID: C00296913
// Lab4 Binary to Decimal Converter
// This program converts a binary number to its decimal equivalent.

// Formula: decimal = dn * 2^n + dn-1 * 2^n-1 + ... + d1 * 2^1 + d0 * 2^0
// Reference: https://www.cuemath.com/numbers/binary-to-decimal/

#include <iostream>
using namespace std;

int main(){
    // initialise variables
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

        // Formula: lastDigit * 2^n
    }

    // display result
    cout << "Decimal equivalent: " << decimal << endl;

    return 0;
}