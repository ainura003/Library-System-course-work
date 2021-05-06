#include "Administrator.h"

extern LogIn rec;
extern Library lib;
extern string account;

void Administrator::AddUser() { 
	system("cls");
	Status newuser; 
	string name, pwd;
	cout << "Please input the username that you want to register" << endl;
	cin >> name; 
	for (size_t i = 0; i < lib.UserArray.size(); i++)
		if (lib.UserArray[i].GetUsername() == name) { 
			if (lib.UserArray[i].GetStatus() != 0) { 
				cout << "User already exist! " << endl;
				Sleep(1000);
				return;
			}
			else {
				cout << "Please input your password" << endl; 
				cin >> pwd; 
				lib.UserArray[i].SetUsername(name);
				lib.UserArray[i].SetPassword(pwd);
				lib.UserArray[i].SetStatus(3); 
				cout << "Add user succsessfully!~ " << endl;
				Sleep(1000);
				Sleep(2000);
				rec.UserLog(account, name, "add", 0);
				PrintUserArray(); 
				return;
			}
		}
	cout << "Please input your password" << endl; 
	cin >> pwd;
	newuser.SetUsername(name);
	newuser.SetPassword(pwd);
	newuser.SetStatus(3);
	lib.UserArray.push_back(newuser); 
	cout << "Add user succsessfully!~ " << endl;
	Sleep(1000);
	Sleep(2000);
	rec.UserLog(account, name, "add", 0); 
	PrintUserArray(); 
}

void Administrator::DelUser() { 
	system("cls");
	int choice;
	string name;
	cout << "Please input the username that you want to delete" << endl;
	cin >> name; 
	for (size_t i = 0; i < lib.UserArray.size(); i++)
		if (lib.UserArray[i].GetUsername() == name) { 
			if (lib.UserArray[i].GetStatus() != 0) {
				cout << "Are you sure you want to delete this user? (press 1: continue, 0: quit)" << endl;
				cin >> choice;
				if (choice == 1) { 
					lib.UserArray[i].SetStatus(0);
					cout << "Delete user succsessfully!~ " << endl;
				}
				else cout << "Delete canceled . " << endl; // Cancel the delete operation
				Sleep(1000);
				cout << "Automatic quit after 3 seconds." << endl;
				Sleep(2000);
				rec.UserLog(account, name, "del", 0);
				PrintUserArray(); 
				return;
			}
		}
	cout << "User not exist! " << endl; 
	Sleep(1000);
}

void Administrator::SetUser() {
	system("cls");
	int choice;
	string name;
	cout << "Please input the username that you want to change status" << endl;
	cin >> name; 
	for (size_t i = 0; i < lib.UserArray.size(); i++)
		if (name == lib.UserArray[i].GetUsername()) {
			if (lib.UserArray[i].GetStatus() != 0) { 
				cout << "Please input a number:  3 for Student, 2 for Staff, 1 for Administartor, 0 for quit" << endl;
				cin >> choice;
				if (choice != 0) { 
					lib.UserArray[i].SetStatus(choice);
					cout << "Change user status succsessfully!~ " << endl;
				}
				else cout << "Change canceled." << endl; 
				Sleep(1000);
				Sleep(2000);
				rec.UserLog(account, name, "set", choice); 
				PrintUserArray(); 
				return;
			}
		}
	cout << "User not exist! " << endl; 
	Sleep(1000);
}

void Administrator::ListUser() { 
	system("cls");
	string temp;
	vector<string> Stat; 
	temp = "Administrator";
	Stat.push_back(temp);
	temp = "PersonalStaff";
	Stat.push_back(temp);
	temp = "Student";
	Stat.push_back(temp);
	cout << "This is the list of all the user:" << endl;
	cout << "|       Username      |    Password  |   Status   |" << endl;
	for (size_t i = 0; i < lib.UserArray.size(); i++) 
		if (lib.UserArray[i].GetStatus() != 0)
			cout << "|" << setw(21) << lib.UserArray[i].GetUsername() << "|" << setw(36) << lib.UserArray[i].GetPassword()
			<< "|" << setw(12) << Stat[lib.UserArray[i].GetStatus() - 1] << "|" << endl;
	cout << endl;
	cout << "Input 0 to exit" << endl;
	cin >> temp;
	while (temp != "0")
		cin >> temp;
}

void Administrator::Interface(string username) {
	char command;
	int stop = 0;
	while (1) {
		system("cls");
		cout << "Welcome! " << username << " You are administartor" << endl;
		cout << "Please choose what you want to do by input a character that list under " << endl;
		while (1) { // The operation list
			cout << "1 ----- Add new user" << endl;
			cout << "2 ----- Delete user" << endl;
			cout << "3 ----- Change user privilage" << endl;
			cout << "4 ----- Add new book" << endl;
			cout << "5 ----- Delete book" << endl;
			cout << "6 ----- Change book information" << endl;
			cout << "7 ----- List book (ALL)" << endl;
			cout << "8 ----- List book (By Category)" << endl;
			cout << "9 ----- List book (By Name)" << endl;
			cout << "+ ----- List all users' information" << endl;
			cout << "0 ----- Exit;" << endl;
			cin >> command;
			if (command != '+' && (command < '0' || command > '9')) { 
				cout << endl << "Wrong!! You should input '*','+' or number between 0-9" << endl;
				cout << "Please input an order." << endl; // Ask to input again
			}
			else break;
		}
		switch (command) {
		case '1':
			AddUser(); 
			break;
		case '2':
			DelUser();
			break;
		case '3':
			SetUser(); 
			break;
		case '4':
			AddBook(); 
			break;
		case '5':
			DelBook(); 
			break;
		case '6':
			SetBook(); 
			break;
		case '7':
			ListBookAll();
			break;
		case '8':
			ListBookByC(); 
			break;
		case '9':
			ListBookByN(); 
			break;
		case '+':
			ListUser(); 
			break;
		case '0':
			stop = 1;
			Sleep(3000);
			break;
		}
		if (stop) break;
	}
}