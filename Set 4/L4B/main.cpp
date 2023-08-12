/*CSCI 261 Lab 4B - Multiplication Tables
 *
 * Program Name: Multiplication Tables
 * Description: The user enters two integers between one and eleven and the program outputs a formatted times table.
 *
 *
 * Author: Lauren Sherburne
 * Date: September 30, 2019
 */


//Use standard namespace and include the following libraries: iostream, iomanip
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    //Define varibales for the multiplier (vertical), multiplicand (horizontal), and the current multiplier.
    int verticalLimit;
    int horizontalLimit;
    int currentMultiplier = 1;


    //Get value from the user for the multiplier (vertical) between 1 and 11 inclusive.
    cout << "Enter an integer between 1 and 11 for the multiplier:" << endl;
    cin >> verticalLimit;

    while (verticalLimit > 10 || verticalLimit < 2) {
        cout << "Sorry, but this was not a valid entry. Please try again:" << endl;
        cin >> verticalLimit;
    }

    //Get value from the user for the multiplicand (horizontal) between 1 and 11 inclusive.
    cout << "Enter an integer between 1 and 11 for the multiplicand:" << endl;
    cin >> horizontalLimit;

    while (horizontalLimit > 10 || horizontalLimit < 2) {
        cout << "Sorry, but this was not a valid entry. Please try again:" << endl;
        cin >> horizontalLimit;
    }

    //print the first line of the times table
    cout << "Here is your times table..." << endl;
    cout << "..";
    for (int i = 1; i <= horizontalLimit; i++) {
        cout << setfill ('.') << setw (4) << right << i;
    }
    cout << endl;

    //print the rest of the times table using loops

    for (int x = 0; x < verticalLimit; x++) {
        cout << setfill('.') << setw(2) << right << currentMultiplier;

        for (int i = 1; i <= horizontalLimit; i++) {
            cout << setfill('.') << setw(4) << right << (i * currentMultiplier);
        }
        currentMultiplier = currentMultiplier + 1;
        cout << endl;
    }

    return 0;
}