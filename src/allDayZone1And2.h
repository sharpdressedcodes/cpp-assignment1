//
// allDayZone1And2.h
//
// derived class
//

#ifndef __ALLDAYZONE1AND2_H__
#define __ALLDAYZONE1AND2_H__


#include "travelPass.h"

class AllDayZone1And2 : public TravelPass
{

public:
	static const float DEFAULT_PRICE;
	static const string DEFAULT_LENGTH;
	static const string DEFAULT_ZONES;

	AllDayZone1And2();
	AllDayZone1And2(string theLength, string theZones, float theCost);
	~AllDayZone1And2();
	void input();   // Data input for a AllDayZone1And2 object
	void print();   // Data output for a AllDayZone1And2 object
	bool isTravelPass(TravelPass& pUnknown);
	string toString();

	friend ostream& operator<<(ostream& stream, AllDayZone1And2& pass);
	friend istream& operator>>(istream& stream, AllDayZone1And2& pass);

};

#endif
