#ifndef PERSONALSTAFF_H
#define PERSONALSTAFF_H

#include "Status.h"
#include "Library.h"

class PersonalStaff : public Status {
public:
	void AddBook(); // Add new books
	void DelBook(); // Delete some books
	void SetBook(); // Change books' information
	void Interface(string username); // Staff interface
};

#endif
