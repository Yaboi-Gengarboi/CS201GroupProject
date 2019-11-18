//mathFunctions.h
//Justyn P. Durnford
//Izac Lorimer
//Created on 10/21/2019
//Last Updated on 10/25/2019
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

//See mathFunctions.hpp
bool compareDouble(double val, double comp, double diff)
{
	if (abs(val - comp) <= diff)
		return true;
	return false;
}

//See mathFunctions.hpp
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

//See mathFunctions.hpp
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

//See mathFunctions.hpp
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

//See mathFunctions.hpp
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

//See mathFunctions.hpp
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

//See mathFunctions.hpp
unsigned long getFactorial(unsigned long num)
{
	unsigned long res = 1;

	for (unsigned long i = 2; i <= num; i++)
		res *= i;

	return res;
}