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
	static const float DEFAULT_PRICE = 2.5;

  TwoHoursZone1();
  TwoHoursZone1(string theLength, string theZones, float theCost);
   ~TwoHoursZone1() ; 
  void input() ;   // Data input for a TwoHoursZone1 object
  void print() ;   // Data output for a TwoHoursZone1 object
  
};

#endif
