//
// Created by Lauren Sherburne on 11/22/2019.
//

#ifndef L8D_DATE_H
#define L8D_DATE_H


class Date {
public:
    //declare a function to set the date: default and user-inputted
    void setDate ();
    void setDate (int m, int d, int y);

    //declare getter functions for the private variables
    int getMonth ();
    int getDay ();
    int getYear ();

private:
    //declare private variables for the month, day, and year
    int _month;
    int _day;
    int _year;

    //declare a private validate function to check if the date is currently in a good state
    void validateDate ();

    //declare boolean member function that returns whether the callee is earlier than the target date argument passed
    bool checkDate (Date date);
};


#endif //L8D_DATE_H
