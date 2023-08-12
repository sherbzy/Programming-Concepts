/* CSCI 261 Lab 7A - SFML Drawing
 *
 * Program Name: Big Green Tractor
 * Description: The program uses SFML to create a graphic drawing within the window of a green tracto (Inspiration: Jason Aldean)
 *
 * Author: Lauren Sherburne
 * Date: November 6, 2019
 *
*/


#include <iostream>                             // for standard input/output
using namespace std;                            // using the standard namespace

#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
using namespace sf;                             // using the sf namespace

int main() {
    // display "Hello, World!" -- this still appears in our Run terminal as before
    cout << "Hello, World!" << endl;

    // create a RenderWindow object
    // specify the size to be 640x640
    // set the title to be "SFML Example Window"
    RenderWindow window( VideoMode(640, 640), "SFML Example Window" );


    // while our window is open, keep it open
    // this is our draw loop
    while( window.isOpen() ) {
        window.clear( Color::White);           // clear the contents of the old frame
                                                // by setting the window to white


        //First, draw a green rectangle for the tractor's cab
        RectangleShape rectangle;
        rectangle.setSize(sf::Vector2f(300, 100));
        rectangle.setOutlineColor(Color(35, 35, 35));
        rectangle.setOutlineThickness(2);
        rectangle.setFillColor(Color(29, 151, 20));
        rectangle.setPosition(50, 200);
        window.draw(rectangle);

        //Next, add a large back wheel
        CircleShape backWheel;
        backWheel.setFillColor(Color::Black);
        backWheel.setRadius(60);
        backWheel.setPosition(Vector2f(60, 240));
        window.draw(backWheel);

        CircleShape innerBackWheel;
        innerBackWheel.setFillColor(Color::Yellow);
        innerBackWheel.setRadius(45);
        innerBackWheel.setPosition(Vector2f(75, 255));
        window.draw(innerBackWheel);

        //Add a small front wheel
        CircleShape frontWheel;
        frontWheel.setFillColor(Color::Black);
        frontWheel.setRadius(27);
        frontWheel.setPosition(Vector2f(258, 298));
        window.draw(frontWheel);

        CircleShape innerFrontWheel;
        innerFrontWheel.setFillColor(Color::Yellow);
        innerFrontWheel.setRadius(15);
        innerFrontWheel.setPosition(Vector2f(270, 310));
        window.draw(innerFrontWheel);

        //Then, add a rectangular cab
        RectangleShape rectangleCab;
        rectangleCab.setSize(sf::Vector2f(175, 120));
        rectangleCab.setOutlineColor(Color(35, 35, 35));
        rectangleCab.setOutlineThickness(2);
        rectangleCab.setFillColor(Color(29, 151, 20));
        rectangleCab.setPosition(65, 78);
        window.draw(rectangleCab);

        //Draw windows on the cab of the tractor
        RectangleShape cabWindshield;
        cabWindshield.setSize(Vector2f(40, 100));
        cabWindshield.setOutlineColor(Color(35, 35, 35));
        cabWindshield.setOutlineThickness(2);
        cabWindshield.setFillColor(Color(81, 222, 222));
        cabWindshield.setPosition(200, 98);
        window.draw(cabWindshield);

        RectangleShape cabWindow;
        cabWindow.setSize(Vector2f(80, 100));
        cabWindow.setOutlineColor(Color(35, 35, 35));
        cabWindow.setOutlineThickness(2);
        cabWindow.setFillColor(Color(81, 222, 222));
        cabWindow.setPosition(110, 98);
        window.draw(cabWindow);

        //Finally, add an exhaust pipe
        RectangleShape exhaustPipe;
        exhaustPipe.setSize(Vector2f(20, 80));
        exhaustPipe.setFillColor(Color::Black);
        exhaustPipe.setPosition(300, 118);
        window.draw(exhaustPipe);

        window.display();                       // display the window
    }

    return EXIT_SUCCESS;                        // report our program exited successfully
}