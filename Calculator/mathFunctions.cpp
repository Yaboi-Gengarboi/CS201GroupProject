//mathFunctions.h
//Justyn P. Durnford
//Izac Lorimer
//Created on 10/21/2019
//Last Updated on 11/25/2019
//Source file for functions relating to math

#include "mathFunctions.hpp"
#include "Error.hpp"

#include <algorithm>
#include <cmath>
using std::abs;
using std::log;
using std::sin;
using std::cos;
using std::tan;
using std::pow;
using std::asin;
using std::acos;
using std::atan2;
using std::tgamma;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;

#include <vector>
using std::vector;

#include <utility>
using std::pair;
using std::make_pair;

#include <iostream>
using std::cout;
using std::endl;

// See mathFunctions.hpp
bool compareDouble(double val, double comp, double diff)
{
	if (abs(val - comp) <= diff)
		return true;
	return false;
}

double evalFunction(vector<string>  parsed) {
	// Check for any values in parentheses
	while (std::find(parsed.begin(), parsed.end(), "(") != parsed.end()) {
		auto opening = std::find(parsed.begin(), parsed.end(), "(");
		auto closing = std::find(opening, parsed.end(), ")");

		// If there's not a matching closing paren, we can't process this.
		if (closing == parsed.end())
			throw;

		// Create a vector and copy over the values inside the parentheses
		// We then evaluate this and replace the parentheses with the result.
		vector<string> subFunction;
		std::copy(opening + 1, closing, std::back_inserter(subFunction));
		*opening = std::to_string(evalFunction(subFunction));
		parsed.erase(opening + 1, closing + 1);
	}

	// Exponents
	while (std::find(parsed.begin(), parsed.end(), "^") != parsed.end()) {
		auto op = std::find(parsed.begin(), parsed.end(), "^");
		string firstStr = *(op - 1);
		string secondStr = *(op + 1);

		// Convert values to doubles from strings.
		istringstream stream(firstStr);
		double first;
		stream >> first;

		istringstream stream2(secondStr);
		double second;
		stream2 >> second;

		if (!stream || !stream2) // Make sure both are converted successfully
			throw;
		
		// Put the result in the vector and remove the operands.
		*(op - 1) = std::to_string(pow(first, second));
		parsed.erase(op, op + 2);
	}

	// Multiplication
	while (std::find(parsed.begin(), parsed.end(), "*") != parsed.end()) {
		auto op = std::find(parsed.begin(), parsed.end(), "*");
		string firstStr = *(op - 1);
		string secondStr = *(op + 1);

		// Convert values to doubles from strings.
		istringstream stream(firstStr);
		double first;
		stream >> first;

		istringstream stream2(secondStr);
		double second;
		stream2 >> second;

		if (!stream || !stream2) // Make sure both are converted successfully
			throw;

		// Put the result in the vector and remove the operands.
		*(op - 1) = std::to_string(first * second);
		parsed.erase(op, op + 2);
	}

	// Division
	while (std::find(parsed.begin(), parsed.end(), "/") != parsed.end()) {
		auto op = std::find(parsed.begin(), parsed.end(), "/");
		string firstStr = *(op - 1);
		string secondStr = *(op + 1);

		// Convert values to doubles from strings.
		istringstream stream(firstStr);
		double first;
		stream >> first;

		istringstream stream2(secondStr);
		double second;
		stream2 >> second;

		if (second == 0.0)
			displayError("ERROR: Divide by 0");

		if (!stream || !stream2) // Make sure both are converted successfully
			throw;

		// Put the result in the vector and remove the operands.
		*(op - 1) = std::to_string(first / second);
		parsed.erase(op, op + 2);
	}

	// Addition
	while (std::find(parsed.begin(), parsed.end(), "+") != parsed.end()) {
		auto op = std::find(parsed.begin(), parsed.end(), "+");
		string firstStr = *(op - 1);
		string secondStr = *(op + 1);

		// Convert values to doubles from strings.
		istringstream stream(firstStr);
		double first;
		stream >> first;

		istringstream stream2(secondStr);
		double second;
		stream2 >> second;

		if (!stream || !stream2) // Make sure both are converted successfully
			throw;

	// Put the result in the vector and remove the operands.
		*(op - 1) = std::to_string(first + second);
		parsed.erase(op, op + 2);
	}

	// Subtraction
	while (std::find(parsed.begin(), parsed.end(), "-") != parsed.end()) {
		auto op = std::find(parsed.begin(), parsed.end(), "-");
		string firstStr = *(op - 1);
		string secondStr = *(op + 1);

		// Convert values to doubles from strings.
		istringstream stream(firstStr);
		double first;
		stream >> first;

		istringstream stream2(secondStr);
		double second;
		stream2 >> second;

		if (!stream || !stream2) // Make sure both are converted successfully
			throw;

		// Put the result in the vector and remove the operands.
		*(op - 1) = std::to_string(first - second);
		parsed.erase(op, op + 2);
	}

	// If we have less than or more than one value in the array
	// at this point, something's not right - probably a letter.
	if (parsed.size() != 1)
		throw;

	istringstream stream(parsed[0]);
	double res;
	stream >> res;
	return res;
}

