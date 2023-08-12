/* CSCI 261 Assignment 8 - Bouncing Bubble
 *
 *
 * Program Name: Bouncing Bubble
 * Description: The program uses the class "bubble" and sfml graphics to draw five bubbles in the sfml window with
 *              random color, speed, and starting position values. Then, it continuously changes the position of the
 *              bubbles so that they moves across the screen, yet stay within the drawing window. The effect makes
 *              the bubbles appear to bounce off of any edge that they touch.
 *
*/
#include <iostream>                             // for standard input/output
using namespace std;                            // using the standard namespace

#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
using namespace sf;                             // using the sf namespace

//include ctime and vector libraries as well as bubble.h file
#include <ctime>
#include <vector>
#include "Bubble.h"

int main() {
    //seed rand function
    srand (time(0));
    rand();
    rand();

    //declare variables to help control the drawing loop speed
    Clock frameRateClock;
    const float FRAME_RATE = 5000.0;

    //Create a vector of five bubbles using the bubble class and set its starting values
    vector <Bubble> myBubble;
    myBubble.assign(5, Bubble());
    for (int i = 0; i < myBubble.size(); i++) {
        //Bubble tempBubble = myBubble->at(i);
        cout << i << endl;
        myBubble.at(i).setXdirection((rand() % 26) / 10.0);
        cout << "x: " << myBubble.at(i).getXvalue() << endl;
        myBubble.at(i).setYdirection((rand() % 26)/ 10.0);
        cout << "y: " << myBubble.at(i).getYvalue() << endl;
        myBubble.at(i).setBubbleShape(rand() % 256, rand() % 256, rand() % 256, ((rand() % 401) + 100) / 10, (rand() % 301 + 100), (rand() % 301 + 100));
    }

    //add a counter to keep track of the number of bubbles on screen
    int numBubbles = myBubble.size();

    // display "Hello, World!" -- this still appears in our Run terminal as before
    cout << "Testing, testing 1, 2, 3..." << endl;


    // create a renderwindow object size 640x640 and set the title to be "SFML Window"
    RenderWindow window( VideoMode(640, 640), "SFML Window" );

    // while our window is open, keep it open
    // this is our draw loop
    while( window.isOpen() ) {
        window.clear( Color::Black );           // clear the contents of the old frame
        // by setting the window to black
        window.draw(myBubble.at(0).getBubbleShape());
        for (int i = 0; i < myBubble.size(); i++) {
            //Bubble tempBubble = myBubble->at(i);
            window.draw(myBubble.at(i).getBubbleShape());
            myBubble.at(i).updatePosition();
        }


        window.display();                       // display the window

        //event to close the drawing window
        Event event;
        while( window.pollEvent(event) ) {      // ask the window if any events occurred
            switch (event.type) {
                //if event type is a closed event then close the window
                case Event::Closed:
                window.close();
                break;

                //if the user left clicks in the sfml window, add another bubble at the point that they clicked
                case Event::MouseButtonReleased:
                    if (event.mouseButton.button == Mouse::Left) {
                        Bubble newBubble;
                        newBubble.setBubbleShape(rand() % 256, rand() % 256, rand() % 256,((rand() % 401) + 100) / 10, event.mouseButton.x, event.mouseButton.y);
                        myBubble.push_back(newBubble);
                        myBubble.at(numBubbles).setXdirection((rand() % 26) / 10.0);
                        myBubble.at(numBubbles).setYdirection((rand() % 26) / 10.0);
                        numBubbles += 1;
                    }

                 //if the user presses d or D, delete the last bubble in the vector of bubbles
                case Event::KeyPressed:
                    if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
                        if (myBubble.size() == 1) {
                            myBubble.at(0).bubbleDisappear();
                        } else {
                            myBubble.pop_back();
                            numBubbles -= 1;
                        }
                    }

            }
        }


        // wait before looping
        while( frameRateClock.getElapsedTime() < microseconds( FRAME_RATE ) ) ;
        frameRateClock.restart() ; // reset the timer
    }

    return EXIT_SUCCESS;                        // report our program exited successfully
}