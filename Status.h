#ifndef STATUS_H
#define STATUS_H

#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include "LogIn.h"

using namespace std;

class Status {
public:
	void ListBookAll(); 
	void ListBookByC(); 
	void ListBookByN(); 
	void BookInfor(); 
	void PrintUserArray(); 
	void PrintBookArray(); 
	int IsAllDigit(const string& str);

	string GetUsername() { return username; };
	string GetPassword() { return password; };
	int    GetStatus() { return status; };

	void SetUsername(string name) { username = name; };
	void SetPassword(string pwd) { password = pwd; };
	void SetStatus(int number) { status = number; };


	virtual void Interface(string username) {};
	private:
	int status; 
	string username;
	string password;
};

#endif