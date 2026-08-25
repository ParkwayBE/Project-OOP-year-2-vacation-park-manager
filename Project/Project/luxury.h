#pragma once
#include <string>
using namespace std;
class Luxury {
protected:
	bool bbq;
	bool surroundSystem;
	bool breakfastService;
	bool cleaningService;
	string accommodationKind;
public:
	Luxury(bool bbq1 = false, bool surroundSystem1 = false, bool breakfastService1 = false, bool cleaningService1 = false, string accommodationKind1 = "Hotelroom") {
		bbq = bbq1;
		surroundSystem = surroundSystem1;
		breakfastService = breakfastService1;
		cleaningService = cleaningService1;
		accommodationKind = accommodationKind1;
	}
	void setBbq(bool bbq1);
	bool getBbq(void)const;

	void setSurroundSystem(bool surroundSystem1);
	bool getSurroundSystem(void)const;

	void setBreakfastService(bool breakfastService1);
	bool getBreakfastService(void) const;

	void setCleaningService(bool cleaningService1);
	bool getCleaningService(void)const;

	void setAccommodationKind(string accommodationKind1);
	string getAccommodationKind(void) const;
	string toString(void);
};