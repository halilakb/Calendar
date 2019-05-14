#ifndef CALENDAR_H
#define CALENDAR_H
#include "event.h"
#include <iostream>
using namespace std;

class Calendar{				// calendarclass is used for making linklist
	Event *head;			// head pointer of linklist, pointing first element of the list
	Event *tail;			// tail pointer of linklist, pointing last element of the list
public:
	Calendar() {head = NULL; tail = NULL;}		// constructor of Calendar
	Event* addEvent(int,int,int,int,int);		// method for adding elements to the list
	void deleteEvent(int);				// method for deleting elements from the list
	void listEvents();				// method for listing the avaliable elements
	void filterEvents(int,int);			// method for listing the avaliable elements with a certain year and month
};

#endif
