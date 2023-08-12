/* CSCI 261 Lab 7C - Classes Part II: Protected Godzilla
 *
 *
 * Program Name: Protected Godzilla
 * Description: The program uses a class called godzilla to stimulate a fight between the user's and computer's
 *              godzillas. Within the class, each godzilla's health and power are private values so the program
 *              uses setter and getter functions to access these values from the main function. It creates the
 *              computer's "godzilla" with random health and power values then asks the user to input the name,
 *              health, and power of their "mechagodzilla". The program ends by printing the values of both monsters.
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

    //Declare variables for health and power and name;
    double health;
    double power;
    string name;

    //Create a mechagodzilla and allow the user to input name, health, and power values using the parameterized godzilla
    Godzilla mechagodzilla;
    cout << "For your mechagodzilla, please enter the following: " << endl;
    cout << "Please enter the name of your mechagodzilla:" << endl;
    cin >> name;
    Godzilla::setName(mechagodzilla.godzillaName);
    cout << "Please enter a health value (an integer between 50 and 100 inclusive):" << endl;
    cin >> health;
    Godzilla::setHealth(health);
    cout << "Please enter a power value (an integer between 10 and 25 inclusive):" << endl;
    cin >> power;
    Godzilla::setPower(power);


    //Output the values of godzilla and mechagodzilla
    cout << "Godzilla:" << endl;
    cout << "name: " << godzilla.godzillaName << endl;
    cout << "health: " << godzilla.getHealth() << endl;
    cout << "power: " << godzilla.getPower() << endl;

    cout << "Mechagodzilla:" << endl;
    cout << "name: " << mechagodzilla.godzillaName << endl;
    cout << "health: " << mechagodzilla.getHealth() << endl;
    cout << "power: " << mechagodzilla.getPower() << endl;

    //return 0 signals the operating system that our program ended ok
    return 0;
}