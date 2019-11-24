//mathFunctions.hpp
//Justyn P. Durnford
//Izac Lorimer
//Created on 10/21/2019
//Last Updated on 10/25/2019
//Header file for functions relating to math

#ifndef MATH_FUNCTIONS_HPP
#define MATH_FUNCTIONS_HPP

#include <cmath>

#include <string>
using std::string;

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

//Grabs a number from the given string
//between p1 and p2, not including p2.
//@PARAM const string& str: string to grab int from
//@PARAM size_t p1: Start position
//@PARAM size_t p2: End position
double grabNumber(const string& str, size_t p1, size_t p2);

//Takes inputField's line and does the math,
//if it can. There is a priority, of course 
//(PEMDAS), so once we know what operands
//are where, we can use grabInt and grabDouble
//and use the operands to manipulate them.
//There are a few rules:
//	The string cannot be empty
//	There cannot be two adjacent operands
//  (not including ()s).
//	There must be something to the left and
//	right of an operand (not including ()s).
//  There cannot be an operand at then start
//	or end of the string.
//Violation of any of these results in an
//empty string as the return value.
//If there are no operands, the string simply
//matches the input string.
string doMath(const string& str);

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
unsigned long getFactorial(unsigned long num);

//
double getFactorial(double num);

#endif