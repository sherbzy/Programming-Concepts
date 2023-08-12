/*CSCI 261 Assignment 2 - Triangles == Three Times The Fun
 *
 *Program Name:
 * Description: This program begins by requesting that the user enters 2 values that coordinate with the sides of a
 *  triangle. The code will then generate a random number for the third side of the triangle which creates a real triangle.
 *  Next, the program classifies the triangle as either acute, obtuse, or right. Finally, the perimeter and area of the
 *  triangle are calculated and outputted on the screen. If the user enters 3 values that do not create a real triangle,
 *  the program indicates this and ends.
 * Author: Lauren Sherburne
 * Date: September 4, 2019
 *
 */

//Include iostream, cstdlib, cmath, ctime and use namespace std
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    //Create variables to hold the measurements for each side of the triangle.
    double sideOne;
    double sideTwo;
    double sideThree;
    int maxThree;
    int minThree;

    //Create variables to helps with classification of the triangle.
    double a;
    double b;
    double c;
    const double TOLERANCE = 0.0001;

    //Create variables for perimeter and area of the triangle.
    int trianglePerimeter;
    double s;
    double withinSquareRootArea;
    double triangleArea;

    //The following requests that the user enters values for 2 sides of the triangle, then it uses the rand function to
    //generate a third side that creates a valid triangle.
    cout << "Hello there!" << endl;
    cout << "Please enter your triangle's three side measurements below:" << endl;
    cout << "Side one: " << endl;
    cin >> sideOne;
    cout << "Side two: " << endl;
    cin >> sideTwo;


    srand(time(0));
    rand();
    maxThree = sideOne + sideTwo;
    minThree = abs(sideOne - sideTwo);
    sideThree = rand() % (maxThree - minThree + 1) + minThree;
    cout << "Side three: " << sideThree << endl;


    //The code below determines if the triangle is a real triangle or not.
    if ((sideOne + sideTwo > sideThree) && (sideOne + sideThree > sideThree) && (sideTwo + sideThree > sideOne)) {
        if ((sideOne == 0) || (sideTwo == 0) || (sideThree == 0)) {
            cout << "Error: your values do not make a real triangle since one side is equal to zero. Please try again."
                 << endl;
            return 0;
        } else {
            cout << "Your values make a real triangle!" << endl;
        }
        cout << endl;
    } else {
        cout << "Error: your values do not make a real triangle. Please try again." << endl;
        return 0;
    }


    //Using if statements, classify the sides of the triangle based on length. Longest side is c, smallest side is a, and
    //the middle length side is b.
    if ((sideOne >= sideTwo) && (sideOne >= sideThree)) {
        c = sideOne;
    //cout << "c = " << c << endl;
        if (sideTwo > sideThree) {
            b = sideTwo;
            //cout << "b = " << b << endl;
            a = sideThree;
            //cout << "a = " << a << endl;
            //s1 > s2 > s3
        } else {
            b = sideThree;
            //cout << "b = " << b << endl;
            a = sideTwo;
            //cout << "a = " << a << endl;
            //s1 > s3 > s2
        }
    } else if (sideTwo > sideOne && sideTwo > sideThree) {
        c = sideTwo;
        //cout << "c = " << c << endl;
        if (sideOne > sideThree) {
            b = sideOne;
            //cout << "b = " << b << endl;
            a = sideThree;
            //cout << "a = " << a << endl;
            //s2 > s1 > s3
        } else {
            b = sideThree;
            //cout << "b = " << b << endl;
            a = sideOne;
            //cout << "a = " << a << endl;
            //s2 > s3 > s1
        }
    } else {
        c = sideThree;
        //cout << "c = " << c << endl;
        if (sideOne > sideTwo) {
            b = sideOne;
            //cout << "b = " << b << endl;
            a = sideTwo;
            //cout << "a = " << a << endl;
            //s3 > s1 > s2
        } else {
            b = sideTwo;
            //cout << "b = " << b << endl;
            a = sideOne;
            //cout << "a = " << a << endl;
            //s3 > s2 > s1
        }
    }



//Next we need to classify the triangle itself as right, acute, or obtuse.
        cout << "Your triangle is classified as: " << endl;

    //The following code tests to see if the triangle is a right, acute, or obtuse.
    if (((pow(a, 2) + pow(b, 2) - pow(c, 2)) <= TOLERANCE) && (pow(a, 2) + pow(b, 2) - pow(c, 2)) >= -0.5) {
        cout << "a right triangle." << endl;
    } else if (pow(a, 2) + pow(b, 2) > pow(c, 2)) {
        cout << "an acute triangle." << endl;
    } else if (pow(a,2) + pow(b,2) < pow(c,2)) {
        cout << "an obtuse triangle." << endl;
    } else {
        cout << "I don't really know..." << endl;
    }


//Using a,b,and c, the program calculates and outputs the triangle's perimeter.
    cout << endl;
    trianglePerimeter = a + b + c;
    cout << "Your triangle's perimeter is: " << trianglePerimeter << endl;

//Using Heron's formula, the program calculates and outputs the triangle's area.
    cout << endl;
    s = trianglePerimeter/2;
    withinSquareRootArea = s * (s - a) * (s - b) * (s - c);
    withinSquareRootArea = (pow(s,2) - (s * a))  * (pow(s,2) - (s * b)) * (pow(s,2)- (s * c));
    triangleArea =  sqrt (sqrt ((withinSquareRootArea)));
    cout << "Your triangle's area is: " << triangleArea << endl;

    return 0; //signals to the operating system that the program ended ok
}
