//
// Created by Lauren Sherburne on 11/22/2019.
//

#include "Bubble.h"
#include <SFML/Graphics.hpp>
using namespace sf;

//default random bubble creation function
void Bubble::bubble() {
    _bubbleShape.setFillColor(Color(rand() % 256, rand() % 256, rand() % 256));
    _bubbleShape.setRadius(rand() % 51 + 5);
    _bubbleShape.setPosition(rand() % 641, rand() % 641);

}


//write getter functions for private variables
CircleShape Bubble::getBubbleShape () {
    return _bubbleShape;
}
double Bubble::getXvalue () {
    return _xDir;
}
double Bubble::getYvalue () {
    return _yDir;
}


//write setter functions for each of the private variable
void Bubble::setBubbleShape (int r, int b, int g, float radius, double xPos, double yPos) {
    _bubbleShape.setFillColor(Color (r, g, b));
    _bubbleShape.setRadius(radius);
    _bubbleShape.setPosition(xPos, yPos);
}

void Bubble::setXdirection (double x) {
    _xDir = x;
}

void Bubble::setYdirection (double y) {
    _yDir = y;
}

//create a function called updatePosition to add the direction values to the circle's position
void Bubble::updatePosition () {
    _bubbleShape.setPosition((_bubbleShape.getPosition().x + _xDir), (_bubbleShape.getPosition().y + _yDir));
    if ((_bubbleShape.getPosition().x + (2 * _bubbleShape.getRadius()) >= 640) || (_bubbleShape.getPosition().x <= 0)) {
        setXdirection (-_xDir);
    }
    if ((_bubbleShape.getPosition().y + (2 * _bubbleShape.getRadius()) >= 640) || (_bubbleShape.getPosition().y <= 0)) {
        setYdirection (-_yDir);
    }
}

//create a function to set the fill color of the bubble to black
void Bubble::bubbleDisappear() {
    _bubbleShape.setFillColor(Color::Black);
}