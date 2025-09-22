// Student Name: Reanielle Broas
// Student ID: C00296913
// Lab2 Palindrome Checker Program
// This program checks if a given string is a palindrome or not.

#include <iostream>
using namespace std;

int main(){
    // initialise variables
    string str, revStr = "";

    // get user input
    cout << "Enter a string: ";
    cin >> str;

    // reverse the string
    for (int i = str.length() - 1; i >= 0; i--){
        revStr += str[i];
    }

    // check if the string is a palindrome
    if (str == revStr){
        cout << str << " is a palindrome." << endl;
    }
    else{
        cout << str << " is not a palindrome." << endl;
    }

    return 0;
}


