//mathFunctions.h
//Justyn P. Durnford
//Izac Lorimer
//Created on 11/09/2019
//Last Updated on 11/09/2019
//Source file for custom widgets. Allows for custom handling of events.

#include <iostream>

#include "customWidgets.hpp"

int count = 0;

int CalcButton::handle (int e) {
  int ret = Fl_Button::handle(e);
  switch (e)
  {
  case FL_KEYUP:
    if (Fl::event_key() == shortcut()) {
      callback()(this, nullptr);
    }
    break;
  
  default:
    break;
  }
  return ret;
}
