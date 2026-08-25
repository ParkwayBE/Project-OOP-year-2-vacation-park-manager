#include "vacationpark.h"
void VacationPark::setName(string name1) {
	name = name1;
}
string VacationPark::getName(void) const {
	return name;
}
void VacationPark::setAddress(string address1) {
	address = address1;
}
string VacationPark::getAddress(void) const {
	return address;
}
void VacationPark::setVAT(string VAT1) {
	VAT = VAT1;
}
string VacationPark::getVAT(void)const {
	return VAT;
}
void VacationPark::addParc(Parc parc1) {
	parcs.push_back(parc1);
}
vector<Parc> VacationPark::getParcs(void)const {
	return parcs;
}
void VacationPark::setClients(vector<Client>clients1) {
	clients = clients1;
}
vector<Client> VacationPark::getClients(void) const {
	return clients;
}