/*CSCI 261 Lab 4A - RPS: Multigame
 *
 *
 * Program Name: Human vs. Computer Rock, Paper, Scissors
 * Author: Lauren Sherburne
 *
 * Description: When run, the program asks the user to choose either rock, paper or scissors. Then, it uses random
 * numbers to generate a response and outputs it. The computer then tells whether the human player won, lost or tied,
 * and asks if the user would like to play again. If yes, it loops to the beginning of the game and if no, it exits the
 * program.
 *
 * Date: September 30, 2019
 */

//Include iostream library, cmath, ctime, cstdlib, and standard namespace.
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int main() {
    //Define variable for what the player chooses and what the computer chooses (R, P, S)
    char playerChoice;
    short int randNumber;
    short int computerChoice;
    char playerResponse;
    int gamesWon = 0, gamesLost = 0, gamesTied = 0;

    do {
        //Introduce the player to the game and request for input of R, P, or S
        cout << "Welcome one and all to a round of Rock, Paper, and Scissors! (Enter R, P, or S)" << endl;
        cout << "Player 1: ";
        cin >> playerChoice;
        cout << " " << endl;

        //Output the player's choice as Rock, Paper or Scissors
        if (playerChoice == 'R' || playerChoice == 'r') {
            cout << "Player Chooses: Rock" << endl;
        } else if (playerChoice == 'S' || playerChoice == 's') {
            cout << "Player Chooses: Scissors" << endl;
        } else if (playerChoice == 'P' || playerChoice == 'p') {
            cout << "Player Chooses: Paper" << endl;
        }

        //Use a rand function to generate a random number between 0 and 2 (inclusive) and assign it to computerChoice
        srand(time(0));
        rand();
        computerChoice = rand() % (2 - 0) + 0;


        //Using the random number found above, discern whether the computer chose Rock, Paper, or Scissors and print the
        //computer's choice to the screen
        if (computerChoice == 0) {
            cout << "Computer Chooses: Rock" << endl;
            cout << endl;
        } else if (computerChoice == 1) {
            cout << "Computer Chooses: Scissors" << endl;
            cout << endl;
        } else if (computerChoice == 2) {
            cout << "Computer Chooses: Paper" << endl;
            cout << endl;
        }

        //The following code determines who won the game and output the result.

        //First identify if there is a tie game.
        if (computerChoice == 0 && (playerChoice == 'R' || playerChoice == 'r')) {
            cout << "Rock does not beat Rock. Tie game." << endl;
            gamesTied = gamesTied + 1;
        }
        if (computerChoice == 1 && (playerChoice == 'S' || playerChoice == 's')) {
            cout << "Scissors does not beat Scissors. Tie game." << endl;
            gamesTied = gamesTied + 1;
        }
        if (computerChoice == 2 && (playerChoice == 'P' || playerChoice == 'p')) {
            cout << "Paper does not beat Paper. Tie game." << endl;
            gamesTied = gamesTied + 1;
        }

        //Then, identify if the computer won.
        if (computerChoice == 0 && (playerChoice == 'S' || playerChoice == 's')) {
            cout << "Rock beats Scissors." << endl;
            cout << "Computer wins!" << endl;
            gamesLost = gamesLost + 1;
        }
        if (computerChoice == 1 && (playerChoice == 'P' || playerChoice == 'p')) {
            cout << "Scissors beats Paper" << endl;
            cout << "Computer wins!" << endl;
            gamesLost = gamesLost + 1;
        }
        if (computerChoice == 2 && (playerChoice == 'R' || playerChoice == 'r')) {
            cout << "Paper beats Rock." << endl;
            cout << "Computer wins!" << endl;
            gamesLost = gamesLost + 1;
        }

        //Finally, identify if the human player won.
        if (computerChoice == 0 && (playerChoice == 'P' || playerChoice == 'p')) {
            cout << "Paper beats Rock." << endl;
            cout << "You win!" << endl;
            gamesWon = gamesWon + 1;
        }
        if (computerChoice == 1 && (playerChoice == 'R' || playerChoice == 'r')) {
            cout << "Rock beats Scissors." << endl;
            cout << "You win!" << endl;
            gamesWon = gamesWon + 1;
        }
        if (computerChoice == 2 && (playerChoice == 'S' || playerChoice == 's')) {
            cout << "Scissors beats Paper." << endl;
            cout << "You win!" << endl;
            gamesWon = gamesWon + 1;
        }



        //ask the player if they want to play again
        cout << "Do you want to play again? (Y/N)" << endl;
        cin >> playerResponse;

    } while (playerResponse == 'Y' || playerResponse == 'y');

    //thank the player for playing and list how many games they won, lost, and tied.
    cout << "Thank you for playing!" << endl;
    cout << "You won " << gamesWon << " game(s), lost " << gamesLost << " game(s), and tied " << gamesTied << " game(s)" << endl;

//return 0 signals the operating system that our program ended ok
    return 0;
}