#pragma once
#include <string>
#include <vector>
#include "service.h"
#include "accommodation.h"
using namespace std;
class Parc {
private:
	string name;
	string address;
	Service ExtraServices;
	
public:
	Parc(string name1, string address1, Service service1, vector<Accommodation*>accommodations1){
		name = name1;
		address = address1;
		ExtraServices = service1;
		accommodations = accommodations1;
	}
	vector<Accommodation*> accommodations;
	void setName(string name1);
	string getName(void) const;
	void setAddress(string address1);
	string getAddress(void) const;
	void setExtraService(Service service1);
	Service getExtraServices(void) const;
	void setAccommodations(vector<Accommodation*>);
	vector<Accommodation*> getAccommodations(void) const;
	void addAccommodation(Accommodation*);
	vector<Accommodation*> getTest(void);
	int getSizeOfAcc(void);
};
