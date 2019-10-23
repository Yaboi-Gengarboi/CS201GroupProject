//mathFunctions.h
//Justyn P. Durnford
//Izac Lorimer
//Created on 10/21/2019
//Finished on
//Source file for functions relating to math

#include "mathFunctions.h"

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

	if (compareDouble(val, 1, 0.000001))
		sinOfVal = 1.0;
	else if (compareDouble(val, -1, 0.000001))
		sinOfVal = -1.0;

	return sinOfVal;
}