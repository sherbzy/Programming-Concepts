/* CSCI 261 Lab 8C - Class Part IV: Cordial Godzilla vs. MechaGodzilla
 *
 *
 * Program Name: Protected Godzilla
 * Description: The program uses a class called godzilla to stimulate a fight between the user's and computer's
 *              godzillas. Within the class, each godzilla's health and power are private values so the program
 *              uses setter and getter functions to access these values from the main function. It creates the
 *              computer's "godzilla" with random health and power values then asks the user to input the name,
 *              health, and power of their "mechagodzilla". The program prints the values of both monsters and
 *              godzilla greets mechagodzilla before attacking him once. Then, mechagodzilla continually attacks
 *              godzilla until he is defeated.
 *
 * Author: Lauren Sherburne
 * Date: November 22, 2019
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
    mechagodzilla.setName(name);
    cout << "Please enter a health value (an integer between 50 and 100 inclusive):" << endl;
    cin >> health;
    mechagodzilla.setHealth(health);
    cout << "Please enter a power value (an integer between 10 and 25 inclusive):" << endl;
    cin >> power;
    mechagodzilla.setPower(power);

    cout << endl << endl;


    //Output the values of godzilla and mechagodzilla
    cout << "Godzilla:" << endl;
    cout << "name: " << godzilla.godzillaName << endl;
    cout << "health: " << godzilla.getHealth() << endl;
    cout << "power: " << godzilla.getPower() << endl;

    cout << "Mechagodzilla:" << endl;
    cout << "name: " << mechagodzilla.godzillaName << endl;
    cout << "health: " << mechagodzilla.getHealth() << endl;
    cout << "power: " << mechagodzilla.getPower() << endl;

    //Godzilla greets then attacks mechagodzilla once
    godzilla.greet (mechagodzilla);
    godzilla.attackGodzilla (mechagodzilla);

    //mechagodzilla attacks godzilla until godzilla has been vanquished
    int x;
    do {
        x = mechagodzilla.attackGodzilla(godzilla);
    } while (x != 0);

    //return 0 signals the operating system that our program ended ok
    return 0;
}