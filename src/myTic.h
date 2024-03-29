/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

//
//myTic.h
//
// MyTic class
//

#ifndef __MYTIC_H__
#define __MYTIC_H__

/*TO DO  REQUIRED HEADER FILES AND NAMESPACES*/
#include "travelPass.h"
#include "twoHoursZone1.h"
#include "twoHoursZone1And2.h"
#include "allDayZone1.h"
#include "allDayZone1And2.h"
#include <vector>
using std::vector;

class MyTic {

private:

  float credit;
  float limit;
  /*TO DO ANY FURTHER ATTRIBUTES AND CONSTANTS*/
  unsigned int maxPasses;
  vector<TravelPass*> purchases;

public:

  static float MAX_LIMIT;
  static unsigned int AMOUNT_DIVISOR;

  MyTic();
  MyTic(int maxPasses_);
  MyTic(float theCredit, float theLimit, int maxPasses_);
  ~MyTic() ;
  void input();   // Data input for a MyTic object
  void print();  // Data output for a MyTic object

  float getCredit() const;   //Note the use of const
  float getLimit() const;

  unsigned int getMaxPasses() const;
  void setMaxPasses(unsigned int newValue);

  /*TO DO  REQUIRED FUNCTIONS REQUIRED FOR PURCHASING A TRAVEL PASS */

  bool addCredit(float amount);
  bool buyPass(TravelPass* pass);
  void clearPurchases();
  unsigned int getPurchaseCount() const;
  vector<TravelPass*> getPurchases() const;
  float getPurchaseTotal() const;

};

#endif
