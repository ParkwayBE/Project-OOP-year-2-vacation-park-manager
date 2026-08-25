#pragma once
#include <string>
class Service {
private:
	bool swimParadise;
	bool bicycleRent;
	bool bowling;
	bool kidsParadise;
public:
	Service(bool swimParadise1 = false, bool bicycleRent1 = false, bool bowling1 = false, bool kidsParadise1 = false){
		swimParadise = swimParadise1;
		bicycleRent = bicycleRent1;
		bowling = bowling1;
		kidsParadise = kidsParadise1;
	}
	void setSwimParadise(bool swimParadise1);
	bool getSwimParadise(void) const;
	void setBicycleRent(bool bicycleRent1);
	bool getBicycleRent(void) const;
	void setBowling(bool bowling1);
	bool getBowling(void) const;
	void setKidsParadise(bool kidsParadise1);
	bool getKidsParadise(void) const;


};