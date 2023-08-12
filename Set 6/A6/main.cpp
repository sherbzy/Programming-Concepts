/* CSCI 261 Assignment 6 - Yahtzee!
 *
 * Program Name: Yahtzee
 * Description: This program leads the user through a standard game of yahtzee.
 *
 * Author: Lauren Sherburne (and CSCI 261 Section B class)
 * Date: October 29, 2019
 *
*/


//use standard namespace and include the following libraries: iostream, ctime
#include <iostream>
#include <ctime>
using namespace std;

//Include the dice functions in the dice.h file
#include "dice.h"

//Include the yahtzee functions in the yahtzee.h file
#include "yahtzee.h"

//Create global constant for the amount of dice in one roll and declare an array of integers to hold the current die values
const int HAND_SIZE = 5;
int dieValues [HAND_SIZE];

int main() {
    //seed rand() with time to ensure all functions using the random number generator operate correctly
    srand(time(0));
    rand();


    //Declare an int for the number of rolls, a character for the user's input, and an array of bools for the user's die input
    int numRolls = 3;
    char userInput = 'Y';
    bool userDieChoice[HAND_SIZE];

    //Declare an int for the user's choice of scoring category and both an array and an int for the user's score
    int scoreCategory;
    int userScoreArray[13];
    int totalScore;

    //Declare an array to keep track of which score categories the user has used and an array to list the categories
    bool categoryScored[13] = {false};
    string listCategories[13] = {'( 1) Ones', '( 2) Twos', '( 3) Threes', '( 4) Fours', '( 5) Fives', '( 6) Sixes', '(7) Three of a Kind', '( 8) Four of a Kind', '( 9) Full House', '(10) Small Straight', '(12) Yahtzee!', '(13) Chance'};

    //using a for loop, repeat the yahtzee game process 13 times
    for (int x = 0; x < 13; x++) {
        //using a do while loop, allow the user to roll 1, 2, or 3 times
        do {
            //Roll the dice and print the user's hand
            rollDice(dieValues);
            printHand(dieValues);
            numRolls--;

            //Exit the loop if there are no rolls remaining
            if (numRolls == 0) {
                break;
            }
            //Print the number of rolls left and ask the user if they would like to roll again
            cout << endl;
            cout << numRolls << " rolls remaining." << endl;

            //Ask if the user would like to roll again
            cout << "Would you like to roll again? (Y or N)";
            cin >> userInput;

            //If the user chooses to roll again, find out which, if any, die values the user would like to keep
            if (userInput == 'Y') {
                for (int i = 0; i < HAND_SIZE; i++) {
                    cout << "Do you want to keep die #" << i + 1 << "? (Y or N)";
                    cin >> userDieChoice[i];
                    cout << endl;
                }
                cout << endl;
            }
        } while (userInput == 'Y');
        numRolls = 3;

        //Ask the user which category they would like to score their hand as and update the score array
        cout << "Which category do you want to score this hand as?" << endl;

        for(int i = 0; i < listCategories.length; i++) {
            if (!categoryScored[i]) {
                cout << listCategories[i] << endl;
            }
        }

        cout << "Category #";
        cin >> scoreCategory;

        switch (scoreCategory) {
            case 1:
                userScoreArray[scoreCategory - 1] = scoreOnes (dieValues[0], dieValues[1], dieValues[2], dieValues[3], dieValues[4]);
                break;
            case 2:
                userScoreArray[scoreCategory - 1] = scoreTwos (dieValues[0], dieValues[1], dieValues[2], dieValues[3], dieValues[4]);
                break;
            case 3:
                userScoreArray[scoreCategory - 1] = scoreThrees (dieValues[0], dieValues[1], dieValues[2], dieValues[3], dieValues[4]);
                break;
            case 4:
                userScoreArray[scoreCategory - 1] = scoreFours (dieValues[0], dieValues[1], dieValues[2], dieValues[3], dieValues[4]);
                break;
            case 5:
                userScoreArray[scoreCategory - 1] = scoreFives (dieValues[0], dieValues[1], dieValues[2], dieValues[3], dieValues[4]);
                break;
            case 6:
                userScoreArray[scoreCategory - 1] = scoreSixes (dieValues[0], dieValues[1], dieValues[2], dieValues[3], dieValues[4]);
                break;
            case 7:
                userScoreArray[scoreCategory - 1] = scoreThreeKind (dieValues[0], dieValues[1], dieValues[2], dieValues[3], dieValues[4]);
                break;
            case 8:
                userScoreArray[scoreCategory - 1] = scoreFourKind (dieValues[0], dieValues[1], dieValues[2], dieValues[3], dieValues[4]);
                break;
            case 9:
                userScoreArray[scoreCategory - 1] = scoreFullHouse (dieValues[0], dieValues[1], dieValues[2], dieValues[3], dieValues[4]);
                break;
            case 10:
                userScoreArray[scoreCategory - 1] = scoreSmallStraight (dieValues[0], dieValues[1], dieValues[2], dieValues[3], dieValues[4]);
                break;
            case 11:
                userScoreArray[scoreCategory - 1] = scoreLargeStraight (dieValues[0], dieValues[1], dieValues[2], dieValues[3], dieValues[4]);
                break;
            case 12:
                userScoreArray[scoreCategory - 1] = scoreYahtzee (dieValues[0], dieValues[1], dieValues[2], dieValues[3], dieValues[4]);
                break;
            case 13:
                userScoreArray[scoreCategory - 1] = scoreChance (dieValues[0], dieValues[1], dieValues[2], dieValues[3], dieValues[4]);
                break;
            default:
                break;
        }

        //update the list of score categories left then calculate and print the user's current score
        categoryScored[scoreCategory - 1] = true;
        totalScore += userScoreArray[scoreCategory - 1];
        cout << "Your current score is " << totalScore;

    }



    //return 0 signals the operating system that our program ended ok.
    return 0;
}