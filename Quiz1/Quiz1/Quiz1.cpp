#include <iostream>
#include <string>
using namespace std;

struct Date {
	int viewDate;
};
struct Appointment {
	int id; // auto-generated
	string name; // person’s name
	Date date; // appointment date
	string purpose; // reason for visit
};
Appointment schedule[50];
int choice = 0;

int main() {
	Appointment userAppt{};
	Date userDate{};
	cout << "*****Appointment Scheduler*****" << endl;
	cout << "1. Add Appointment" << endl;
	cout << "2. View Appointments by Date" << endl;
	cout << "3. Exit" << endl;
	cout << "Choice: "; cin >> choice;
	if (choice == 1) {
		cout << "Name: ";
		cin >> userAppt.name;
		cout << "Date (DD MM YYYY): ";
		cin >> userAppt.date;
		cout << "Purpose: ";
		cin >> userAppt.purpose;
		userAppt.id = 1000 + rand() % 9000;
		cout << "Appointment added! ID: " << userAppt.id;
	}
	else if (choice == 2) {
		cout << "Enter day (DD MM YYYY): "; cin >> userDate.viewDate;
		if (userDate.viewDate == userAppt.date) {
			cout << "Appointments on " << userDate.viewDate << ":" << endl;
			cout << "ID: " << userAppt.id << "|" << userAppt.name << "|" << userAppt.purpose << endl;
		}
		else {
			cout << "No appointments found for that date.";
		}
		cout << "Choice: "; cin >> choice;
	}
	else {
		cout << "Thank you for using the scheduler!";
	}
	return 0;
}