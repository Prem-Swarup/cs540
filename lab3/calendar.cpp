
#include<bits/stdc++.h>
using namespace std;


class Event {
	string heading ;
	string description;

	public:
	Event() ;
	Event(string _heading, string _description) ;
	void printDetails() ;
	void editHeading(string _heading) ;
	void editDescription(string descrpt) ;
};

Event::Event(){
	this->heading = "some event" ;
	this->description = "some description" ;
}

Event::Event(string _heading, string _description) {
	this->heading = _heading ;
	this->description = _description ;
}

void Event::printDetails(){
	cout<<"Event Heading: "<<this->heading<<endl ;
	cout<<"Event Description: "<<this->description<<endl ;
}

void Event::editHeading(string _heading) {
	this->heading = _heading ;
}

void Event::editDescription(string descrpt){
	this->description = descrpt ;
}


unordered_map<int, string> monthNoToName ;
unordered_map<string, int> monthNameToNo ;

class monthCalendar {
	string monthName ;
	int monthNo ;
	string startDay ;
	
	public:
	unordered_map<int, Event> eventMap ;
	monthCalendar(string, string) ;
	monthCalendar(int, string) ;
	void addEvent(int date, Event _event) ;
	void displayEvent(int date) ;
};

monthCalendar::monthCalendar(string name, string day) {
	this->monthName = name ;
	this->monthNo = monthNameToNo[name] ;
	this->startDay = day ;
}
	
monthCalendar::monthCalendar(int no, string day) {
	this->monthNo = no ;
	this->monthName = monthNoToName[no] ;
	this->startDay = day ;
}

void monthCalendar::addEvent(int date, Event _event) {
	eventMap[date] = _event ;
}

void monthCalendar::displayEvent(int date) {
	cout<<"\nDetails of event on "<<date<<" "<<this->monthName<<" are\n" ;
	eventMap[date].printDetails() ;
}


int main() {
	int date ;
	string heading, description ;
	
	monthNoToName[1] = "January";
	monthNoToName[2] = "February";
	monthNoToName[3] = "March";
	monthNoToName[4] = "April";
	monthNoToName[5] = "May";
	monthNoToName[6] = "June";
	monthNoToName[7] = "July";
	monthNoToName[8] = "August";
	monthNoToName[9] = "September";
	monthNoToName[10] = "October";
	monthNoToName[11] = "November";
	monthNoToName[12] = "December";

	for(int i=1; i<=12; ++i) {
		monthNameToNo[monthNoToName[i]] = i ;
	}

	monthCalendar Sept("September", "friday") ;
	
	cout<<"Enter a date of sept 2023 for adding event: " ;
	cin>>date ; 

	cout<<"\nEnter heading of event: " ;
	
	cin.ignore() ;
	getline(cin, heading) ;

	cout<<"\nEnter description of event: " ;
	getline(cin, description) ;
	cout<<endl ; 

	Event event1(heading, description) ;

	Sept.addEvent(date, event1) ;
	cout<<"Address of added event:  "<<&(Sept.eventMap[date])<<endl ;

	Sept.displayEvent(date) ;

	return 0 ;
}
