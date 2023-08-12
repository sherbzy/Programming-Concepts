/* CSCI 261: Lab 4D - Input Paradigms to Compute Averages
 *
 * Program Name: Computing Averages
 * Description: First, the program asks the user if which file they want to open. If the user chooses to open the counter
 *              controlled file, then the program outputs the number of values first followed by the a list of the values
 *              and the average. However, if the user chooses to open the sentinel controlled file, the program lists
 *              the values in the file followed by the number of values and the average.
 *
 * Author: Lauren Sherburne
 * Date: 10/1/19
 */


//Use namespace standard and include the following libraries: iostream, ifstream
#include <iostream>
#include <fstream>
using namespace std;

int main() {
//Define variables for: user's file choice, number of values in the file, current value
    int userFileChoice;
    int numValues;
    double fileAverage;
    double currentValue;

//Ask the user which file they want to open.
    cout << "Hello! Which file would you like to open?" << endl;
    cout << "1. Counter Controlled" << endl;
    cout << "2. Sentinel Controlled" << endl;
    cin >> userFileChoice;

//Using an if statement, open the file that the user chooses.
    if (userFileChoice == 1){
        //open the counter controlled file
        //open file
        ifstream counterInput("counter_controlled.txt");

        //check for error
        if (counterInput.fail()) {
            cout << "Error. Could not open file to read." << endl;
            return -1;
        }

        //read data: number of values, loop to output each value, then calculate and output average
        counterInput >> numValues;
        cout << "There are " << numValues << " values in the file." << endl;
        cout << "The values in the file are: " << endl;

        for (int i = 0; i <= numValues; i++) {
            counterInput >> currentValue;
            cout << currentValue << endl;
            fileAverage += currentValue;
        }

        fileAverage = fileAverage/numValues;
        cout << "The average is: " << fileAverage << "." << endl;

        //close file
        counterInput.close();


    } else if (userFileChoice == 2) {
        //open the sentinel controlled file
        // open file
        ifstream sentinelInput("sentinel_controlled.txt");

        //check for error
        if (sentinelInput.fail()) {
            cout << "Error. Could not open file to read." << endl;
            return -1;
        }

        //read data
        cout << "The values in the file are:" << endl;

        while (currentValue != -9999) {
            sentinelInput >> currentValue;
            cout << currentValue << endl;
            fileAverage += currentValue;
            numValues = numValues + 1;
        }

        fileAverage = fileAverage / numValues;
        cout << "There are " << numValues << " values in the file." << endl;
        cout << "The average is " << fileAverage << "." << endl;

        //close file
        sentinelInput.close();
    } else {
        cout << "I'm sorry, you're input was not valid." << endl;
        return -1;
    }

//return 0 signals the operating system that the program ended ok.
    return 0;
}