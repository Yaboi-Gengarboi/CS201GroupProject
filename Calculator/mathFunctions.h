//mathFunctions.h
//Justyn P. Durnford
//Izac Lorimer
//Created on 10/21/2019
//Finished on
//Header file for functions relating to math

#include <cmath>

const double PI = 3.14159265358979323846;
const double E = 2.71828182845904523536;

//Takes a value, a value to compare it to, and a
//difference and checks if the value and comparison
//are within the difference of eachother.
//@PARAM double val: Value to observe
//@PARAM double comp: Value to compare to
//@PARAM double diff: Diffrence val and comp should
//be within, from 0 to and including diff
//@RETURN true/false
bool compareDouble(double val, double comp, double diff);

//
double getLog(double base, double val);

//
double getSin(double val, bool isRad);

//
double getCos(double val, bool isRad);

//
double getTan(double val, bool isRad);

//
double getPow(double base, double exp);

//
int getFactorial(int num);

//
double getFactorial(double num);