/* CSCI 261 Assignment 7 - Stargate
 *
 * Program Name: Stargate
 * Description: Using the ModifiedStars.txt file, the program draws a collection of stars in the SFML window.
 *
 *
 * Author: Lauren Sherburne
 * Date: November 8, 2019
 *
 * Using Skip Day 3 of 5
 * Remaining Skip Days: 2
 *
*/

#include <fstream>
#include <vector>
#include <iostream>                             // for standard input/output
using namespace std;                            // using the standard namespace

#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
using namespace sf;                             // using the sf namespace

int main() {

    // create a RenderWindow object
    // specify the size to be 640x640
    // set the title to be "SFML Example Window"
    RenderWindow window( VideoMode(640, 640), "SFML Example Window" );

    //********************************************
    //  PLACE ANY FILE INPUT PROCESSING BELOW HERE
    //********************************************

    //open file stream
    ifstream starData("ModifiedStars.txt");

    //check for error
    if (starData.fail()) {
        cerr << "Error opening file to read." << endl;
        return -1;
    }

    //********************************************
    //  PLACE ANY FILE INPUT PROCESSING ABOVE HERE
    //********************************************

    // while our window is open, keep it open
    // this is our draw loop
    while( window.isOpen() ) {
        window.clear( Color::Black );           // clear the contents of the old frame
                                                // by setting the window to black

        //****************************************
        //  ADD ALL OF OUR DRAWING BELOW HERE
        //****************************************

        const double BRIGHTEST_STAR = 8.0;
        double xValue;
        double yValue;
        double starBrightness;
        CircleShape star;
        star.setRadius(2);

        //using a loop, draw all of the stars in their respective positions;
        while (!starData.eof()) {
            //input data
            starData >> xValue;
            starData >> yValue;
            starData >> starBrightness;

            cout << xValue << endl;
            cout << yValue << endl;
            cout << starBrightness << endl;

            //determine the shade of gray of the star
            int shadeOfGray = (int)( ( 255.0 * starBrightness) / BRIGHTEST_STAR );

            //draw each star using the circle drawing shape
            star.setFillColor( Color(shadeOfGray, shadeOfGray, shadeOfGray));
            star.setPosition(Vector2f(xValue, yValue));
            window.draw(star);
        }

        //close file
        starData.close();

        //****************************************
        //  ADD ALL OF OUR DRAWING ABOVE HERE
        //****************************************

        window.display();                       // display the window

        //****************************************
        // HANDLE EVENTS BELOW HERE
        //****************************************
        Event event;
        while( window.pollEvent(event) ) {      // ask the window if any events occurred
            if( event.type == Event::Closed ) { // if event type is a closed event
                                                // i.e. they clicked the X on the window
                window.close();                 // then close our window
            }
        }
    }

    return EXIT_SUCCESS;                        // report our program exited successfully
}