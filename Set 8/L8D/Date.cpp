//
// Created by Lauren Sherburne on 11/22/2019.
//

#include "Date.h"
#include <iostream>
using namespace std;


//write the private validate function to determine if the date is currently in a sound state
void Date::validateDate() {
    //validate month
    if ((_month > 12) || (_month < 1)) {
        setDate();
    }
    //validate day
    if ((_day > 31) || (_day < 1)) {
        setDate();
    }
    //validate year
    if (_year < 1) {
        setDate();
    }
}


//write a function to set the date
void Date::setDate() {
    _month = 12;
    _day = 30;
    _year = 1950;
    cout << "This date, 12/30/1950, is the birthday of the man who created the C++ programming language: Bjarne Stroustrup!" << endl;
}

void Date::setDate (int m, int d, int y) {
    _month = m;
    _day = d;
    _year = y;
    validateDate();
    if ((m == 8) && (d == 1) && (y == 1876)) {
        cout << "The date you inputted, 8/1/1876, marks the day that Colorado joined the Union as the 38th state!" << endl;
    }
}

//write functions to get the private variables in the date
int Date::getMonth () {
    return _month;
}

int Date::getDay () {
    return _day;
}

int Date::getYear () {
    return _year;
}

//write boolean member function that returns whether the callee is earlier than the target date argument passed
bool Date::checkDate (Date targetDate) {
    if ((targetDate._year) > (_year)) {
        return true;
    } else if ((targetDate._year) == (_year)){
        if ((targetDate._month) > (_month)) {
            return true;
        } else if ((targetDate._month) == (_month)) {
            if ((targetDate._day) > (_day)) {
                return true;
            }
        }
    } else {
        return false;
    }
}
