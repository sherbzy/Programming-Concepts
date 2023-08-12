//
// Created by Lauren Sherburne on 11/26/2019.
//

#include "Event.h"
#include <iostream>
#include <string>
using namespace std;

//setter functions for the date, title, and location
void Event::setEventDate() {
    _eventDate.setDate();
    _eventTitle = "Bjarne Stroustrup's Birthday!!!";
    _eventLocation = "Aarhus, Denmark";
}

void Event::setEventDate (Date date) {
    _eventDate = date;
    if ((_eventDate.getYear() == 1876) && (_eventDate.getMonth() == 8) && (_eventDate.getDay() == 1)) {
        cout << "This is the date that Colorado joined the union! Your location and title have been updated accordingly." << endl;
        _eventLocation = "Colorado";
        _eventTitle = "Colorado Joins the Union (38th state)!";
    }
}

void Event::setEventTitle (string title) {
    _eventTitle = title;
}

void Event::setEventLocation (string location) {
    _eventLocation = location;
}

void Event::setEvent (Date eventDate, string eventTitle, string eventLocation) {
    setEventDate(eventDate);
    setEventTitle(eventTitle);
    setEventLocation(eventLocation);
}


//getter functions for the date, title, and location
Date Event::getEventDate () {
    return _eventDate;
}

string Event::getEventTitle() {
    return _eventTitle;
}

string Event::getEventLocation () {
    return _eventLocation;
}

//print function that prints MM/DD/YYYY: Title (location)
void Event::printEvent() {
    cout << _eventDate.getMonth() << "/" << _eventDate.getDay() << "/";
    cout << _eventDate.getYear() << ": " <<_eventTitle << " (" << _eventLocation << ")" << endl;
}