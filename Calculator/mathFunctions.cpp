//mathFunctions.h
//Justyn P. Durnford
//Izac Lorimer
//Created on 10/21/2019
//Last Updated on 10/25/2019
//Source file for functions relating to math

#include "mathFunctions.hpp"

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

// See mathFunctions.hpp
double grabNumber(const string& str, size_t p1, size_t p2)
{
	string str2 = str.substr(p1, p2);
	istringstream stream(str2);
	double ret = 0.0;
	stream >> ret;
	return ret;
}

string doMath(const string& str)
{
	double result = 0.0;
	string ret = str;
	bool look = true;
	vector<pair<char, size_t>> operators;
	vector<string> substrs;
	char ops[] = { '(', ')', '^', '*', '/', '+', '-' };
	int i = 0;
	size_t p = 0;

	cout << str << endl;
	//Locates and identifies each operand
	while (i < 7)
	{
		while (look)
		{
			p = str.find(ops[i], p);

			if (p != -1)
			{
				cout << ops[i] << " @ " << p << endl;
				operators.push_back(make_pair(ops[i], p));
				++p;
			}
			else
			{
				look = false;
				p = 0;
				++i;
			}
		}
		look = true;
	}

	//Grab strings in between operands

	return ret;
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