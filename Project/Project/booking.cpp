#include "booking.h"
#include "accommodation.h"
#include <string>
void Booking::setBookingID(int bookingID1) {
	bookingID = bookingID1;
}
int Booking::getBookingID(void) const {
	return bookingID;
}
void Booking::setClient(Client client1) {
	client = client1;
}
Client Booking::getClient(void) const {
	return client;
}
void Booking::setAccommodation(vector<Accommodation> accommodations1) {
	accommodations = accommodations1;
}
vector<Accommodation> Booking::getAccommodation(void) const {
	return accommodations;
}

void Booking::setParc(string parcName) {
	parc = parcName;
}
string Booking::getParc(void) const {
	return parc;
}
void Booking::setPrice(int price1) {
	price = price1;
}
int Booking::getPrice(void) const {
	return price;
}

void Booking::setActivityPass(bool activityPass1) {
	activityPass = activityPass1;
}
bool Booking::getActivityPass(void) const {
	return activityPass;
}
void Booking::setSportsPass(bool sportsPass1) {
	sportsPass = sportsPass1;
}
bool Booking::getSportsPass(void) const {
	return sportsPass;
}
void Booking::setBicycleRent(bool bicycleRent1) {
	bicycleRent = bicycleRent1;
}
bool Booking::getBicycleRent(void) const {
	return bicycleRent;
}
void Booking::setSwimmingPass(bool swimmingPass1) {
	swimmingPass = swimmingPass1;
}
bool Booking::getSwimmingPass(void) const {
	return swimmingPass;
}