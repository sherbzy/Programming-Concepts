/*CSCI 261 Lab 5B - Matrix Transposition
 *
 *
 * Program Name: Matrix Calculator
 * Author: Lauren Sherburne
 *
 * Description: When run, the program asks the user to enter values into a two dimensional matrix with "numRows" rows
 *              and "numCols" columns. Then, it outputs the user's matrix, calculates the transpose of the matrix, and
 *              print's the matrix's transpose.
 *
 * Date: October 21, 2019
 *
*/

#include <iostream>
using namespace std;

int main() {
    //Define variables for rows, columns, and declare array and transpose matrix
    int numRows = 4;
    int numCols = 3;
    int userInputMatrix[numRows][numCols];
    int transposedMatrix [numCols][numRows];

    //Welcome user and prompt input
    cout << "Welcome to the Matrix Calculator!" << endl;
    cout << "Please enter a " << numRows << "x" << numCols << " matrix..." << endl;

    //Use for loops to put the user's input in the correct positions in the two dimensional array
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << "Enter Row " << i + 1 << " Column " << j + 1 << ": ";
            cin >> userInputMatrix[i][j];
        }
        cout << endl;
    }

    //Print user's matrix
    cout << "The matrix you entered is: " << endl;

    for (int i = 0; i < numRows; i++) {
        cout << "[" << "   ";
        for (int j = 0; j < numCols; j++) {
            cout << userInputMatrix[i][j] << "   ";
        }
        cout << "]" << endl;
    }
    //Calculate the transpose of the matrix
    for (int i = 0; i < numCols; i++) {
        for (int j = 0; j < numRows; j++) {
            transposedMatrix[i][j] = userInputMatrix[j][i];
        }
        cout << endl;
    }


    //Print the transpose of the matrix
    cout << "The transpose of the matrix is: " << endl;

    for (int i = 0; i < numCols; i++) {
        cout << "[" << "   ";
        for (int j = 0; j < numRows; j++) {
            cout << transposedMatrix[i][j] << "   ";
        }
        cout << "]" << endl;
    }

    cout << "Have a nice day!" << endl;

    //Return 0 signals the operating system that our program ended ok.
    return 0;
}