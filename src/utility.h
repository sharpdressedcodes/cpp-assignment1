#ifndef UTILITY_
#define UTILITY_

#include <iomanip>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Utility {

private:

	/*
	 * Hide the constructors since this is a Singleton implementation.
	 */
	Utility(){}
	Utility(Utility const&){}
	Utility& operator=(Utility const&);//{}

public:

	/*
	 * Staff supplied function.
	 */
	static void clearInputBuffer();

	/*
	 * Custom functions.
	 */
	static int getIntFromConsole(const unsigned int min, const unsigned int max, const string& message, const string& errorMessage, bool allowEmpty);
	static string getStringFromConsole(const unsigned int min, const unsigned int max, const string& message, const string& errorMessage, bool allowEmpty);
	static int stringToInt(const string& str);
	static string intToString(const int number);
	static string floatToString(const float number, const int precision);
	static bool isNumeric(const string& str);
	static bool isDigit(const char c);

};


#endif /* UTILITY_ */
