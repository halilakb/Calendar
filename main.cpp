/*
 * main.cpp
 * 
 * Copyright 2019 Halil Akbulut <halil@itu.edu.tr>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <string>
#include "event.h"
#include "calendar.h"
using namespace std;

int main(){
	Calendar m;				// creates an empty list.
											// here i created 5 task events and 5 appointment events.
	Task* t1 = static_cast<Task*>(m.addEvent(0,2019,4,22,23));			// static_cast is used for turning an Event pointer to a Task pointer.
	t1->set_taskname("Submit OOP Homework 2");					// with this way we can reach the set methods of the object.

	Task* t2 = static_cast<Task*>(m.addEvent(0,2019,4,22,9));
	t2->set_taskname("OOP Midterm 2");

	Task* t3 = static_cast<Task*>(m.addEvent(0,2019,4,23,10));
	t3->set_taskname("23 Nisan Ulusal Egemenlik ve Çocuk Bayramı Etkinlikleri");

	Task* t4 = static_cast<Task*>(m.addEvent(0,2019,5,4,19));
	t4->set_taskname("İTU Halk Oyunları Kulübü Yıl Sonu Gösterisi");

	Task* t5 = static_cast<Task*>(m.addEvent(0,2019,10,29,10));
	t5->set_taskname("29 Ekim Cumhuriyet Bayramı Etkinlikleri");

	Appointment* a1 = static_cast<Appointment*>(m.addEvent(1,2019,4,10,15));
	a1->set_personname("Dr. Ali Bilir");
	a1->set_place("İstanbul Teknik Üniversitesi");

	Appointment* a2 = static_cast<Appointment*>(m.addEvent(1,2019,5,15,11));
	a2->set_personname("Dr. Mustafa Kaya");
	a2->set_place("Kağıthane Devlet Hastanesi");

	Appointment* a3 = static_cast<Appointment*>(m.addEvent(1,2019,5,15,11));
    a3->set_personname("Elif Şahin");
    a3->set_place("Büyükşehir Belediye Binası");

	Appointment* a4 = static_cast<Appointment*>(m.addEvent(1,2019,8,26,16));
	a4->set_personname("Prof. Dr. Metin Yazgı");
	a4->set_place("İstanbul Teknik Üniversitesi");

	Appointment* a5 = static_cast<Appointment*>(m.addEvent(1,2019,12,20,20));
	a5->set_personname("Dr. Selin Okuyan");
	a5->set_place("İstinye Devlet Hastanesi");

	bool x = true;
	while (x){							// a choice list for user 
		int choice;
		cout << "1 For List Events" << endl
			 << "2 For Delete an Event" << endl
			 << "3 For Filter the Events" << endl
			 << "0 For Exit" << endl;
		cin >> choice;
	
		if(choice == 1){
			try{ m.listEvents(); }					// try and catch block for listEvents method.
			catch(const char * result){ cout << result << endl;}
		}
	
		else if(choice == 2){
			int z;
			cout << "Enter Event id you want to delete:";
			cin >> z;
			try{ m.deleteEvent(z); }				// try and catch block for deleteEvent method.
			catch(const char * result){ cout << result << endl;}
		}
	
		else if (choice == 3){
			int y,t;
			cout << "Enter Event time you time you want to list." << endl;
			cout << "Year:";
			cin >> y;
			cout << "Month:";
			cin >> t;
			try{ m.filterEvents(y,t);}				// try and catch block for filterEvents method.
			catch(const char * result){ cout << result << endl;}
		}
		
		else if (choice == 0){x = false;}
	}
return 0;
}
