#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class BooksInfo {
public:
	
	string GetName() { return name; }
	string GetSn() { return Sn; }
	string GetAuthor() { return author; }
	int GetNumber() { return number; }
	int GetCategory() { return category; }
	string GetInformation() { return information; }

	
	void SetName(string new_name) { name = new_name; }
	void SetSn(string new_Sn) { Sn = new_Sn; }
	void SetAuthor(string new_author) { author = new_author; }
	void SetNumber(int new_number) { number = new_number; }
	void SetCategory(int new_category) { category = new_category; }
	void SetInformation(string new_imfor) { information = new_imfor; }

	
private:
	string name;
	string Sn;
	string author;
	int number; 
	int category; 
	string information; 
};

#endif