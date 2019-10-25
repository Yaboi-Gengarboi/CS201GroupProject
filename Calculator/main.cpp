//main.cpp
//Justyn P. Durnford
//Izac Lorimer
//Created on 9/30/2019
//Last Updated on 10/25/2019
//Main file for calculator project.

#include "mathFunctions.hpp"
#include <iostream>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>

int main (int argc, char** argv)
{
	Fl_Window* window = new Fl_Window(500, 600); //Length, Height
	Fl_Box* box = new Fl_Box(20, 20, 460, 100, "Hello, World!"); //X, Y, Length, Height
	Fl_Button* button = new Fl_Button(30, 30, 50, 50); //X, Y, Length, Height
	Fl_Output* output = new Fl_Output(30, 150, 100, 50); //X, Y, Length, Height
	box->box(FL_BORDER_BOX);
	box->labelfont(FL_BOLD);
	box->labelsize(36);
	box->labeltype(FL_SHADOW_LABEL);
	window->end();
	window->show(argc, argv);
	return Fl::run();
}