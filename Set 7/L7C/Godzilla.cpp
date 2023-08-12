//
// Created by Lauren Sherburne on 11/8/2019.
//

#include "Godzilla.h"
#include <string>
#include <iostream>
using namespace std;


Godzilla::Godzilla() {
    godzillaName = "Godzilla";
    godzillaHealth = (rand() % 51) + 50;
    godzillaPower = (rand() % 16) + 10;
}

void Godzilla::setValues (string &name, double &health, double &power) {
    cout << "Please enter the name of your mechagodzilla:" << endl;
    cin >> name;

    cout << "Please enter " << name << "'s health value (an integer between 50 and 100 inclusive):" << endl;
    cin >> health;
    if (health < 1) {
        health = (rand() % 51) + 50;
    }

    cout << "Please enter " << name << "'s power value (an integer between 10 and 25 inclusive):" << endl;
    cin >> power;
    if (power < 1) {
        power = (rand() % 16) + 10;
    }
}

