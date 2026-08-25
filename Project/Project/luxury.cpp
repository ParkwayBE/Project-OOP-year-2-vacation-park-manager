#include "luxury.h"
#include <sstream>
#include <iomanip>
void Luxury::setBbq(bool bbq1) {
	bbq = bbq1;
}
bool Luxury::getBbq(void)const {
	return bbq;
}

void Luxury::setSurroundSystem(bool surroundSystem1) {
	surroundSystem = surroundSystem1;
}
bool Luxury::getSurroundSystem(void)const {
	return surroundSystem;
}

void Luxury::setBreakfastService(bool breakfastService1) {
	breakfastService = breakfastService1;
}
bool Luxury::getBreakfastService(void) const {
	return breakfastService;
}

void Luxury::setCleaningService(bool cleaningService1) {
	cleaningService = cleaningService1;
}
bool Luxury::getCleaningService(void)const {
	return cleaningService;
}

void Luxury::setAccommodationKind(string accommodationKind1) {
	accommodationKind = accommodationKind1;
}
string Luxury::getAccommodationKind(void) const {
	return accommodationKind;
}
string Luxury::toString(void) {

	ostringstream output;
	output << fixed << setprecision(2);
	output << "luxe: " << "\n"
		<< "bbq: " << bbq << "\n"
		<< "surround: " << getSurroundSystem() << "\n"
		<< "breakfast: " << getBreakfastService() << "\n"
		<< "cleaning service:" << getCleaningService() << "\n";


	return output.str();
}