// Parse string into a function vector and evaluate it.
string doMath(const string& str) {
	vector<string> function;
	bool wasNumber = false;
	for (std::size_t i = 0; i < str.size(); i++) {
		istringstream stream(string(1, str[i]));
		int num;
		stream >> num;
		if (stream && wasNumber) {
			function[function.size() - 1] += string(1, str[i]);
		} else if (stream) {
			function.push_back(string(1, str[i]));
			wasNumber = true;
		} else if (str[i] == '.') {
			function[function.size() - 1] += string(1, str[i]);
		} else {
			function.push_back(string(1, str[i]));
			wasNumber = false;
		}
	}

	return std::to_string(evalFunction(function));
}

// See mathFunctions.hpp
double getLog(double base, double val)
{
	double res = 0.0;

	if (val < 0)
	{

	}
	else 
		res = log(val) / log(base);

	return res;
}

// See mathFunctions.hpp
double getSin(double val, bool isRad)
{
	double sinOfVal = 0.0;

	if (isRad)
		sinOfVal = sin(val);
	else
		sinOfVal = sin(val * PI / 180);

	if (compareDouble(sinOfVal, 0, 0.000001))
		sinOfVal = 0.0;

	return sinOfVal;
}

// See mathFunctions.hpp
double getCos(double val, bool isRad)
{
	double cosOfVal = 0.0;

	if (isRad)
		cosOfVal = cos(val);
	else
		cosOfVal = cos(val * PI / 180);

	if (compareDouble(cosOfVal, 0, 0.000001))
		cosOfVal = 0.0;

	return cosOfVal;
}

// See mathFunctions.hpp
double getTan(double val, bool isRad)
{
	double tanOfVal = 0.0;

	if (isRad)
		tanOfVal = tan(val);
	else
		tanOfVal = tan(val * PI / 180);

	if (compareDouble(tanOfVal, 0, 0.000001))
		tanOfVal = 0.0;
	else if (tanOfVal >= 5.72958e+06) //tan(89.99999)
	{

	}
	else if (tanOfVal <= -5.72958e+06) //tan(-89.99999)
	{

	}

	return tanOfVal;
}

// See mathFunctions.hpp
double getPow(double base, double exp)
{
	double res = 0.0;

	if (base < 0 && abs(exp < 1))
	{
		//Imaginary numbers
	}
	else
		res = pow(base, exp);

	return res;
}

// See mathFunctions.hpp
unsigned long getFactorial(unsigned long num)
{
	unsigned long res = 1;

	for (unsigned long i = 2; i <= num; i++)
		res *= i;

	return res;
}