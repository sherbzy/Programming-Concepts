/* CSCI 261 Lab 6B - Polar to Cartesian
 *
 * Program Name: Polar to Cartesian
 * Description: This program asks the user if they want to convert polar to cartesian coordinates or vice versa. Then,
 *              the program computes the values that the user wants and outputs them to the user.
 *
 *
 * Author: Lauren Sherburne
 * Date: October 27 2019
 *
 *
 */

#include <iostream>
#include <cmath>
using namespace std;


//Declare a pass by reference function called polarToCartesian that converts polar coordinates to cartesian coordinates
void polarToCartesian (const double r, const double thetaValue, double &x, double &y) {
    x = r * (cos(thetaValue));
    y = r * (sin(thetaValue));
}


//Declare a pass by reference function called cartesianToPolar that converts cartesian coordinates to polar coordinates
void cartesianToPolar (const double x, const double y, double &r, double &thetaValue) {
    const double PI = 3.1415927;
    r = sqrt((pow (x, 2)) + (pow (y, 2)));
    thetaValue = (atan((y / x))) * (180/PI);
}



int main() {
    //Declare variables for the user's choice, x coordinate, y coordinate, radius, and theta
    int userChoice;
    double xCoord;
    double yCoord;
    double radius;
    double theta;

    //Ask the user which data type the would like to enter, polar or cartesian
    cout << "Would you like to convert" << endl;
    cout << "1. Polar to Cartesian (r, theta) -> (x, y)" << endl;
    cout << "or" << endl;
    cout << "2. Cartesian to Polar (x, y) -> (r, theta)" << endl << endl;
    cout << "Please enter \"1\" or \"2\"" << endl;

    cin >> userChoice;

    //If the user chose to convert polar to cartesian...
    if (userChoice == 1) {

        //input the radius and angle theta
        cout << "Please enter the radius: " << endl;
        cin >> radius;
        cout << "Please enter the angle value in degrees: " << endl;
        cin >> theta;

        //calculate the x and y coordinates using the polarToCartesian function
        polarToCartesian(radius, theta, xCoord, yCoord);

        //output the x and y coordinate values
        cout << "x = " << xCoord << endl;
        cout << "y =  " << yCoord << endl;

    } else if (userChoice == 2) {    //If the user chose to convert cartesian to polar...

        //input the x and y coordinates
        cout << "Please enter the x-coordinate value: " << endl;
        cin >> xCoord;
        cout << "Please enter the y-coordinate value: " << endl;
        cin >> yCoord;

        //calculate the radius and angle theta using the cartesianToPolar function
        cartesianToPolar(xCoord, yCoord, radius, theta);

        //output the radius and theta values
        cout << "The radius is " << radius << " units." << endl;
        cout << "The angle is " << theta << " degrees." << endl;

    } else {    //If the user does not enter 1 or 2...
        cout << "I'm sorry, but you're entry was invalid." << endl;
    }

    //return 0 signals the operating system that our program ended ok.
    return 0;
}
