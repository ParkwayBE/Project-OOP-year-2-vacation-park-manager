#include "hotelroom.h"
#include "accommodation.h"

#include <sstream>
#include <iomanip>
void Hotelroom::setFloor(int floor1) {
	floor = floor1;
}
int Hotelroom::getFloor(void) const{
	return floor;
}

void Hotelroom::setLocation(string location1) {
	location = location1;
}
string Hotelroom::getLocation(void) const {
	return location;
}

void Hotelroom::setNrBeds(int nrBeds1) {
	nrBeds = nrBeds1;
}
int Hotelroom::getNrBeds(void) const {
	return nrBeds;
}

void Hotelroom::setChildrenBed(bool childrenBed1) {
	childrenBed = childrenBed1;
}
bool Hotelroom::getChildrenBed(void) const {
	return childrenBed;
}
string Hotelroom::toString(void) {
	
	ostringstream output;
	/*output << fixed << setprecision(20);*/
	output << "\nID: " << setw(30) << left <<  getID() 
		<< "\nMax amount of people: " << setw(30) << getMaxAmountPeople() 
		<< "\nSurface size: "  << setw(30) << getSurfaceSize() 
		<< "\nShower: " << setw(30) << getShower()
		<< "\nBath: " << setw(30) << getBathTub()
		<< "\nFloor: " << setw(30) << floor 
		<< "\nlocation: " << setw(30) << location
		<< "\nNumber of beds: " << setw(30) << nrBeds
		<< "\nchildren bed: " << setw(30) << childrenBed
		<< "\nPrice: " << setw(30) << getPrice() << "\n";
		
						
	return output.str();
}
