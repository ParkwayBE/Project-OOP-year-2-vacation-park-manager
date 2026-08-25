#include "accommodation.h"
#include <sstream>
#include <iomanip>
void Accommodation::setLuxuryLevel(bool bbq1, bool surroundSystem1, bool breakfastService1, bool cleaningService1, string accommodationKind1) {
	luxuryLevel.setBbq(bbq1);
	luxuryLevel.setSurroundSystem(surroundSystem1);
	luxuryLevel.setBreakfastService(breakfastService1);
	luxuryLevel.setCleaningService(cleaningService1);
	luxuryLevel.setAccommodationKind(accommodationKind1);
}
void Accommodation::setLuxuryLevelQuick(Luxury lux1) {
	luxuryLevel = lux1;
}
Luxury Accommodation::getLuxuryLevel(void) {
	return luxuryLevel;
}
void Accommodation::setID(int ID1) {
	ID = ID1;
}
int Accommodation::getID(void) const {
	return ID;
}
void Accommodation::setMaxAmountPeople(int maxAmountPeople1) {
	maxAmountPeople = maxAmountPeople1;
}
int Accommodation::getMaxAmountPeople(void) {
	return maxAmountPeople;
}
void Accommodation::setSurfaceSize(int surfaceSize1) {
	surfaceSize = surfaceSize1;
}
int Accommodation::getSurfaceSize(void)const {
	return surfaceSize;
}
void Accommodation::setShower(bool shower1) {
	shower = shower1;
}
bool Accommodation::getShower(void) const {
	return shower;
}
void Accommodation::setBathTub(bool bathTub1) {
	bathTub = bathTub1;
}
bool Accommodation::getBathTub(void) const {
	return bathTub;
}
void Accommodation::setPrice(int price1) {
	price = price1;
}
int Accommodation::getPrice(void) const{
	return price;
}

string Accommodation::toString(void) {
	ostringstream output;
	output << fixed << setprecision(2);
	output << "\nID: " << ID <<  "\n"
		<< "Max amount of people: "<< maxAmountPeople << "\n"
		<< "Surface size: "<< surfaceSize << "\n"
		<< "Shower: "  << shower << "\n"
		<< "BathTub: " << bathTub << "\n"
		<< "Price: " << price << "\n";
	return output.str();
}