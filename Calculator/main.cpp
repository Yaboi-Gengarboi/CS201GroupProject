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


int main()
{
	Fl_Window* mainWindow = new Fl_Window(500, 600); //Length, Height
	Fl_Output* output = new Fl_Output(20, 20, 460, 40); //X, Y, Length, Height

	Fl_Button* button1 = new Fl_Button(340, 80, 40, 40, "1");
	Fl_Button* button2 = new Fl_Button(380, 80, 40, 40, "2");
	Fl_Button* button3 = new Fl_Button(420, 80, 40, 40, "3");
	Fl_Button* button4 = new Fl_Button(340, 120, 40, 40, "4");
	Fl_Button* button5 = new Fl_Button(380, 120, 40, 40, "5");
	Fl_Button* button6 = new Fl_Button(420, 120, 40, 40, "6");
	Fl_Button* button7 = new Fl_Button(340, 160, 40, 40, "7");
	Fl_Button* button8 = new Fl_Button(380, 160, 40, 40, "8");
	Fl_Button* button9 = new Fl_Button(420, 160, 40, 40, "9");

	Fl_Button* button0 = new Fl_Button(40, 80, 40, 40, "0");

	output->value("Hey");
	mainWindow->end();
	mainWindow->show();
	return Fl::run();
}

/*
int main()
{
	return 0;
}
*/