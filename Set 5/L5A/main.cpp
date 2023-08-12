/*CSCI 261 Lab 5A - Array Input/Output
 *
 *
 * Program Name: Looping Through Arrays
 * Author: Lauren Sherburne
 *
 * Description: The program asks the user to input 15 integers and it inputs them into an array. Then, it prints out
 *              the contents of the array.
 *
 * Date: October 20, 2019
 *
 */

#include <iostream>
using namespace std;

int main() {
    //Declare a constant variable for the number of entries
    const int numEntries = 15;

    //Welcome the user and give instructions about input
    cout << "Hey! Witness my first array mojo!" << endl;
    cout << "Enter " << numEntries << " numbers and I will tell you what they are." << endl;

   //Declare an array of fifteen integers
   int myIntegerArray[numEntries];

   //Using a for loop, prompt the user for each number and then assign the entered number to the ith value in the array
   for (int i = 0; i < numEntries; i++) {
       cout << "Number " << (i + 1) << ": ";
       cin >> myIntegerArray[i];
       cout << endl;
   }

   cout << "So awesome!" << endl;

   //Using another for loop, output the ith value in the array
   cout << "The numbers are: ";
   for (int i = 0; i < numEntries; i++) {
       cout << myIntegerArray[i] << " ";
   }
   cout << endl;
   cout << "Have a nice day!" << endl;


   //return 0 signals the operating system that the program ended ok
    return 0;
}