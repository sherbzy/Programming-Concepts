//
// Created by Lauren Sherburne on 11/8/2019.
//

#include "Godzilla.h"
#include <string>
#include <iostream>
using namespace std;


Godzilla::Godzilla() {
    godzillaName = "Godzilla";
    _godzillaHealth = (rand() % 51) + 50;
    _godzillaPower = (rand() % 16) + 10;
}

//setter functions for health and power
void Godzilla::setHealth(double h) {
    if (h < 1) {
        _godzillaHealth = (rand() % 51) + 50;
    } else {
        _godzillaHealth = h;
    }
}
void Godzilla::setPower(double p) {
    if (p < 1) {
        _godzillaPower = (rand() % 16) + 10;
    } else {
        _godzillaPower = p;
    }
}

//getter functions for health and power
double Godzilla::getHealth() {
    return _godzillaHealth;
}

double Godzilla::getPower() {
    return _godzillaPower;
}

void Godzilla::setName (string name) {
    godzillaName = name;
}



