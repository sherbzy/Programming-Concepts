//below are all of the yahtzee functions
#include "yahtzee.h"

//isOnes and scoreOnes
bool isOnes( int die1, int die2, int die3, int die4, int die5 ) {
    int dieValues[5] = {die1, die2, die3, die4, die5};

    for (int i = 0; i < 5; i++) {
        if (dieValues[i] == 1){
            return true;
        }
    }
    return false;
}

int scoreOnes( int die1, int die2, int die3, int die4, int die5 ) {

    int dieValues [5] = {die1, die2, die3, die4, die5};
    int oneScore = 0;

    for (int i = 0; i < 5; i++) {
        if (dieValues[i] == 1) {
            oneScore += 1;
        }
    }
    return oneScore;
}

//isTwos and scoreTwos
bool isTwos( int die1, int die2, int die3, int die4, int die5 ) {
    bool isTwo = (die1 == 2 || die2 == 2 || die3 == 2 || die4 == 2 || die5 == 2);

    return isTwo;
}

int scoreTwos( int die1, int die2, int die3, int die4, int die5 ) {
    int score=0, i;
    int die[5] = {die1,die2,die3,die4,die5};

    for (i=0; i<5; ++i) {
        if (die[i] == 2) {
            score += 2;
        }
    }
    return score;
}

//isThrees and scoreThrees
bool isThrees( int die1, int die2, int die3, int die4, int die5 ) {
    bool isThree = (die1 == 3 || die2 == 3 || die3 == 3 || die4 == 3 || die5 == 3);

    return isThree;
}

int scoreThrees( int die1, int die2, int die3, int die4, int die5 ) {
    int score=0, i;
    int die[5] = {die1,die2,die3,die4,die5};

    for (i=0; i<5; ++i) {
        if (die[i] == 3) {
            score += 3;
        }
    }
    return score;
}

//isFours and scoreFours
bool isFours( int die1, int die2, int die3, int die4, int die5 ) {

    bool isAce = (die1 == 4 || die2 == 4 || die3 == 4 || die4 == 4 || die5 == 4);
    return isAce;

}

int scoreFours( int die1, int die2, int die3, int die4, int die5 ) {

    int scores[] = {die1,die2,die3,die4,die5};
    int aceScore = 0;

    for( int i = 0; i < 5; i++ ) {
        if( scores[i] == 4 ) {
            aceScore += 4;
        }
    }
    return aceScore;
}

//isFives and scoreFives
bool isFives( int die1, int die2, int die3, int die4, int die5 ) {

    if (die1 == 5 || die2 == 5 || die3 == 5|| die4 == 5 || die5 == 5){

        return true;
    }
    else {
        return false;
    }
}

int scoreFives( int die1, int die2, int die3, int die4, int die5 ) {
    int dieVal [5] = {die1, die2, die3, die4, die5};
    int scoreFives =0;

    for (int i = 0; i < 5; i++) {
        if (dieVal[i] == 5) {
            scoreFives += 5;
        }
    }
    return scoreFives;
}

//isSixes and scoreSixes
bool isSixes( int die1, int die2, int die3, int die4, int die5 ) {
    int dice[5] = {die1, die2, die3, die4, die5};
    for(int i = 0; i < 5; i++){
        if(dice[i] == 6){
            return true;
        }
    }
    return false;
}

int scoreSixes( int die1, int die2, int die3, int die4, int die5 ) {
    int dice[5] = {die1, die2, die3, die4, die5}, score = 0;
    for(int i = 0; i < 5; i++){
        if(dice[i] == 6){
            score += 6;
        }
    }
    return score;
}

//isThreeKind and scoreThreeKind
bool isThreeKind( int die1, int die2, int die3, int die4, int die5 ) {

    int count;
    bool threeKind = false;
    int dice[5] = {die1, die2, die3, die4, die5};

    for(int i = 0; i < 5; i++){

        count = 0;
        for (int j = 0; j < 5; j++){
            if(dice[i] == dice[j]){
                count++;
            }
        }
        if(count >= 3){
            threeKind = true;
        }
    }
    return threeKind;
}

int scoreThreeKind( int die1, int die2, int die3, int die4, int die5 ) {
    int score = 0;

    if(isThreeKind(die1, die2, die3, die4, die5)){
        score = die1 + die2 + die3 + die4 + die5;
    }
    return score;
}

