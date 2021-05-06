#ifndef STUDENT_H
#define STUDENT_H

#include "Status.h"
#include "Library.h"

class Student : public Status {
public:
	void GetBook(); 
	void Interface(string username); 
};

#endif
