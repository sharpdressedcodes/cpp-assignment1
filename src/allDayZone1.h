//
// allDayZone1.h
//
// derived class
//

#ifndef __ALLDAYZONE1_H__
#define __ALLDAYZONE1_H__


#include "travelPass.h"

class AllDayZone1 : public TravelPass
{

public:
	static const float DEFAULT_PRICE;
	static const string DEFAULT_LENGTH;
	static const string DEFAULT_ZONES;

	AllDayZone1();
	AllDayZone1(string theLength, string theZones, float theCost);
	~AllDayZone1();
	void input();   // Data input for a AllDayZone1 object
	void print();  // Data output for a AllDayZone1object
	bool isTravelPass(TravelPass& pUnknown);
	string toString();

	friend ostream& operator<<(ostream& stream, AllDayZone1& pass);
	friend istream& operator>>(istream& stream, AllDayZone1& pass);

};

#endif
