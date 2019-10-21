//Placeholder

#include <vector>

//This grabs a double previously generated from
//calculations that will be stored in the memory
//vector in case the user wants to retreive it.
//The vector needs to be at most 50 entries long
//and, of course, must contain the index.
//@PARAM vector<double>& memory: vector containing
//previous calculations.
//@PARAM int index: index of vector to grab double
//@RETURN double: value of calculation memory grabbed 
double getMemoryValue(std::vector<double>& memory, int index);