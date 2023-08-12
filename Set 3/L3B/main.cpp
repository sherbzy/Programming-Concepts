/*CSCI 261 Lab 3B - Math Worksheet Generator
 *
 * Program Name: Math Worksheet Generator
 * Description: The program creates mathworksheet.txt and prints its solutions to the screen. It begins by creating two
 * random decimal numbers within the range -100 and 100 inclusive. Then, it uses ofstream to output the values in the
 * following manner: A + B, A - B, A * B, and A / B. After the creation of the worksheet, the program reads the file
 * by using ifstream then prints the answers to the problems in the worksheet to the screen.
 *
 *
 * Author: Lauren Sherburne
 * Date: September 16, 2019
 *
 */


//include the following libraries: iostream, fstream, ctime and use namespace standard.
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
//Declare variables for the two random numbers, A and B
    double A;
    double B;

//Generate two random decimals within -100 and 100 inclusive and assign them to variables A and B
    //seed rand with time, then throw out the first value since it repeats itself
    srand(time(0));
    rand();

    //assign random decimals to A and B within -100 and 100
    A = rand() % 9000 - 1000;
    A = A/100;
    B = rand() % 9000 - 1000;
    B = B/100;

    //cout << "A = " << A << endl;
    //cout << "B = " << B << endl;

//using ofstream, create mathworksheet.txt with the following four math problems: A + B, A - B, A * B ,and A / B
    //open the file
    ofstream MathFileOut ("mathWorksheet.txt");

    //check for an error
    if (MathFileOut.fail()) {
        cerr << "Error opening file to write." << endl;
        return -1;
    }

    //write data
    MathFileOut << A << " + " << B << " = ?" << endl;
    MathFileOut << A << " - " << B << " = ?" << endl;
    MathFileOut << A << " * " << B << " = ?" << endl;
    MathFileOut << A << " / " << B << " = ?" << endl;

    //close the file
    MathFileOut.close();



// Declare two doubles to store A and B and declare variables for the four solutions
    double aValue;
    double bValue;
    double aPlusB;
    double aMinusB;
    double aTimesB;
    double aDivB;

// Declare characters to store the math sign, equal sign, and ?
    char mathAddSign;
    char mathSubSign;
    char mathMultSign;
    char mathDivSign;
    char equalSign;
    char questionMark;

// Open the file and read in A,B, and all other signs
    //Open file
    ifstream mathWorksheetInput ("mathWorksheet.txt");

    //Check for error
    if (mathWorksheetInput.fail()) {
        cerr << "Error opening file to read" << endl;
        return -1;
    }

    //Read input
    mathWorksheetInput >> aValue >> mathAddSign >> bValue >> equalSign >> questionMark;
    mathWorksheetInput >> aValue >> mathSubSign >> bValue >> equalSign >> questionMark;
    mathWorksheetInput >> aValue >> mathMultSign >> bValue >> equalSign >> questionMark;
    mathWorksheetInput >> aValue >> mathDivSign >> bValue >> equalSign >> questionMark;

    //Close file
    mathWorksheetInput.close();

//Solve the problems then cout all of the problems with their solutions
    aPlusB = aValue + bValue;
    aMinusB = aValue - bValue;
    aTimesB = aValue * bValue;
    aDivB = aValue / bValue;

    cout << aValue << " + " << bValue << " = " << aPlusB << endl;
    cout << aValue << " - " << bValue << " = " << aMinusB << endl;
    cout << aValue << " * " << bValue << " = " << aTimesB << endl;
    cout << aValue << " / " << bValue << " = " << aDivB << endl;

//return 0 signals the operating system that our program ended ok
    return 0;
}