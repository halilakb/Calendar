#include "calendar.h"
#include "event.h"
#include <iostream>

Event* Calendar::addEvent(int eventType,int year,int month,int day,int hour){
	if(eventType == 0){						// controlling eventType for Task objects 
		Task* t = new Task(year,month,day,hour);		// Creates a new Task object
		if(tail == NULL)
			head = t;
		else
			tail->next = t;
			tail = t;
			return t;
	}
	else if (eventType == 1){						// controlling eventType for Appointment objects
		Appointment* p = new Appointment(year,month,day,hour);		// Creates a new Appointment object
		if(tail == NULL)
			head = p;
		else
			tail->next = p;
			tail = p;
			return p;
	}
	return head;
}

void Calendar::deleteEvent(int r){
	Event *temp3;
	temp3 = head;
	bool s = false;
	while (temp3 != NULL){				// this loop used for checking the list if it has an Event with a given id.  
		if (temp3->id == r )
			s = true;
			temp3 = temp3->next;
		}
	if(s == false) throw "EventNotFound";		// throw systax for exeption block, throw an error message
		
		
		
	else if(head != NULL){
		Event *temp1;
		temp1 = head;
		if (temp1->id == r){
			head = head->next;
			cout << "Element with id " << temp1->get_id() << " is deleted." << endl; 
			delete temp1;				// deletes object and gives memory back to RAM
		}
		else {
			while (true){
				if(temp1->next == NULL){
					break;
				}
				if(temp1->next->id == r){
					Event *temp2;
					temp2 = temp1->next;
					temp1->next = temp1->next->next;
					cout << "Element with id " << temp2->get_id() << " is deleted." << endl;
					delete temp2;		
					break;
				}
				temp1 = temp1->next;
			}
		}
	}
	else
		cout << "Liste Boş" << endl;
}

void Calendar::listEvents(){					// this method lists the all events of the linklist
	if (head == NULL) throw "ListEmpty";			// throw an error message
	cout << "-----Begining of the list-----" << endl;
	Event *temp = head;
	while(temp != NULL){
		temp->print();
		cout << "--------------------------------------------------------" << endl;
		temp = temp->next;
	}		
	cout << "------End of the list------" << endl;
}

void Calendar::filterEvents(int a,int b){			// this method lists the events with specific year and month
	Event *temp = head;
	bool s = false;
	while (temp != NULL){					// this loop checks if the list has an Event with given year and month
		if (temp->year == a && temp->month == b){
			s = true;
		}
		temp = temp->next;
	}
	
	if (s == false) throw "NoMatchingEvent";		// throw an error message 
	temp = head;
	while (temp != NULL){
		if (temp->year == a && temp->month == b){
			temp->print();
			cout << "---------------------------------------------------------" << endl;
		}
		temp = temp->next;
	}
}

