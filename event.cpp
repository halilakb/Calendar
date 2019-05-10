#include "event.h"

Event::Event(int a,int b,int c,int d){
	year=a;
	month=b;
	day=c;
	hour=d; 
	id=k; 
	k++;
}

Task::Task(int a,int b,int c,int d):Event(a,b,c,d){}		// Task constructor

void Task::print() const {				// print method of Task class
	cout << "Task with id " << get_id() << " at " << get_day() << "/";
	cout << get_month() << "/" << get_year() << ", " << get_hour() << ":00:" << endl; 
	cout << get_taskname() << endl;
}

Appointment::Appointment(int a,int b,int c,int d):Event(a,b,c,d){}		// Appointment constructor

void Appointment::print() const {		// print function of Appointment class
	cout << "Appointment with id " << get_id() <<" at "<< get_day() << "/";
	cout << get_month() << "/" << get_year() << ", " << get_hour() << ":00:" << endl;
	cout << get_personname() << ", " << get_place() << endl;
}
