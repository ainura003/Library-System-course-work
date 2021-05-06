#include "Status.h"
#include "Library.h"

extern LogIn rec;
extern Library lib;
extern string account;

void Status::PrintUserArray() { 
	ofstream fout;
	fout.open("Status.txt"); 
	if (!fout) { 
		cerr << "Status.txt can't open" << endl;
		abort(); 
	}
	for (size_t i = 0; i < lib.UserArray.size(); i++) 
		fout << lib.UserArray[i].GetUsername() << " " << lib.UserArray[i].GetPassword() << " " << lib.UserArray[i].GetStatus() << endl;
	fout.close(); 
}

void Status::PrintBookArray() {
	ofstream fout;
	fout.open("BooksInfo.txt"); 
	if (!fout) { 
		cerr << "BooksInfo.txt can't open" << endl;
		abort(); 
	}
	for (size_t i = 0; i < lib.BookArray.size(); i++)
		fout << lib.BookArray[i].GetName() << " " << lib.BookArray[i].GetSn() << " " << lib.BookArray[i].GetAuthor()
		<< " " << lib.BookArray[i].GetNumber() << " " << lib.BookArray[i].GetCategory();
	fout.close(); 
}

int Status::IsAllDigit(const string& str) { 
	int i;
	for (i = 0; i != str.length(); i++)
		if (!isdigit(str[i]) && (str[i] != '.')) return 0; 
	return 1;
}

void Status::ListBookAll() {
	system("cls");
	string temp;
	cout << "This is the list of all the book:" << endl;
	cout << "       SerialNumber                    Name                 In stock         " << endl;
	for (size_t i = 0; i < lib.BookArray.size(); i++) { 
		cout << setw(18) << lib.BookArray[i].GetSn() << setw(29) << lib.BookArray[i].GetName()
			<< setw(18) << lib.BookArray[i].GetNumber() << setw(13) << setiosflags(ios::fixed) << setprecision(2) <<   endl;
	}
	cout << endl;
	cout << "Input 0 to exit" << endl;
	cin >> temp;
	while (temp != "0")
		cin >> temp;
}

void Status::ListBookByC() { 
	system("cls");
	string temp, category;
	cout << "Please input the category that you want to list: " << endl;
	while (1) {
		cin >> category;
		if (IsAllDigit(category)) break;
		cout << "Pleass input a digital number.  Try again." << endl;
	}
	system("cls");
	cout << "This is the list of all the book in category " << category << " :" << endl;
	cout << "      SerialNumber                   Name                  In stock          " << endl;
	for (size_t i = 0; i < lib.BookArray.size(); i++) 
		if (lib.BookArray[i].GetCategory() == stoi(category)) {
			cout << setw(18) << lib.BookArray[i].GetSn() <<  setw(29) << lib.BookArray[i].GetName() 
				<< setw(18) << lib.BookArray[i].GetNumber() << setw(13) << setiosflags(ios::fixed) << setprecision(2)  <<  endl;
		}
	cout << endl;
	cout << "Input 0 to exit" << endl;
	cin >> temp;
	while (temp != "0")
		cin >> temp;
}

void Status::ListBookByN() { // List book by name
	system("cls");
	string temp, name;
	cout << "Please input the name that you want to find: " << endl;
	cin >> name;
	system("cls");
	cout << "This is the list of all the book that name contains string \"" << name << " \" :" << endl;
	cout << "      SerialNumber                    Name                  In stock      \    " << endl;
	for (size_t i = 0; i < lib.BookArray.size(); i++) // Output each book information match this name
		if (lib.BookArray[i].GetName().find(name) != string::npos) {
			cout << setw(18) << lib.BookArray[i].GetSn() <<  setw(29) << lib.BookArray[i].GetName()
				<< setw(18) << lib.BookArray[i].GetNumber() <<  setw(13) << setiosflags(ios::fixed) << setprecision(2) <<  endl;
		}
	cout << endl;
	cout << "Input 0 to exit" << endl;
	cin >> temp;
	while (temp != "0")
		cin >> temp;
}

void Status::BookInfor() { // See more information of one book
	system("cls");
	string temp, Sn;
	cout << "Please input the Serial number of the book that you want to find: " << endl;
	cin >> Sn;
	for (size_t i = 0; i < lib.BookArray.size(); i++)
		if (lib.BookArray[i].GetSn() == Sn) { 
			system("cls");
			cout << "Detail information of the book with Serial number " << Sn << " : " << endl;
			cout << "Name            : " << lib.BookArray[i].GetName() << endl;
			cout << "Author            : " << lib.BookArray[i].GetAuthor() << endl;
			cout << "In stock           : " << lib.BookArray[i].GetNumber() << endl;
			cout << "Category        : " << lib.BookArray[i].GetCategory() << endl;
			cout << "Information        : " << lib.BookArray[i].GetInformation() << endl;
			cout << endl;
			cout << "Input 0 to exit" << endl;
			cin >> temp;
			while (temp != "0")
				cin >> temp;
			return;
		}
	cout << "Not found this book! " << endl;
	Sleep(1000);
}

