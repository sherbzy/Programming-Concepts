/*CSCI 261 Lab 2B - Rock, Paper, Scissors
 *
 *
 * Program Name: Human vs. Computer Rock, Paper, Scissors
 * Author: Lauren Sherburne
 * Description: When run, the program asks the user to choose either rock, paper or scissors. Then, it uses random
 * numbers to generate a response and outputs it. Finally, the computer tells whether the human player won, lost or tied
 * Date: September 3, 2019
 */

//Include iostream library, cmath, ctime, cstdlib, and standard namespace.
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;


int main() {
    //Define variable for what the player chooses and what the computer chooses (R, P, S)
    char playerChoice;
    short int randNumber;
    char computerChoice;

    //Introduce the player to the game and request for an input of Rock, Paper, or Scissors, then output the player's choice.
    cout << "Welcome one and all to a round of Rock, Paper, and Scissors! (Enter R, P, or S)" << endl;
    cout << "Player 1: ";
    cin >> playerChoice;
    cout << " " << endl;
    cout << "Player 1 Chooses: " << playerChoice << endl;

    //Use a rand function to generate a random number and print it as the computer's choice.
    srand(time(0));
    rand ();
    cout << "Computer Chooses: " << rand() % (3) << endl;



    return 0;
}