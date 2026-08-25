#pragma once
#include <string>
#include "accommodation.h"
using namespace std;
class Hotelroom : public Accommodation{
private:
	int floor;
	string location;
	int nrBeds;
	bool childrenBed;
public:
	Hotelroom(Luxury luxury1, int floor1 = 0, string location1 = "frontside", int nrBeds1 = 2, bool childrenBed1 = false) : Accommodation(luxury1){
		
		floor = floor1;
		location = location1;
		nrBeds = nrBeds1;
		childrenBed = childrenBed1;
	}
	void setFloor(int floor1);
	int getFloor(void) const;

	void setLocation(string location1);
	string getLocation(void) const;

	void setNrBeds(int nrBeds1);
	int getNrBeds(void) const;

	void setChildrenBed(bool childrenBed1);
	bool getChildrenBed(void) const;
	string toString(void);

};