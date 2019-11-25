//Error.hpp
//Justyn P. Durnford
//Izac Lorimer
//Created on 11/25/2019
//Last Updated on 11/25/2019
//Header file for error handling

#ifndef ERROR_HPP
#define ERROR_HPP

#include <string>
using std::string;

//Creates a temporary window that will display a message
//that handles an error, telling the user what to do.
//@PARAM const string& msg: Message to display.
void displayError(const string& msg);

#endif