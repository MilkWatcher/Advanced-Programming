// Student Name: Reanielle Broas
// Student ID: C00296913
// Lab3 Check whether a number is prime or not
// This program checks if a given number is prime or not.

#include <iostream>
using namespace std;

int main() {

    // initialise variables
    int num, i;
    bool isPrime = true;

    // get user input
    cout << "Enter a positive integer: ";
    cin >> num;

    // check if the number is prime
    if (num <= 1){
        isPrime = false;
    } 
    else{
        for (i = 2; i <= num / 2; ++i){
            if (num % i == 0){
                isPrime = false;
                break;
            }
        }
    }

    // display result
    if (isPrime){
        cout << num << " is a prime number." << endl;
    } 
    else{
        cout << num << " is not a prime number." << endl;
    }

    return 0;
}