#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <string>
using namespace std;

static int k=0;

class Event{					// Abstract Event(base) class.
	friend class Calendar;
	int year;
	int month;
	int day;
	int hour;
	int id;
	Event *next;				// next pointer for linklist
	
public:
	Event(int,int,int,int);			// constructor of Event class

	int get_year() const {return year;}	// get methods for member of Event class 
	int get_month() const {return month;}
	int get_day() const {return day;}
	int get_hour() const {return hour;}
	int get_id() const {return id;}
	virtual void print() const = 0;		// pure virtual print function, makes Event class Abstract
	virtual ~Event(){}			// virtual destructor of Event class
};

class Task:public Event{				// Task class derived from Event class
	string taskname;
public:
	Task(int,int,int,int);				// Task constructor
	
	void set_taskname(string str){ taskname = str; }			// set and get methods for taskname
	string get_taskname() const { return taskname; }

	void print() const;
};

class Appointment:public Event{				// Appointment class derived from Event class
	string personname;
	string place;
public:
	Appointment(int,int,int,int);			// Appointment constructor
	
	void set_personname(string str){ personname = str;}			// set-get methods of Appointment class private variables
	string get_personname() const { return personname;}

	void set_place(string str){ place = str;}
	string get_place() const { return place;}

	void print() const;
};

#endif
