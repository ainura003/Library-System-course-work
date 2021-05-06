#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "PersonalStaff.h"
class Administrator : public PersonalStaff {
public:
	void AddUser(); 
	void DelUser(); 
	void SetUser(); 
	void Interface(string username);
	private:
	void ListUser();
};
#endif