//Below are all of the dice rolling and printing functions used in the yahtzee game
#include "dice.h"

//Create a rollDie function with no input that returns a random number between 1 and 6 inclusive
int rollDie() {
    return (rand() % (6)) + 1;
}


//Create a printHand function with currentHand as an input and no output that prints the current die values
void printHand (int currentHand[HAND_SIZE]) {
    cout << "Your hand is: ";
    for (int i = 0; i < HAND_SIZE; i++) {
        cout << currentHand[i] << " ";
    }
}

//Create a rollDice function with an array input and no output that uses rollDie to assign each element of the array with
//a random value between 1 and 6 inclusive
void rollDice (int currentHand[HAND_SIZE]) {
    for (int i = 0; i < HAND_SIZE; i++) {
        currentHand[i] = rollDie();
    }
}