//isFourKind and scoreFourKind
bool isFourKind( int die1, int die2, int die3, int die4, int die5 ) {
    int count = 0;
    int die[5] = {die1, die2, die3, die4, die5};
    for (int i = 0; i < 5; ++i) {
        count = 0;
        for (int j = 0; j < 5; ++j) {
            if (die[i] == die[j]) {
                ++count;
            }
            if (count == 4) {
                return true;
            }
        }
    }
    return false;
}

int scoreFourKind( int die1, int die2, int die3, int die4, int die5 ) {
    if (isFourKind(die1, die2, die3, die4, die5) == true) {
        return die1 + die2 + die3 + die4 + die5;
    } else {
        return 0;
    }
}

//isFullHouse and scoreFullHouse
bool isFullHouse( int die1, int die2, int die3, int die4, int die5 ) {
    int diceRoll [6] = {0,0,0,0,0,0};
    diceRoll[die1-1]++;
    diceRoll[die2-1]++;
    diceRoll[die3-1]++;
    diceRoll[die4-1]++;
    diceRoll[die5-1]++;

    bool threeOfaKind = false;
    bool twoOfaKind = false;
    for (int i = 0; i < 6; i++) {
        if(diceRoll[i] == 3) {
            threeOfaKind = true;
        } else if(diceRoll[i] == 2) {
            twoOfaKind = true;
        }
    }
    if(threeOfaKind && twoOfaKind) {
        return true;
    } else {
        return false;
    }
}

int scoreFullHouse( int die1, int die2, int die3, int die4, int die5 ) {
    if(isFullHouse(die1,die2,die3,die4,die5)){
        return 25;
    } else {
        return 0;
    }
}

//isSmallStraight and scoreSmallStraight
bool isSmallStraight(int die1, int die2, int die3, int die4, int die5) {
    int roll[5] = {die1, die2, die3, die4, die5};
    int numbers[6] = {0};
    for(int i = 1; i < 6; i++) {
        numbers[roll[i - 1] - 1] = numbers[roll[i - 1] - 1] + 1;
    }
    for(int i = 0; i <= 2; i++) {
        if((numbers[i] >= 1) && (numbers[i + 1] >= 1) && (numbers[i + 2] >= 1) && (numbers[i + 3] >= 1)) {
            return true;
        }
    }
    return false;
}

int scoreSmallStraight(int die1, int die2, int die3, int die4, int die5) {
    if(isSmallStraight(die1, die2, die3, die4, die5)) {
        return 30;
    } else {
        return 0;
    }
}

//isLargeStraight and scoreLargeStraight
bool isLargeStraight( int die1, int die2, int die3, int die4, int die5 ) {
    int tempArr[7] = {0, 0, 0, 0, 0, 0, 0};
    tempArr[die1] = 1;
    tempArr[die2] = 1;
    tempArr[die3] = 1;
    tempArr[die4] = 1;
    tempArr[die5] = 1;

    for(int i = 1; i < 3; i++){
        int sum = 0;
        for(int j = i; j < i+5; j++){
            sum += tempArr[j];
        }
        if(sum == 5){
            return true;
        }
    }
    return false;
}

int scoreLargeStraight( int die1, int die2, int die3, int die4, int die5 ) {
    if(isLargeStraight(die1, die2, die3, die4, die5)){
        return 40;
    }

    return 0;
}

//isChance and scoreChance
bool isChance( int die1, int die2, int die3, int die4, int die5 ) {
    return true;
}

int scoreChance (int die1, int die2, int die3, int die4, int die5 ) {
    int score;
    score = die1 +die2+die3+die4+die5;
    return score;
}

//isYahtzee and scoreYahtzee
bool isYahtzee(int dieA, int dieB, int dieC, int dieD, int dieE) {
    int trueFalse;
    if (dieA == dieB && dieB == dieC && dieC == dieD && dieD == dieE) {
        trueFalse = true;
    } else {
        trueFalse = false;
    }

    return trueFalse;
}

int scoreYahtzee(int dieA, int dieB, int dieC, int dieD, int dieE) {
    if (dieA == dieB && dieB == dieC && dieC == dieD && dieD == dieE) {
        return 50;
    } else {
        return 0;
    }

}