/*CSCI 261 Lab 5DE - Vector Input/Output
 *
 *
 * Program Name: Vector Input/Output
 * Author: Lauren Sherburne
 *
 * Description: The program asks the user to input non negative integers which inputs them into a vector. Then, it
 *              prints how many numbers the user entered and the order they entered them in. The program creates a
 *              sorted version of the user's input and prints the smallest number, largest number, first number, and
 *              last number before exiting.
 *
 *
 * Date: October 23, 2019
 *
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    //Declare a variable for the user's input
    int userInput;

    //Welcome the user and give instructions about input
    cout << "Hey! Witness my first array mojo!" << endl;
    cout << "Enter as many non-negative numbers as you'd like and I will tell you what they are." << endl;
    cout << "When you wish to be done, enter -1 to stop entering numbers." << endl;


    //Declare a vector and an int for it's length
    vector <int> myIntegerVector;
    int vectorLength = 0;

    //Using a do while loop, prompt the user for each number and then assign the entered number to the ith value
    // in the vector
    do {
        cout << "Your number is: ";
        cin >> userInput;
        myIntegerVector.push_back(userInput);
        vectorLength++;

    } while (userInput != -1);
    myIntegerVector.pop_back();
    vectorLength--;
    cout << endl << endl;

    //Print the vector size and the numbers within the vector
    cout << "So awesome! You entered " << vectorLength << " numbers." << endl;
    cout << "The numbers are: ";
    for (int i = 0; i < vectorLength; i++) {
        cout << myIntegerVector.at(i) << " ";
    }
    cout << endl;

    //Sort the numbers and place them in a sorted vector using selection sort
    vector <int> sortedVector(vectorLength);
    for (int i = 0; i < vectorLength; i++) {
        sortedVector.at(i) = myIntegerVector.at(i);
    }

    sort(sortedVector.begin(), sortedVector.end());

    //for (int i = 0; i < vectorLength; i++) {
    //    cout << sortedVector.at(i) << endl;
    //}

    //Print the smallest number, the largest number, the first number, and the last number
    cout << "The smallest number is: " << sortedVector.at(0) << endl;
    cout << "The largest number is: " << sortedVector.at(sortedVector.size() - 1) << endl;
    cout << "The first number is: " << myIntegerVector.at(0) << endl;
    cout << "The last number is : " << myIntegerVector.at(myIntegerVector.size() - 1) << endl;
    cout << endl << endl;
    cout << "Have a nice day!" << endl;
    cout << "Gaze at my awesome." << endl;

    //return 0 signals the operating system that the program ended ok
    return 0;
}