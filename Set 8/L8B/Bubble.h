//
// Created by Lauren Sherburne on 11/22/2019.
//

#ifndef SFML_TEMPLATE_BUBBLE_H
#define SFML_TEMPLATE_BUBBLE_H
#include <SFML/Graphics.hpp>
using namespace sf;


class Bubble {
public:
    //declare a default random bubble function
    void bubble();
    //declare setter functions for each of the private variable
    void setBubbleShape (int r, int b, int g, float radius, double xPos, double yPos);
    void setXdirection (double x);
    void setYdirection (double y);

    //declare a getter function for each of the private variables
    CircleShape getBubbleShape ();
    double getXvalue ();
    double getYvalue ();

    //declare a function called updatePosition to add the direction values to the circle's position
    void updatePosition ();

private:
    //declare a circle for the bubble's shape as well as doubles for its x and y position
    CircleShape _bubbleShape;
    double _xDir;
    double _yDir;
};


#endif //SFML_TEMPLATE_BUBBLE_H
