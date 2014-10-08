//
// twoHoursZone1And2.h
//
// derived class
//

#ifndef __TWOHOURSZONE1AND2_H__
#define __TWOHOURSZONE1AND2_H__


#include "travelPass.h"

class TwoHoursZone1And2 : public TravelPass
{

public:
	static const float DEFAULT_PRICE;
	static const string DEFAULT_LENGTH;
	static const string DEFAULT_ZONES;

	TwoHoursZone1And2();
	TwoHoursZone1And2(string theLength, string theZones, float theCost);
	~TwoHoursZone1And2();
	void input();   // Data input for a TwoHoursZone1And2 object
	void print();  // Data output for a TwoHoursZone1And2 object
	bool isTravelPass(TravelPass& pUnknown);
	string toString();
  
	friend ostream& operator<<(ostream& stream, TwoHoursZone1And2& pass);
	friend istream& operator>>(istream& stream, TwoHoursZone1And2& pass);
};

#endif
