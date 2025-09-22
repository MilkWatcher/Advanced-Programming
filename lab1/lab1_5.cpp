// Student Name: Reanielle Broas
// Student ID: C00296913
// Lab5 Convert chars 0-9 input to integers.
// Note: ASCII values are used in this program.

#include <iostream>
using namespace std;

int main()
{
    char inputChar;
    int convertedInt;

    cout << "Enter a character (0-9): ";
    cin >> inputChar;

    // convert char to int using ASCII values
    convertedInt = inputChar - '0';

    // check if the input is a valid digit
    if (convertedInt >= 0 && convertedInt <= 9){
        cout << "The integer value is: " << convertedInt << endl;
    }
    else{
        cout << "Invalid input. Please enter a character between 0 and 9." << endl;
    }

    return 0;
}