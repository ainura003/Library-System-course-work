#include "Student.h"

extern LogIn rec;
extern Library lib;
extern string account;

void Student::GetBook() { 
	system("cls");
	string serialn, temp;
	cout << "Please input the Serial number of the book that you want to get " << endl;
	cin >> serialn; 
	for (size_t i = 0; i < lib.BookArray.size(); i++)
		if (lib.BookArray[i].GetSn() == serialn) { 
			cout << "There are " << lib.BookArray[i].GetNumber() << " copies of this book, how many do you want to get?  " << endl;
			while (1) {
				cin >> temp; 
				if (IsAllDigit(temp)) break;
				cout << "Pleass input a digital number. Try again." << endl;
			}
			if (stoi(temp) > lib.BookArray[i].GetNumber()) { 
				cout << "Book number is not that much! " << endl;
				Sleep(1000);
			}
			else {
				lib.BookArray[i].SetNumber(lib.BookArray[i].GetNumber() - stoi(temp)); 
				cout << "Buy " << stoi(temp) << " copies of that book, succsessfully!~ " << endl;
				Sleep(1000);
				Sleep(2000);
				rec.BookLog(account, serialn, "get", stoi(temp)); 
				PrintBookArray(); 
				
			}
			return;
		}
	cout << "Not found this book! " << endl; // Book not found in Book.txt
	Sleep(1000);
}


void Student::Interface(string username) {
	char command;
	int stop = 0;
	while (1) {
		system("cls");
		cout << "Welcome! " << username << " You are a customer~" << endl;
		cout << "Please choose what you want to do by input a number " << endl;
		while (1) { // The operation list
			cout << "1 ----- Get a book" << endl;
			cout << "2 ----- List book (ALL)" << endl;
			cout << "3 ----- List book (By Category)" << endl;
			cout << "4 ----- List book (By Name)" << endl;
			cout << "5 ----- Show more book information by serial number" << endl;
			cout << "0 ----- Exit;" << endl;
			cin >> command;
			if (command < '0' || command > '5') {
				cout << endl << "Wrong!! You should input number between 0-5 " << endl;
				cout << "Please repick a number :) " << endl;
			}
			else break;
		}
		switch (command) {
		case '1':
			GetBook(); 
			break;
		case '2':
			ListBookAll();
			break;
		case '3':
			ListBookByC(); 
			break;
		case '4':
			ListBookByN(); 
			break;
		case '5':
			BookInfor(); 
			break;
		case '0':
			stop = 1;
			Sleep(3000);
			break;
		}
		if (stop) break;
	}
}