#include "PersonalStaff.h"

extern Library lib;
extern LogIn rec;
extern string account;

void PersonalStaff::AddBook() { 
	system("cls");
	BooksInfo newbook;
	string money, number, category, name, Sn, author, information;
	cout << "Please input the Serial number of the book" << endl;
	cin >> Sn; 
	for (size_t i = 0; i < lib.BookArray.size(); i++)
		if (lib.BookArray[i].GetSn() == Sn) {
			cout << "This Serial number already exist =. =" << endl; 
			Sleep(1000);
			return;
		}
	cout << "Please input the name of the book" << endl;
	cin >> name;
	cout << "Please input the author of the book" << endl;
	cin >> author; 
	cout << "Please input the copy number of the book" << endl;
	while (1) {
		cin >> number;
		if (IsAllDigit(number)) break;
		cout << "Pleass input a digital number. Try again." << endl;
	}
	cout << "Please input the category of the book" << endl;
		cin >> category; 
		
	
	newbook.SetName(name);
	newbook.SetSn(Sn);
	newbook.SetAuthor(author);
	newbook.SetNumber(stoi(number));
	newbook.SetCategory(stoi(category));
	lib.BookArray.push_back(newbook); 
	cout << "Add book succsessfully!~ " << endl;
	Sleep(1000);
	Sleep(2000);
	rec.BookLog(account, Sn, "add", stoi(number)); 
	PrintBookArray(); 
}

void PersonalStaff::DelBook() { 
	system("cls");
	string Sn, temp;
	cout << "Please input the Serial number of the book that you want to delete " << endl;
	cin >> Sn; 
	for (size_t i = 0; i < lib.BookArray.size(); i++)
		if (lib.BookArray[i].GetSn() == Sn) {
			cout << "There are " << lib.BookArray[i].GetNumber() << " copies of this book, how many do you want to delete?  " << endl;
			while (1) {
				cin >> temp; 
				if (IsAllDigit(temp)) break;
				cout << "Pleass input a digital number. Try again." << endl;
			}
			if (stoi(temp) > lib.BookArray[i].GetNumber()) { 
				cout << "Book number is not that much! " << endl;
				Sleep(1000);
				Sleep(3000);
			}
			else {
				lib.BookArray[i].SetNumber(lib.BookArray[i].GetNumber() - stoi(temp)); 
				cout << "Delete (" << stoi(temp) << ") of this book succsessfully!~ " << endl;
				Sleep(1000);
				Sleep(2000);
				rec.BookLog(account, Sn, "del", stoi(temp)); 
				PrintBookArray();
			}
			return;
		}
	cout << "Not found this book! " << endl; 
	Sleep(1000);
}

void PersonalStaff::SetBook() { 
	system("cls");
	int choice;
	string number, category, name, Sn, author, information;
	cout << "Please input the Serial number of the book that you want to change the information." << endl;
	cin >> Sn; 
	for (size_t i = 0; i < lib.BookArray.size(); i++)
		if (lib.BookArray[i].GetSn() == Sn) {
			cout << "Do you want to change the name of the book? (input 1 for YES and 0 for NO )" << endl;
			cin >> choice;
			if (choice == 1) {
				cout << "Please input the new name of the book" << endl;
				cin >> name;
				lib.BookArray[i].SetName(name);
			}
			cout << "Do you want to change the Serial number of the book? (input 1 for YES and 0 for NO )" << endl;
			cin >> choice;
			if (choice == 1) {
				cout << "Please input the new Serial number of the book" << endl;
				cin >> Sn; 
				lib.BookArray[i].SetSn(Sn);
			}
			cout << "Do you want to change the author of the book? (input 1 for YES and 0 for NO )" << endl;
			cin >> choice;
			if (choice == 1) {
				cout << "Please input the new author of the book" << endl;
				cin >> author; 
				lib.BookArray[i].SetAuthor(author);
			}
			
			cout << "Do you want to change the category of the book? (input 1 for YES and 0 for NO )" << endl;
			cin >> choice;
			if (choice == 1) {
				cout << "Please input the new category of the book" << endl;
					cin >> category;
					
				lib.BookArray[i].SetCategory(stoi(category));
			}
			
			
			Sleep(1000);
			Sleep(2000);
			rec.BookLog(account, Sn, "set", 0); 
			PrintBookArray(); 
			return;
		}
	cout << "Not found this book! " << endl; // Book not exist in Book.txt
	Sleep(1000);
}



void PersonalStaff::Interface(string username) { // Staff interface
	char command;
	int stop = 0;
	string str;
	while (1) {
		system("cls");
		cout << "Welcome! " << username << " You are staff" << endl;
		cout << "Please choose what you want to do by input a number " << endl;
		while (1) { 
			cout << "1 ----- Add new book" << endl;
			cout << "2 ----- Delete book" << endl;
			cout << "3 ----- Change book information" << endl;
			cout << "4 ----- List book (ALL)" << endl;
			cout << "5 ----- List book (By Category)" << endl;
			cout << "6 ----- List book (By Name)" << endl;
			cout << "0 ----- Exit;" << endl;
			cin >> command;
			if (command < '0' || command > '6') { 
				cout << endl << "Wrong!! You should input number between 0-6 " << endl;
				cout << "Please input a number :) " << endl; 
			}
			else break;
		}
		switch (command) {
		case '1':
			AddBook(); 
			break;
		case '2':
			DelBook(); 
			break;
		case '3':
			SetBook(); 
			break;
		case '4':
			ListBookAll();
			break;
		case '5':
			ListBookByC(); 
			break;
		case '6':
			ListBookByN();
			break;
		case '0':
			stop = 1;
			Sleep(3000);
			break;
		}
		if (stop) break;
	}
}