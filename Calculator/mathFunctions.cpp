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
	if (isRad)
	{
		if (val > 2 * PI)
			val -= val - 2 * PI;
		else if (val < 0)
			val += 0 - val;

		if (compareDouble(val, PI, 0.0000001) ||
			compareDouble(val, 2 * PI, 0.0000001))
			return 0;
		else if (compareDouble(val, PI / 2, 0.0000001))
			return 1;
		else if (compareDouble(val, 3 * PI / 2, 0.0000001))
			return -1;
		else
			return sin(val);
	}
	else
	{

	}
	return 0.0;
}