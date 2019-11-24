//main.cpp
//Justyn P. Durnford
//Izac Lorimer
//Created on 9/30/2019
//Last Updated on 10/28/2019
//Main file for calculator project.

#include "mathFunctions.hpp"
#include "customWidgets.hpp"

#include <vector>
using std::vector;

#include <string>
using std::string;
using std::to_string;

#include <iostream>
using std::cout;
using std::endl;

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Output.H>

struct View
{
	CalcButton* button1 = nullptr;
	CalcButton* button2 = nullptr;
	CalcButton* button3 = nullptr;
	CalcButton* button4 = nullptr;
	CalcButton* button5 = nullptr;
	CalcButton* button6 = nullptr;
	CalcButton* button7 = nullptr;
	CalcButton* button8 = nullptr;
	CalcButton* button9 = nullptr;
	CalcButton* buttonE = nullptr;
	CalcButton* button0 = nullptr;
	CalcButton* buttonPI = nullptr;

	CalcButton* plus = nullptr;
	CalcButton* minus = nullptr;
	CalcButton* multiply = nullptr;
	CalcButton* divide = nullptr;
	CalcButton* exponent = nullptr;
	CalcButton* parenthesis = nullptr;

	CalcButton* del = nullptr;
	CalcButton* cl = nullptr;
	CalcButton* enter = nullptr;

	Fl_Output* inputField = nullptr;
	Fl_Output* outputField = nullptr;

};

struct Model
{
	string input = "";
	string output = "";
};

View view;
Model model;

// Adds the number to the inputField
void callback(Fl_Widget* w)
{
	model.input += w->label();
	view.inputField->value(model.input.c_str());
}

// Clears input and output fields
void clear(Fl_Widget* w)
{
	model.input = "";
	model.output = "";
	view.inputField->value(model.input.c_str());
	view.outputField->value(model.output.c_str());
}

//
void delCallback(Fl_Widget* w)
{
	if (model.input.rfind("pi") == model.input.size() - 2
		&& model.input.rfind("pi") != -1)
	{
		model.input.pop_back();
		model.input.pop_back();
	}
	else if (model.input.rfind("()") == model.input.size() - 2
		&& model.input.rfind("()") != -1)
	{
		model.input.pop_back();
		model.input.pop_back();
	}
	else if (model.input.size() >= 1)
		model.input.pop_back();
	view.inputField->value(model.input.c_str());
}

//
void enterCallback(Fl_Widget* w)
{
	model.output = model.input;
	view.outputField->value(model.output.c_str());
}

/*
int main()
{
	Fl_Window* mainWindow = new Fl_Window(500, 600); // Length, Height
	view.inputField = new Fl_Output(20, 20, 460, 40); // X, Y, Length, Height
	view.outputField = new Fl_Output(20, 60, 460, 40); // X, Y, Length, Height

	view.button1 = new CalcButton(330, 120, 50, 50, "1");
	view.button2 = new CalcButton(380, 120, 50, 50, "2");
	view.button3 = new CalcButton(430, 120, 50, 50, "3");
	view.button4 = new CalcButton(330, 170, 50, 50, "4");
	view.button5 = new CalcButton(380, 170, 50, 50, "5");
	view.button6 = new CalcButton(430, 170, 50, 50, "6");
	view.button7 = new CalcButton(330, 220, 50, 50, "7");
	view.button8 = new CalcButton(380, 220, 50, 50, "8");
	view.button9 = new CalcButton(430, 220, 50, 50, "9");
	view.buttonE = new CalcButton(330, 270, 50, 50, "e");
	view.button0 = new CalcButton(380, 270, 50, 50, "0");
	view.buttonPI = new CalcButton(430, 270, 50, 50, "pi");

	view.plus = new CalcButton(330, 340, 50, 50, "+");
	view.minus = new CalcButton(380, 340, 50, 50, "-");
	view.multiply = new CalcButton(430, 340, 50, 50, "*");
	view.divide = new CalcButton(330, 390, 50, 50, "/");
	view.exponent = new CalcButton(380, 390, 50, 50, "^");
	view.parenthesis = new CalcButton(430, 390, 50, 50, "()");

	view.del = new CalcButton(330, 440, 50, 40, "Delete");
	view.cl = new CalcButton(380, 440, 50, 40, "Clear");
	view.enter = new CalcButton(430, 440, 50, 40, "Enter");

	view.button1->callback(callback);
	view.button2->callback(callback);
	view.button3->callback(callback);
	view.button4->callback(callback);
	view.button5->callback(callback);
	view.button6->callback(callback);
	view.button7->callback(callback);
	view.button8->callback(callback);
	view.button9->callback(callback);
	view.buttonE->callback(callback);
	view.button0->callback(callback);
	view.buttonPI->callback(callback);

	view.plus->callback(callback);
	view.minus->callback(callback);
	view.multiply->callback(callback);
	view.divide->callback(callback);
	view.exponent->callback(callback);
	view.parenthesis->callback(callback);

	view.del->callback(delCallback);
	view.cl->callback(clear);
	view.enter->callback(enterCallback);

	view.button1->shortcut("1");
	view.button2->shortcut("2");
	view.button3->shortcut("3");
	view.button4->shortcut("4");
	view.button5->shortcut("5");
	view.button6->shortcut("6");
	view.button7->shortcut("7");
	view.button8->shortcut("8");
	view.button9->shortcut("9");
	view.buttonE->shortcut("e");
	view.button0->shortcut("0");
	view.buttonPI->shortcut("p");

	view.del->shortcut(65288);

	//view.plus->shortcut("+");
	//view.minus->shortcut("-");
	//view.multiply->shortcut("*");
	//view.divide->shortcut("/");


	mainWindow->end();
	mainWindow->show();
	return Fl::run();
}
*/

// test
int main()
{
	string str = "50+6/(3-1)+2*(8+4-7)";
	string test = doMath(str);
}