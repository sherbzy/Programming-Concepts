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
    double godzillaHealth;
    double godzillaPower;

    //add member functions
    Godzilla();
    void setValues (string &name, double &health, double &power);

};


#endif //L7C_GODZILLA_H
