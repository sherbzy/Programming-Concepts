/* CSCI 261 Lab 1C: GEOMETRIC CALCULATIONS
 * Program Name: Area of Rectangular Prism Calculator
 * Author: Lauren Sherburne
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream>// For cin, cout, etc.


// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

    /******** MODIFY OR INSERT CODE BELOW HERE ********/

    int length;
    int width;
    int height;
    int volume;
    double radius;
    double area;
    const double PI = 3.14159;
    const int FREE_FALL_ACCELERATION = 10;

//User must enter a whole number which indicates length, width, and height of the box.

cout << "Enter the dimensions of your box" << endl;
cout << "Enter length..." << endl;
cin >> length ;
cout << "Enter width..." << endl;
cin >> width ;
cout << "Enter height..." << endl;
cin >> height ;

// Volume of a box is length times width times height.
    volume = length * width * height;

cout << "The volume of your box is: " << endl;
cout << volume << endl;

//User must enter a number which indicates the radius of the circle.

cout << "Enter the radius of your circle..." << endl;
cin >> radius ;

//Area of a circle is pi times the radius squared.
area = PI * (radius*radius) ;

cout << "The area of your circle is:" << endl;
cout << area << endl;

    /******** MODIFY OR INSERT CODE ABOVE HERE ********/

    return 0; // signals the operating system that our program ended OK.
}