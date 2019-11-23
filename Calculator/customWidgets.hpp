//customWidgets.hpp
//Justyn P. Durnford
//Izac Lorimer
//Created on 11/09/2019
//Last Updated on 11/09/2019
//Source file for custom widgets. Allows for custom handling of events.

#ifndef CUSTOM_WIDGETS_HPP
#define CUSTOM_WIDGETS_HPP

#include <FL/Fl.H>
#include <FL/Fl_Button.H>

/* This button has a c-string tied to it that
will be entered into the inout string in main.cpp */
class numButton : public Fl_Button
{
		public:
			// Constructor for numButton Class
			numButton(int X, int Y, int W, int H, const char* L = 0)
				:Fl_Button(X, Y, W, H, L) {}

			// Handle event
			int handle(int e);
};

//Constructor for CalcButton class
//
class CalcButton : public Fl_Button
{
  public:
    CalcButton (int X, int Y, int W, int H, const char *L = 0)
    :Fl_Button (X, Y, W, H, L) {}
    int handle (int e);
};

#endif