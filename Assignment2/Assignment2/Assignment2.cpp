#include <iostream>
#include <string>
using namespace std; 

class Book {
private: 
	int year, id; //Book ID
	string title, author; 
	bool available; //True if available, false if borrowed
public: 
	Book() {
		year = 0, id = 0; 
		title = "_", author = "_"; 
		available = true; 
	}
	//Setters
	void setID(int I) {
		id = I; 
	}
	void setYear(int Y) {
		year = Y;
	}
	void setTitle(string T) {
		title = T;
	}
	void setAuthor(string A) {
		author = A;
	}
	void setAvailable(bool A) {
		available = A; 
	}
	//Getters
	int getID() {
		return id; 
	}
	int getYear() {
		return year;
	}
	string getTitle() {
		return title;
	}
	string getAuthor() {
		return author;
	}
	bool getAvailable() {
		return available;
	}

	void borrowBook() {
		if (getAvailable() == true) {
			setAvailable(false); 
		}
	}
	void returnBook() {
		if (getAvailable() == false) {
			setAvailable(true); 
		}
	}
	void display() {
		cout << "ID: " << id; 
		cout << "Title: " << title; 
		cout << "Author: " << author; 
		cout << "Year: " << year; 
		cout << "Status: " << available; 
	}
};

Book bookList[100]; 

int main() {
	int choice; 
	int intChoice; 
	string stringChoice; 
	int randomNum;  
	Book book1;
	do {
		cout << "*************Welcome to the Library*************" << endl; 
		cout << "Please Choose one of the following operations: " << endl; 
		cout << "1. Add a new book" << endl; 
		cout << "2. Borrow a book" << endl;
		cout << "3. Return a book" << endl;
		cout << "4. Display details of a book (by ID)" << endl;
		cout << "5. List all available books" << endl;
		cout << "6. Exit" << endl;
		cout << "Choice: "; cin >> choice; 

		if (choice == 1) {
			randomNum = 10000 + rand() % 90000;
			cout << "Enter title: "; cin >> stringChoice; 
			book1.setTitle(stringChoice); 
			cout << "Enter author: "; cin >> stringChoice; 
			book1.setAuthor(stringChoice); 
			cout << "Enter year: "; cin >> intChoice; 
			book1.setYear(intChoice);  

			cout << "Book added successfully!\nTitle: " << book1.getTitle() << "\nID: " << randomNum << endl; 
			bookList[1] = book1; 
			book1.setAvailable(true); 
		}
		else if (choice == 2) {
			cout << "Enter Book ID: "; cin >> intChoice; 
			for (int i = 0; i < 100; i++)
				if (bookList[i].getID() == intChoice) {
					book1.borrowBook(); 
					cout << "You have successfully borrowed " << book1.getTitle() << endl; 
					break; 
				}
				else if (i == 99) {
					cout << "Sorry, that book is not available to borrow." << endl; 
				}
		}
		else if (choice == 3) {
			cout << "Enter Book ID: "; cin >> intChoice;
			for (int i = 0; i < 100; i++) {
				if (bookList[i].getID() == intChoice) {
					book1.returnBook();
					cout << "You have successfully returned " << book1.getTitle() << endl;
					break; 
				}
				else if (i == 99) {
					cout << "Book was not borrowed." << endl; 
				}
			}
			
		}
		else if (choice == 4) {
			cout << "Enter book ID: "; cin >> intChoice; 
			for (int i = 0; i < 100; i++) {
				if (bookList[i].getID() == intChoice) {
					book1.display(); cout << endl; 
				}
				else if (i == 99) {
					cout << "Book not found." << endl;
				}
			}
		}
		else if (choice == 5) {
			for (int i = 0; i < 100; i++) {
				if (bookList[i].getAvailable() == true) {
					cout << bookList[i].getTitle() << endl; 
				}
			}
		}

	} while (choice != 6); 
	cout << "Thank you for using the library system! Goodbye!"; 
	return 0; 
}