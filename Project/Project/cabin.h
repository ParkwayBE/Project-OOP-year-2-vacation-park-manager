#pragma once
#include"accommodation.h"
class Cabin : public Accommodation {
private:
	int bedrooms;
public:
	Cabin(Luxury luxury1, int bedrooms1 = 1) : Accommodation(luxury1){
		bedrooms = bedrooms1;
	}
	void setBedrooms(int bedrooms1);
	int getBedrooms(void)const;
	string toString(void);
};