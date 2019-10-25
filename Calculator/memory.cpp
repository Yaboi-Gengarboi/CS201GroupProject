//memory.cpp
//Justyn P. Durnford
//Izac Lorimer
//Created on 10/23/2019
//Last Updated on 10/25/2019
//Source file for calculation memory vector

#include "memory.hpp"

using std::vector;

double getMemoryValue(const vector<double>& memory, int index)
{
	double val = 0.0;

	if (index >= memory.size())
	{
		
	}
	else if (index < 0)
	{
		
	}
	else
	{
		val = memory[index];
	}

	return val;
}

void addMemoryValue(vector<double>& memory, double entry)
{
	if (memory.size() < 50)
		memory.push_back(entry);
	else if (memory.size() == 50)
	{
		//We will erase the oldest entry (the value at
		//memory[0] and add a new value at memory[48])
		memory.erase(memory.begin());
		memory.push_back(entry);
	}
}