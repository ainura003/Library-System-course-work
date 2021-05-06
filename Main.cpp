#include "Status.h"
#include "Password.h"
#include "Administrator.h"
#include "Student.h"

LogIn rec;
Library lib;
Password pwd;
string account;

int Login(string username, string password) { 
	for (size_t i = 0; i < lib.UserArray.size(); i++)
		if (username == lib.UserArray[i].GetUsername() && password == lib.UserArray[i].GetPassword()) 
			return lib.UserArray[i].GetStatus(); 
	return 0;
}

void LoadData() {
	lib.LoadUser(); 
	lib.LoadBook(); 
}

void Welcome() { 
	system("cls");
	int status = 0;
	int time = 0;
	cout << "Welcome to Library System" << endl;
	cout << "Please login first" << endl;
	while (status == 0) {
		cout << "Username: " << endl;
		cin >> account; 
		cout << "Password: " << endl;
		pwd.InputPassword(); 
		status = Login(account, pwd.GetPassword()); 
		if (status < 1 || status > 3) {
			time++; 
			if (time < 3) cout << "Oops! Login fail.   Please try again.. " << endl;
			else {
				cout << "Maybe you should register a new account = =" << endl; // Failed too many times, force to exit
				Sleep(1500);
				return;
			}
			Sleep(1500);
		}
		else { 
			if (status == 1) {
				Administrator man;
				man.Interface(account);
			}
			else if (status == 2) {
				PersonalStaff man;
				man.Interface(account);
			}
			else if (status == 3) {
				Student man;
				man.Interface(account);
			}
			break;
		}
		system("cls");
		cout << "Welcome to Library System" << endl;
		cout << "Please login first" << endl;
	}
}

int main(void) {
	LoadData(); 
	Welcome(); 
}