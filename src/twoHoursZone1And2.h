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
	static const float DEFAULT_PRICE = 3.5;

  TwoHoursZone1And2();
  TwoHoursZone1And2(string theLength, string theZones, float theCost);
   ~TwoHoursZone1And2() ; 
  void input() ;   // Data input for a TwoHoursZone1And2 object
  void print() ;  // Data output for a TwoHoursZone1And2 object
  
};

#endif
