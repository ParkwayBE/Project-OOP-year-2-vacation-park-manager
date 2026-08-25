#pragma once
#include <string>
#include <vector>
#include "service.h"
#include "accommodation.h"
#include "client.h"
using namespace std;

class Booking {
private:
	int bookingID;
	Client client;
	vector<Accommodation> accommodations;

	string parc;
	int price;
	bool activityPass;
	bool sportsPass;
	bool bicycleRent;
	bool swimmingPass;
public:
	Booking(int bookingID1, Client client1, vector<Accommodation> accommodations1, 
		string parc1, int price1, bool activityPass1, bool sportsPass1, bool bicycleRent1, bool swimmingPass1) {
		bookingID = bookingID1;
		client = client1;
		accommodations = accommodations1;
		parc = parc1;
		price = price1;
		activityPass = activityPass1;
		sportsPass = sportsPass1;
		bicycleRent = bicycleRent1;
		swimmingPass = swimmingPass1;

	}
	void setBookingID(int bookingID1);
	int getBookingID(void) const;
	void setClient(Client client1);
	Client getClient(void) const;
	void setAccommodation(vector<Accommodation> accommodation1);
	vector<Accommodation> getAccommodation(void) const;
	
	void setParc(string parcName);
	string getParc(void) const;
	void setPrice(int price1);
	int getPrice(void) const;
	void setActivityPass(bool activityPass1);
	bool getActivityPass(void) const;
	void setSportsPass(bool sportsPass1);
	bool getSportsPass(void) const;
	void setBicycleRent(bool bicycleRent1);
	bool getBicycleRent(void) const;
	void setSwimmingPass(bool swimmingPass1);
	bool getSwimmingPass(void) const;

};