//mathFunctions.h
//Justyn P. Durnford
//Izac Lorimer
//Created on 10/21/2019
//Last Updated on 10/25/2019
//Header file for functions relating to math

#ifndef MATH_FUNCTIONS_HPP
#define MATH_FUNCTIONS_HPP

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

//Takes a value and returns the sin of it while
//accounting for the difference between degrees
//and radians. If the calculator is in radian
//mode, isRad will be true. Also gives exactly
//0 if the number is close enough
//(sin(PI) would normally return an extremely
//small number when it should return 0)
//@PARAM double val: Angle to take sin of
//@PARAM bool isRad: Radian mode or not
//@RETURN sin of val
double getSin(double val, bool isRad);

//Takes a value and returns the cos of it while
//accounting for the difference between degrees
//and radians. If the calculator is in radian
//mode, isRad will be true. Also gives exactly
//0 if the number is close enough
//(cos(PI / 2) would normally return an extremely
//small number when it should return 0)
//@PARAM double val: Angle to take cos of
//@PARAM bool isRad: Radian mode or not
//@RETURN cos of val
double getCos(double val, bool isRad);

//
double getTan(double val, bool isRad);

//
double getPow(double base, double exp);

//
int getFactorial(int num);

//
double getFactorial(double num);

#endif