//
// Created by Lauren Sherburne on 11/26/2019.
//

#ifndef L8D_EVENT_H
#define L8D_EVENT_H
#include "date.h"
#include <string>
using namespace std;



class Event {
public:
    //setter functions for the date, title, and location as well as one function that sets all of event's variables
    void setEventDate ();
    void setEventDate (Date date);
    void setEventTitle (string title);
    void setEventLocation (string location);
    void setEvent (Date date, string title, string location);

    //getter functions for the date, title, and location
    Date getEventDate ();
    string getEventTitle();
    string getEventLocation ();

    //print function that prints MM/DD/YYYY: Title (location)
    void printEvent ();

private:
    //add date, title, and location variables
    Date _eventDate;
    string _eventTitle;
    string _eventLocation;
};


#endif //L8D_EVENT_H
