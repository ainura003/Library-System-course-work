#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "BooksInfo.h"
#include "Status.h"

class Library {
public:
	void LoadUser(); 
	void LoadBook(); 
	vector<BooksInfo> BookArray; 
	vector<Status> UserArray; 
};

#endif