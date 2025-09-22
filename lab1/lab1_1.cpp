// Student Name: Reanielle Broas
// Student ID: C00296913
// Lab1 Leap Year Checker Program
// This program checks if a given year is a leap year or not.

#include <iostream>
using namespace std;

int main() {
    // initialise variables
    int year;

    // get user input
    cout << "Enter a year: ";
    cin >> year;

    // check if the year is a leap year and display result
    if (year % 4 == 0){
        if (year % 100 == 0){
            if (year % 400 == 0){
                cout << year << " is a leap year." << endl;
            }
            else{
                cout << year << " is not a leap year." << endl;
            }
        } 
        else{
            cout << year << " is a leap year." << endl;
        }
    } 
    else{
        cout << year << " is not a leap year." << endl;
    }

    return 0;
}