//
//myTic.h
//
// MyTic class
//

#ifndef __MYTIC_H__
#define __MYTIC_H__

/*TO DO  REQUIRED HEADER FILES AND NAMESPACES*/
#include "travelPass.h"
#include <vector>
using std::vector;

class MyTic
{
private:
  float credit;
  float limit;
  /*TO DO ANY FURTHER ATTRIBUTES AND CONSTANTS*/
  unsigned int maxPasses;
  vector<TravelPass*> purchases;

public:
  static const float MAX_LIMIT = 100.0;
  static const unsigned int AMOUNT_DIVISOR = 5;

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
  //MAX_TRAVELPASSES

  /*TO DO  REQUIRED FUNCTIONS REQUIRED FOR PURCHASING A TRAVEL PASS */

  bool addCredit(float amount);
  void buyPass(TravelPass* pass);

  bool addPurchase(TravelPass *pUnknown);
  void clearPurchases();
  unsigned int getPurchaseCount() const;
  vector<TravelPass*> getPurchases() const;
  float getPurchaseTotal() const;
};

#endif
