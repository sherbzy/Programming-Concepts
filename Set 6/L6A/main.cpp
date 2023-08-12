/* CSCI 261 Lab 6A - Yahtzee Functions
 *
 *
 *
 * Program Name: isOnes and scoreOnes Yahtzee Funtion
 * Description: The first function, isOnes, returns true if the user rolled any ones. The second, scoreOnes, gives
 *              the user's score for the number of ones they rolled.
 *
 * Authors: Lauren Sherburne and Haley Vinton
 * Date: October 25, 2019
 *
 */

#include <iostream>

 bool isOnes( int die1, int die2, int die3, int die4, int die5 ) {
        int dieValues[5] = {die1, die2, die3, die4, die5};

        for(int i = 0; i < 5; i++){
            if (dieValues[i] == 1) {
                return true;
            }
        }
        return false;
    }


    int scoreOnes( int die1, int die2, int die3, int die4, int die5 ) {
        int dieValues[5] = {die1, die2, die3, die4, die5};
        int oneScore = 0;

        for(int i = 0; i < 5 ; i++){
            if(dieValues[i] == 1){
                oneScore += 1;
            }
        }
        return oneScore;
    }
    //return 0 signals the operating system that our program ended ok.
    return 0;