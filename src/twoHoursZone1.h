//
// twoHoursZone1.h
//
// derived class
//

#ifndef __TWOHOURSZONE1_H__
#define __TWOHOURSZONE1_H__


#include "travelPass.h"

class TwoHoursZone1 : public TravelPass
{

public:
	static const float DEFAULT_PRICE;
	static const string DEFAULT_LENGTH;
	static const string DEFAULT_ZONES;

	TwoHoursZone1();
	TwoHoursZone1(string theLength, string theZones, float theCost);
	~TwoHoursZone1();
	void input();   // Data input for a TwoHoursZone1 object
	void print();   // Data output for a TwoHoursZone1 object
	bool isTravelPass(TravelPass& pUnknown);
	string toString();

	friend ostream& operator<<(ostream& stream, TwoHoursZone1& pass);
	friend istream& operator>>(istream& stream, TwoHoursZone1& pass);
  
};

#endif
