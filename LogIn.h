#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class LogIn {
public:
	void UserLog(string loginname, string username, string operation, int status); 
	void BookLog(string loginname, string bookisbn, string operation, int number); 
};

#endif