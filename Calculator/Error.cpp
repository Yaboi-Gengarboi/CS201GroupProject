//Error.cpp
//Justyn P. Durnford
//Izac Lorimer
//Created on 11/25/2019
//Last Updated on 11/25/2019
//Implementation file for error handling

#include "Error.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Multiline_Output.H>

void displayError(const string& msg)
{
	Fl_Window* errorWindow = new Fl_Window(300, 300);
	Fl_Multiline_Output* errorOut = new Fl_Multiline_Output(20, 20, 260, 260);
	errorOut->value(msg.c_str());
}