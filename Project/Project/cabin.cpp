#include "cabin.h"
#include <sstream>
#include <iomanip>
void Cabin::setBedrooms(int bedrooms1) {
	bedrooms = bedrooms1;
}
int Cabin::getBedrooms(void)const {
	return bedrooms;
}
string Cabin::toString(void) {
	ostringstream output;
	output << "\nID: " << setw(30) << left << getID()
		<< "\nNumber of bedrooms: " << setw(30) << getBedrooms()
		<< "\nMax amount of people: " << setw(30) << getMaxAmountPeople()
		<< "\nSurface size: " << setw(30) << getSurfaceSize()
		<< "\nShower: " << setw(30) << getShower()
		<< "\nBath: " << setw(30) << getBathTub()
		<< "\nPrice: " << setw(30) << getPrice() << "\n";
	return output.str();
}