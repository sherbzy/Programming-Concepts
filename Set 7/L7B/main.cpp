/* CSCI 261 Lab 7B - Starcraft
 *
 * Program Name: Starcraft
 * Description:
 *
 * Author: Lauren Sherburne
 * Date: November 7, 2019
 *
*/

//use namespace standard and include the following libraries: iostream, fstream, vector
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Declare global constants for height and width of the drawing window
const int HEIGHT = 640;
const int WIDTH = 640;


//write a function to modify the star's x-coordinate; double input and int output
int modifyX (double xStar) {
    return ((int)( ( xStar + 1 ) * WIDTH / 2 ));
}

//write a function to modify the star's y-coordinate; double input and int output
int modifyY (double yStar) {
    return ((int)( ( -yStar + 1 ) * HEIGHT / 2 ));
}

int main() {

    // Declare variables for x, y, z, star brightness, and the unused data from the file as well as a counter for the vectors
    double x;
    double y;
    double z;                               //unused value
    double starBright;                  //between 0.0 and 8.0
    int notUsed;
    int notNecessary;
    int counter = 0;

    // Declare a vector to store the modified x, modified y, and star brightness values
    vector <double> xModValues;
    vector <double> yModValues;
    vector <double> starBrightness;


    //Open input file stream
    ifstream inputStars("stars.txt");

    //Check for error
    if (inputStars.fail()) {
        cerr << "Error opening file to read data." << endl;
        return -1;
    }


    //Input data from the stars file using a while loop
    while (!inputStars.eof()) {
        //Assign data to x, y, z, and starbright values
        inputStars >> x;
        inputStars >> y;
        inputStars >> z;
        inputStars >> starBright;
        inputStars >> notUsed;
        inputStars >> notNecessary;

        if ((starBright > 0) && (starBright <= 8.0)) {
            //modify the x and y values, then place all values into their respective vectors
            xModValues.push_back(modifyX(x));
            yModValues.push_back(modifyY(y));
            starBrightness.push_back(starBright);
        }
    }

    //Close input file stream
    inputStars.close();

    //Test the above code
    //for (int i = 0; i < starBrightness.size(); i++) {
    //    cout << xModValues[i] << "\t" << yModValues[i] << "\t" << starBrightness[i] << endl;
    //}


//Write all modified star data to a new file called ModifiedStars.txt
    //Open file stream
    ofstream newStarData("ModifiedStars.txt");

    //Check for error
    if (newStarData.fail()) {
        cerr << "Error opening file to write data." << endl;
        return -1;
    }

    //Write data for x, y, and starBrightness to file
    for (int i = 0; i < xModValues.size(); i++) {
        newStarData << xModValues.at(i) << "\t" << yModValues.at(i) << "\t" << starBrightness.at(i) << endl;
    }

    //Close file
    newStarData.close();

    //return 0 signals the operating system that our program ended ok
    return 0;
}