/* CSCI 261 Lab 8D - Calendar Classes
 *
 * Program Name:
 * Description: The program uses two classes, a date class and an event class, to create calendar functions. In main,
 *
 *
 *
 * Author: Lauren Sherburne
 * Date: 11/25/19
 *
 */

#include <iostream>
#include "date.h"
#include "event.h"
using namespace std;

int main() {
    //testing date class functions
        //test default date (test extra credit: 12/30/1950)
        cout << "Test the default date 12/30/1950 and indicate it's importance below (extra credit)..." << endl;
        Date defaultDate;
        defaultDate.setDate ();
        cout << endl << endl;

        //test set date
        cout << "Test the set date function in the date class and standard output the date below..." << endl;
        Date myBirthday;
        myBirthday.setDate (12, 23, 2000);
        cout << myBirthday.getMonth() << "/" << myBirthday.getDay() << "/" << myBirthday.getYear();
        cout << endl << endl;


        //test extra credit: 8/1/1876
        cout << "Test the use of 8/1/1976 and it's importance below (extra credit)..." << endl;
        Date extraCredit;
        extraCredit.setDate (8, 1, 1876);
        cout << endl << endl;


    //testing event class functions
        //test default event
        cout << "Test the default event function with extra credit title and location..." << endl;
        Event defaultEvent;
        defaultEvent.setEventDate();
        cout << endl << endl;

        //test set event date (and print event)
        cout << "Test the set event date function..." << endl;
        Date lucyBday;
        lucyBday.setDate(02, 25, 2007);
        Event lucyBirthday;
        lucyBirthday.setEvent(lucyBday, "Lucy\'s Birthday", "San Diego");
        lucyBirthday.printEvent();
        cout << endl << endl;

        //test set event date, title, location (and print event)
        cout << "Test the set event date, title, and location functions..." << endl;
        Date valentinesDay;
        valentinesDay.setDate(02, 14, 2016);
        Event valentinesEvent;
        valentinesEvent.setEventDate(valentinesDay);
        valentinesEvent.setEventTitle("Valentine\'s Day <3");
        valentinesEvent.setEventLocation("Paris, France");
        valentinesEvent.printEvent();
        cout << endl << endl;


    //return 0 signals the operating system that our program ended ok
    return 0;
}