//
// Created by Lauren Sherburne on 11/8/2019.
//

#ifndef L7C_GODZILLA_H
#define L7C_GODZILLA_H
#include <string>
using namespace std;


class Godzilla {
public:
    //declare a string for the name, a double for the health, and a double for the power
    string godzillaName;
private:
    double _godzillaHealth;
    double _godzillaPower;

    //add member functions
public:
    Godzilla();
    void setName(string name);

    //setter functions for health and power
    void setHealth(double h);
    void setPower(double p);

    //getter functions for health and power
    double getHealth();
    double getPower();
};

#endif //L7C_GODZILLA_H
