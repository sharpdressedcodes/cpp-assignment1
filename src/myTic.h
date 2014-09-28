//
//myTic.h
//
// MyTic class
//

#ifndef __MYTIC_H__
#define __MYTIC_H__


/*TO DO  REQUIRED HEADER FILES AND NAMESPACES*/

class MyTic
{
private:
  float credit;
  float limit;
  /*TO DO ANY FURTHER ATTRIBUTES AND CONSTANTS*/
  
  //const float MAX_LIMIT = 100.0;

public:
  static const float MAX_LIMIT = 100.0;
  static const unsigned int AMOUNT_DIVISOR = 5;

  MyTic();
  MyTic(float theCredit, float theLimit);
  ~MyTic() ;
  void input();   // Data input for a MyTic object
  void print();  // Data output for a MyTic object

  float getCredit() const;   //Note the use of const
  float getLimit() const;

  /*TO DO  REQUIRED FUNCTIONS REQUIRED FOR PURCHASING A TRAVEL PASS */

  bool addCredit(float amount);
};

#endif
