//
// travelPass.h
//
// Parent TravelPass class
//

#ifndef __TRAVELPASS_H__
#define __TRAVELPASS_H__


#include <string>
#include <iostream>
#include "utility1.h"

using std::string;
using namespace std;


class TravelPass
{
protected:
  string length;
  string zones;
  float cost;
  
public:
  TravelPass();
  TravelPass(string theLength, string theZones, float theCost);
   ~TravelPass() ; 
  void input() ;   // Data input for a TravelPass object
  void print() ;  // Data output for a TravelPass object

  string getLength() const;   //Note the use of const
  string getZones() const; 
  float getCost() const;

  void setLength(string newLength);
  void setZones(string newZones);
  void setCost( float  newCost);
};

#endif
