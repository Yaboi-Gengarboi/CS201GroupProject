//memory.hpp
//Justyn P. Durnford
//Izac Lorimer
//Created on 10/23/2019
//Finished on
//Header file for calculation memory vector

#ifndef MEMORY_HPP
#define MEMOEY_HPP

#include <vector>

//This grabs a double previously generated from
//calculations that will be stored in the memory
//vector in case the user wants to retreive it.
//The vector must contain the index.
//@PARAM vector<double>& memory: vector containing
//previous calculations.
//@PARAM int index: index of vector to grab double
//@RETURN value of calculation memory grabbed 
double getMemoryValue(const std::vector<double>& memory, int index);

#endif