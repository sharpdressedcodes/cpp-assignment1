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
	static const float DEFAULT_PRICE = 6.8;

  AllDayZone1And2();
  AllDayZone1And2(string theLength, string theZones, float theCost);
   ~AllDayZone1And2() ; 
  void input() ;   // Data input for a AllDayZone1And2 object
  void print() ;   // Data output for a AllDayZone1And2 object
  
};

#endif
