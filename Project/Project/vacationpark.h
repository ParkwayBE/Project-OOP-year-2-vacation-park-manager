#pragma once
#include <string>
#include <vector>
#include "client.h"
#include "booking.h"
#include "parc.h"
using namespace std;
class VacationPark {
private:
	string name;
	string address;
	string VAT;
	vector<Parc> parcs;
	vector<Client> clients;
public:
	VacationPark(string name1, string address1, string VAT1 , vector<Parc> parcs1, vector<Client> clients1) {
		name = name1;
		address = address1;
		VAT = VAT1;
		parcs = parcs1;
		clients = clients1;
	}
	void setName(string name1);
	string getName(void) const;
	void setAddress(string address1);
	string getAddress(void) const;
	void setVAT(string VAT1);
	string getVAT(void)const;
	void addParc(Parc parc1);
	vector<Parc> getParcs(void)const;
	void setClients(vector<Client>clients1);
	vector<Client> getClients(void) const;
};