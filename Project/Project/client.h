#pragma once
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
class Client {
private:
	string firstName;
	string lastName;
	string address;
	string mail;
public:
	Client(string firstName1 = "", string lastName1 = "", string address1 = "", string mail1 = "") {
		firstName = firstName1;
		lastName = lastName1;
		address = address1;
		mail = mail1;
	}
	void setFirstName(string firstName1);
	string getFirstName(void)const;

	void setLastName(string lastName1);
	string getLastName(void);

	void setAddress(string address1);
	string getAddress(void) const;

	void setMail(string mail1);
	string getMail(void) const;

	string toString(void) const;
	string toStringFile(void) const;
};