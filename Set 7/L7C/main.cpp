/* CSCI 261 Lab 7C - Classes Part I: Godzilla
 *
 *
 * Program Name: Godzilla
 * Description: The program uses a class called godzilla to stimulate a fight between the user's and computer's
 *              godzillas. It creates the computer's "godzilla" with random health and power values then asks the user
 *              to input the name, health, and power of their "mechagodzilla". The program ends by printing the values
 *              of both monsters.
 *
 * Author: Lauren Sherburne
 * Date: November 8, 2019
 *
*/

#include <iostream>
#include <string>
#include <ctime>
#include "Godzilla.h"

int main() {
    //Seed the random function
    srand(time(0));
    rand();

    //Create a godzilla using the default constructor
    Godzilla godzilla;

    //Create a mechagodzilla and allow the user to input name, health, and power values using the parameterized godzilla
    Godzilla mechagodzilla;
    cout << "For your mechagodzilla, please enter the following: " << endl;
    mechagodzilla.setValues(mechagodzilla.godzillaName, mechagodzilla.godzillaHealth, mechagodzilla.godzillaPower);

    //Output the values of godzilla and mechagodzilla
    cout << "Godzilla:" << endl;
    cout << "name: " << godzilla.godzillaName << endl;
    cout << "health: " << godzilla.godzillaHealth << endl;
    cout << "power: " << godzilla.godzillaPower << endl;

    cout << "Mechagodzilla:" << endl;
    cout << "name: " << mechagodzilla.godzillaName << endl;
    cout << "health: " << mechagodzilla.godzillaHealth << endl;
    cout << "power: " << mechagodzilla.godzillaPower << endl;

    //return 0 signals the operating system that our program ended ok
    return 0;
}