//mathFunctions.h
//Justyn P. Durnford
//Izac Lorimer
//Created on 10/21/2019
//Finished on
//Source file for functions relating to math

#include "mathFunctions.hpp"

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

bool compareDouble(double val, double comp, double diff)
{
	if (abs(val - comp) <= diff)
		return true;
	return false;
}

double getLog(double base, double val)
{
	return log(val) / log(base);
}

double getSin(double val, bool isRad)
{
	double sinOfVal = 0.0;

	if (isRad)
		sinOfVal = sin(val);
	else
		sinOfVal = sin(val * PI / 180);

	if (compareDouble(sinOfVal, 0, 0.0001))
		sinOfVal = 0.0;

	return sinOfVal;
}

double getCos(double val, bool isRad)
{
	double cosOfVal = 0.0;

	if (isRad)
		cosOfVal = cos(val);
	else
		cosOfVal = cos(val * PI / 180);

	if (compareDouble(cosOfVal, 0, 0.0001))
		cosOfVal = 0.0;

	return cosOfVal;
}