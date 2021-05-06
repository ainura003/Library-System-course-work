#include "Library.h"

void Library::LoadUser() { 
	Status olduser;
	string str;
	ifstream fin("Status.txt"); 
	if (!fin) { 
		cerr << "Status.txt can't open" << endl;
		abort();
	}
	while (getline(fin, str)) {
		size_t i = str.find(" "); 
		olduser.SetUsername(str.substr(0, i)); 
		str = str.substr(i + 1);
		i = str.find(" "); 
		olduser.SetPassword(str.substr(0, i)); 
		olduser.SetStatus(stoi(str.substr(i + 1))); 
		UserArray.push_back(olduser); 
	}
	fin.close();
}

void Library::LoadBook() {
	BooksInfo oldbook;
	string str;
	ifstream fin("BooksInfo.txt"); 
	if (!fin) { 
		cerr << "BooksInfo.txt can't open" << endl;
		abort(); 
	}
	while (getline(fin, str)) {
		size_t i = str.find(" "); 
		oldbook.SetName(str.substr(0, i)); 
		str = str.substr(i + 1);

		i = str.find(" "); 
		oldbook.SetSn(str.substr(0, i)); 
		str = str.substr(i + 1);

		i = str.find(" ");
		oldbook.SetAuthor(str.substr(0, i));
		str = str.substr(i + 1);

		i = str.find(" ");
		oldbook.SetNumber(stoi(str.substr(0, i))); 
		str = str.substr(i + 1);

		i = str.find(" ");
		oldbook.SetCategory(stoi(str.substr(0, i))); 
		str = str.substr(i + 1); 
		BookArray.push_back(oldbook); 
	}
	fin.close(); 
}
