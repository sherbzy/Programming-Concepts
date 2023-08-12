/* CSCI 261: Assignment 4 - Guess the Number
 *
 * Program Name: Guess the Number
 * Description:
 *
 * Author: Lauren Sherburne
 * Date: 10/1/19
 */


//Use namespace standard and include the following libraries: iostream, ctime, cstdlib
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    //define constants for too close, too high, and minimum range
    const int TOO_CLOSE_DIFFERENCE = 5;
    const int TOO_HIGH_DIFFERENCE = 25;
    const int MIN_RANGE = 100;

    //define variables for minimum, maximum, randomNumber, user guess, number of guesses
    int minValue;
    int maxValue;
    int randomNumber;
    int userGuess;
    int numGuesses;

    //prompt the user to enter the low and high ends of the number range
    cout << "Hold onto your pants, we're about to play guess-the-numbah!" << endl;
    cout << "Enter the lowest possible number: " << endl;
    cin >> minValue;
    cout << "Enter the highest possible number: " << endl;
    cin >> maxValue;

    while (maxValue < (minValue + MIN_RANGE)) {
        cout << "High number must be at least 100 more than the low number." << endl;
        cin >> maxValue;
    }

    //Generate a random number between minValue and maxValue
    srand(time(0));
    rand();

    randomNumber = (rand() % (maxValue - minValue + 1) + minValue);

    //Use a loop and if statements to input guesses from the user and give them feedback about how accurate they are until
    //the user guesses the random number correctly.
    do {
        cout << "Pick a number between " << minValue << " and " << maxValue << ":";
        cin >> userGuess;

        //address invalid guesses: numbers not within the range and/or letter or character inputs
        if (userGuess > maxValue || userGuess < minValue) {
            cout << "Invalid guess. Please try again." << endl;
        } else if (userGuess < randomNumber) { //test if the guess is too low
            cout << "Too low. ";
            numGuesses = numGuesses + 1;

            if (userGuess >= (randomNumber - TOO_CLOSE_DIFFERENCE)) {
                cout << "Oooh you're close!";
            } else if (userGuess <= (randomNumber - TOO_HIGH_DIFFERENCE)) {
                cout << "Not even close!";
            }
        } else if (userGuess > randomNumber) { //test if the guess is too high
            cout << "Too high. ";
            numGuesses = numGuesses + 1;

            if (userGuess <= (randomNumber + TOO_CLOSE_DIFFERENCE)) {
                cout << "Oooh you're close!";
            } else if (userGuess >= (randomNumber + TOO_HIGH_DIFFERENCE)) {
                cout << "Not even close!";
            }
        }

        cout << endl;

    } while (userGuess != randomNumber);

    //end the game and tell the user how many tries it took them
    cout << "That's right! You won the game in " << numGuesses << " tries." << endl;

    //return 0 signals the operating system that our program ended ok.
    return 0;
}