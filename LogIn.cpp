#include "LogIn.h"
#include "Library.h"
#include "windows.h"

extern Library lib;

void LogIn::UserLog(string loginname, string username, string operation, int status) { 
	ofstream fout;
	fout.open("UserLogIn.txt", ios::app); 
	if (!fout) { 
		cerr << "UserLogIn.txt can't open" << endl;
		abort(); 
	}
	SYSTEMTIME sys;
	GetLocalTime(&sys); 
	fout << "[ " << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << " " << sys.wHour << ":" << sys.wMinute << ":" << sys.wSecond << " ]"; 
	if (operation == "add")
		fout << " Administrator(" << loginname << ") add a new user(" << username << ")" << endl;
	else if (operation == "del")
		fout << " Administrator(" << loginname << ") delete a user(" << username << ")" << endl;
	else if (operation == "set")
		fout << " Administrator(" << loginname << ") set user(" << username << ")'s status to (" << status << ") " << endl;
	else if (operation == "psw")
		fout << " Status(" << loginname << ") change his/her password " << endl;
	fout.close(); 
}

	void LogIn::BookLog(string loginname, string bookSn, string operation, int number) {
	ofstream fout;
	fout.open("BookLogIn.txt", ios::app); 
	if (!fout) { 
		cerr << "BookLogIn.txt can't open" << endl;
		abort(); 
	}
	SYSTEMTIME sys;
	GetLocalTime(&sys); // Get system time
	fout << "[ " << sys.wYear << "-" << sys.wMonth << "-" << sys.wDay << " " << sys.wHour << ":" << sys.wMinute << ":" << sys.wSecond << " ]"; // Output system tiime
	if (operation == "buy")
		fout << " Customer(" << loginname << ") get books(SN" << bookSn << ") with " << number << " copy(s)" << endl;
	else if (operation == "add")
		fout << " Manager(" << loginname << ") add new books(SN:" << bookSn << ") with " << number << " copy(s)" << endl;
	else if (operation == "del")
		fout << " Manager(" << loginname << ") delete books(SN:" << bookSn << ") with " << number << " copy(s)" << endl;
	else if (operation == "set")
		fout << " Manager(" << loginname << ") change book(SN:" << bookSn << ")'s information " << endl;
	fout.close(); 
}

