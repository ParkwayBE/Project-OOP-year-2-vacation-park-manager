#pragma once
#include "luxury.h"
#include <string>
using namespace std;
class Accommodation {
private:
	int ID;
	int maxAmountPeople;
	int surfaceSize;
	bool shower;
	bool bathTub;
	int price;
	Luxury luxuryLevel;

public:
	/*luxury level moet vanvoor staan*/
	Accommodation(Luxury luxuryLevel1, int ID1 = 1, int maxAmountPeople1 = 5, int surfaceSize1 = 200, bool shower1 = true, bool bathTub1 = false, int price1 = 300) {
		luxuryLevel = luxuryLevel1;
		ID = ID1;
		maxAmountPeople = maxAmountPeople1;
		surfaceSize = surfaceSize1;
		shower = shower1;
		bathTub = bathTub1;
		price = price1;
	
		
	}
	void setLuxuryLevel(bool, bool, bool, bool, string);
	void setLuxuryLevelQuick(Luxury);
	Luxury getLuxuryLevel(void);
	void setID(int ID1);
	int getID(void) const;
	void setMaxAmountPeople(int maxAmountPeople1);
	int getMaxAmountPeople(void);
	void setSurfaceSize(int surfaceSize1);
	int getSurfaceSize(void)const;
	void setShower(bool shower1);
	bool getShower(void) const;
	void setBathTub(bool bathTub1);
	bool getBathTub(void)const;
	void setPrice(int price1);
	int getPrice(void)const;
	/*virtual getFloor(void);*/
	virtual string toString(void);
};