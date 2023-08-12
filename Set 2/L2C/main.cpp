/*CSCI 261 Lab 2C - Rock, Paper, Scissors
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
    short int computerChoice;

    //Introduce the player to the game and request for input of R, P, or S
    cout << "Welcome one and all to a round of Rock, Paper, and Scissors! (Enter R, P, or S)" << endl;
    cout << "Player 1: ";
    cin >> playerChoice;
    cout << " " << endl;

    //Output the player's choice as Rock, Paper or Scissors
    if (playerChoice == 'R' or playerChoice == 'r') {
        cout << "Player Chooses: Rock" << endl;
    } else if (playerChoice == 'S' or playerChoice == 's'){
        cout << "Player Chooses: Scissors" << endl;
    } else if (playerChoice == 'P' or playerChoice == 'p') {
        cout << "Player Chooses: Paper" << endl;
    }

    //Use a rand function to generate a random number between 0 and 2 (inclusive) and assign it to computerChoice
    srand(time(0));
    rand ();
    computerChoice == rand() % (3);

    //Using the random number found above, discern whether the computer chose Rock, Paper, or Scissors and print the
    //computer's choice to the screen
    if (computerChoice == 0) {
        cout << "Computer Chooses: Rock" << endl;
    } else if (computerChoice == 1) {
        cout << "Computer Chooses: Scissors" << endl;
    } else if (computerChoice == 2) {
        cout << "Computer Chooses: Paper" << endl;
    }


    return 0;
}