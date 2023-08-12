/* CSCI 261 L8B - Bouncing Bubble
 *
 *
 * Program Name: Bouncing Bubble
 * Description: The program uses the class "bubble" and sfml graphics to draw a bubble in the sfml window. Then, it
 *              continuously changes the position of the bubble so that it moves across the screen, yet stays within
 *              the drawing window. The effect makes the bubble appear to bounce off of any edge that it touches.
 *
*/
#include <iostream>                             // for standard input/output
using namespace std;                            // using the standard namespace

#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
using namespace sf;                             // using the sf namespace

#include <ctime>
#include "Bubble.h"

int main() {
    //seed rand function
    srand (time(0));
    rand();
    rand();

    //Create a bubble using the bubble class and set its starting values
    Bubble myBubble;
    myBubble.setXdirection(0.1);
    myBubble.setYdirection(0.2);
    myBubble.setBubbleShape(255, 255, 255, 35.5, 50, 5);

    // display "Hello, World!" -- this still appears in our Run terminal as before
    cout << "Testing, testing 1, 2, 3..." << endl;


    // create a renderwindow object size 640x640 and set the title to be "SFML Window"
    RenderWindow window( VideoMode(640, 640), "SFML Window" );

    // while our window is open, keep it open
    // this is our draw loop
    while( window.isOpen() ) {
        window.clear( Color::Black );           // clear the contents of the old frame
                                                // by setting the window to black
        window.draw(myBubble.getBubbleShape());
        myBubble.updatePosition();

        window.display();                       // display the window

        //event to close the drawing window
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