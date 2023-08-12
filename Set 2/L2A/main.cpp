/*CSCI 261 Lab 2A: MATH EQUATIONS
 *
 * Program Name: Solving Math Equations
 * Description: This program asks the user for the length and height of a triangle in inches then outputs the distance
 * of the triangle's hypotenuse in inches. Next, the user is asked to input the radius of a wire in millimeters
 * as well as the amount of force in Newtons being exerted on a cross section of the wire. The computer takes these
 * values and calculates the mechanical stress on the wire's cross section and outputs that value.
 * Author: Lauren Sherburne and Haley Vinton (pair programming)
 * Date: August 28, 2019
 */

//Include proper libraries
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    // Define variables for distance formula to find the length of the hypotenuse of a triangle where user inputs
    //length and height of triangle in inches
    double hypotenuseLength;
    double xLength;
    double yLength;

    //user inputs xLength and yLength for base and height of triangle respectively
    cout << "Welcome! Please enter two side lengths of any triangle. This program will find the length of the hypotenuse!" << endl;
    cout << "Enter length of x (in inches): " << endl;
    cin >> xLength;
    cout << "Enter length of y (in inches): " << endl;
    cin >> yLength;

    //Calculate the hypotenuseLength and output the value to the screen
    hypotenuseLength = sqrt((pow(xLength,2)) + (pow(yLength,2)));
    cout << "The length of the hypotenuse is: " << hypotenuseLength << " inches" << endl;

    //Make a space between the two equations
    cout << endl;

    // Define variables for second equation to find the mechanical stress on a cross section of wire, where one end is fixed,
    //and the other is being pulled on by the user with a certain amount of force in Newtons. The diameter is in millimeters.
    const double PI_VAL = 3.14159;
    double wireRadius;
    double wireForce;
    double wireArea;
    double wireSigma;

    // User inputs radius of wire
    cout << "Now, imagine you have a wire with a certain radius. The wire is fixed at one end, and you pull on it with a certain force." << endl <<"This program calculates the stress on a cross section of your wire!" << endl;
    cout << "Enter the radius of the wire (in millimeters): " << endl;
    cin >> wireRadius;

    //User inputs force with which the wire is being pulled on in Newtons
    cout << "Enter the amount of force exerted on wire (in Newtons): " << endl;
    cin >> wireForce;

    // Formula for unit area is A = pi*radius*radius
    wireArea = PI_VAL * pow(wireRadius,2);

    //The formula for mechanical stress is Sigma = force / unit area
    wireSigma =  wireForce /wireArea;

    //Output value for wireSigma
    cout << "The mechanical stress on a cross section of the wire is: " << wireSigma << " N/mm^2" << endl;

    //return 0 signals the operating system that the program ended successfully.
    return 0;
}
