#include <string>
#include <iostream>
#include <conio.h> 

using namespace std;

class Password {
public:
	Password() {
		psw = ""; 
		length = 0; 
	}
	void InputPassword();
	string GetPassword() { return psw; } 
	~Password() {};

private:
	string psw;
	int length; 
};