#include "parc.h"
void Parc::setName(string name1) {
	name = name1;
}
string Parc::getName(void) const {
	return name;
}
void Parc::setAddress(string address1) {
	address = address1;
}
string Parc::getAddress(void) const {
	return address;
}
void Parc::setExtraService(Service service1) {
	ExtraServices = service1;
}
Service Parc::getExtraServices(void) const {
	return ExtraServices;
}
void Parc::setAccommodations(vector<Accommodation*>accommodations1) {
	accommodations = accommodations1;
}
vector<Accommodation*> Parc::getAccommodations(void) const{
	return accommodations;
}

void Parc::addAccommodation(Accommodation* acc1)
{
	accommodations.push_back(acc1);
}
vector<Accommodation*> Parc::getTest(void) 
{
	return accommodations;
}
int Parc::getSizeOfAcc(void)
{
	return accommodations.size();
}