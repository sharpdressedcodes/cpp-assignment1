#include "utility.h"

/*
 * Function to clear the input buffer.
 */
void Utility::clearInputBuffer(){

	char symbol;

	do {
		cin.get(symbol);
	} while(symbol != '\n');

}

int Utility::getIntFromConsole(const unsigned int min, const unsigned int max, const string& message, const string& errorMessage, bool allowEmpty = true){

	int i = -1;
	bool isValid = false;

	while (!isValid){

		string result;

		cout << message;
		getline(cin, result);

		if (cin.fail() || !isNumeric(result)){
			if (!allowEmpty)
				cerr << errorMessage << endl;
			//clearInputBuffer();
		} else {

			i = stringToInt(result);

			if ((unsigned int)i < min || (unsigned int)i > max){
				if (allowEmpty)
					return min - 1;
				cerr << errorMessage << endl;
			} else {
				isValid = true;
			}
		}

	}

	return i;

}

string Utility::getStringFromConsole(const unsigned int min, const unsigned int max, const string& message, const string& errorMessage, bool allowEmpty = true){

	bool isValid = false;
	string result;

	while (!isValid){

		cout << message;
		getline(cin, result);

		if (cin.fail() || result.length() < min || result.length() > max){
			if (allowEmpty)
				return "";
			cerr << errorMessage << endl;
		} else {
			isValid = true;

		}

	}

	return result;

}

int Utility::stringToInt(const string& str){

	long int result;
	istringstream buffer(str);

	buffer >> result;

	return (int)result;

}

string Utility::intToString(const int number){

	std::ostringstream ss;
	ss << number;

	return ss.str();

}

string Utility::floatToString(const float number, const int precision = -1){

	std::stringstream ss;

	if (precision > -1){
		ss.setf(ios::fixed | ios::showpoint);
		ss.precision(precision);
	}

	ss << number;

	return ss.str();

}

bool Utility::isNumeric(const string& str) {

	bool result = true;

	for (string::const_iterator it = str.begin(); it != str.end() && result; ++it)
		result = isDigit((*it));

	return !str.empty() && result;

}

bool Utility::isDigit(const char c){

	bool exists = false;

	for (char letter = '0'; letter != '9' + 1 && !exists; ++letter)
		exists = (letter == c);

	return exists;

}
