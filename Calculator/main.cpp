//main.cpp
//Justyn P. Durnford
//Izac Lorimer
//Created on 9/30/2019
//Last Updated on 10/28/2019
//Main file for calculator project.

#include "mathFunctions.hpp"
#include <vector>
#include <string>
#include <iostream>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>

using std::vector;
using std::string;
using std::cout;
using std::endl;


int main(int argc, char** argv)
{
	Fl_Window* mainWindow = new Fl_Window(500, 600); //Length, Height
	Fl_Output* output = new Fl_Output(20, 20, 100, 50); //X, Y, Length, Height

	
	Fl_Button* button0 = new Fl_Button(40, 60, 40, 40, "0");

	output->value("Hey");
	mainWindow->end();
	mainWindow->show(argc, argv);
	return Fl::run();
}

/*
int main()
{
	return 0;
}
*/