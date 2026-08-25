#include "client.h"
#include <sstream>
#include <iomanip>
void Client::setFirstName(string firstName1) {
	firstName = firstName1;
}

string Client::getFirstName(void)const{
	return firstName;
}
void Client::setLastName(string lastName1) {
	lastName = lastName1;
}
string Client::getLastName(void) {
	return lastName;
}

void Client::setAddress(string address1) {
	address = address1;
}
string Client::getAddress(void) const {
	return address;
}

void Client::setMail(string mail1) {
	mail = mail1;
}
string Client::getMail(void) const {
	return mail;
}

string Client::toString(void) const {
	ostringstream output;
	output << fixed << setprecision(2);
	output << "\nFirst name: " << firstName << "\n"
		<< "Last name: " << lastName << "\n"
		<< "Mail: " << mail << "\n";
	return output.str();
}
string Client::toStringFile(void) const {
	ostringstream output;
	output << fixed << setprecision(2);
	output << firstName << "\n"
		<< lastName << "\n"
		<< mail << "\n";
	return output.str();
}