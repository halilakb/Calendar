#ifndef CALENDAR_H
#define CALENDAR_H
#include "event.h"
#include <iostream>
using namespace std;

class Calendar{
	Event *head;
	Event *tail;
public:
	Calendar() {head = NULL; tail = NULL;}
	Event* addEvent(int,int,int,int,int);
	void deleteEvent(int);
	void listEvents();
	void filterEvents(int,int);
};

#endif
