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
// travelPass.h
//
// Parent TravelPass class
//

#ifndef __TRAVELPASS_H__
#define __TRAVELPASS_H__

#include <string>
#include <iostream>
#include <typeinfo>
#include "utility.h"

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
  virtual ~TravelPass();
  virtual void input() = 0;   // Data input for a TravelPass object
  virtual void print() = 0;  // Data output for a TravelPass object

  virtual string getLength() const;   //Note the use of const
  virtual string getZones() const;
  virtual float getCost() const;

  virtual void setLength(string newLength);
  virtual void setZones(string newZones);
  virtual void setCost(float newCost);
  virtual bool isTravelPass(TravelPass& pUnknown) = 0;
  virtual string toString() = 0;
};

#endif
