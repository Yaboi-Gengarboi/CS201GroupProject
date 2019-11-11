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
#include <FL/Fl_Output.H>

#include "customWidgets.hpp"

using std::vector;
using std::string;
using std::cout;
using std::endl;

struct View {
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

	CalcButton* enter = nullptr;
	CalcButton* del = nullptr;

	Fl_Output* output = nullptr;
};

struct Model {
	char operation = '+';
	double result = 0;
	double currentInput = 0;

	double lastInput = 0;
};

View view;
Model model;

void callback (Fl_Widget* w) {
	model.currentInput = model.currentInput * 10 + w->label()[0] - '0';
	model.lastInput = w->label()[0] - '0';
	string out = lexical_cast<string>(model.currentInput);
	view.output->value(out.c_str());
}

void delCallback (Fl_Widget* w) {
	model.currentInput = (model.currentInput - model.lastInput) / 10;
	string out = lexical_cast<string>(model.currentInput);
	view.output->value(out.c_str());
}

void enterCallback (Fl_Widget* w) {
	model.currentInput = model.currentInput * 10 + w->label()[0] - '0';
	string out = lexical_cast<string>(model.currentInput);
	view.output->value(out.c_str());
}

int main()
{
	Fl_Window* mainWindow = new Fl_Window(500, 600); //Length, Height
	view.output = new Fl_Output(20, 20, 460, 40); //X, Y, Length, Height

	view.button1 = new CalcButton(340, 80, 40, 40, "1");
	view.button2 = new CalcButton(380, 80, 40, 40, "2");
	view.button3 = new CalcButton(420, 80, 40, 40, "3");
	view.button4 = new CalcButton(340, 120, 40, 40, "4");
	view.button5 = new CalcButton(380, 120, 40, 40, "5");
	view.button6 = new CalcButton(420, 120, 40, 40, "6");
	view.button7 = new CalcButton(340, 160, 40, 40, "7");
	view.button8 = new CalcButton(380, 160, 40, 40, "8");
	view.button9 = new CalcButton(420, 160, 40, 40, "9");
	view.buttonE = new CalcButton(340, 200, 40, 40, "e");
	view.button0 = new CalcButton(380, 200, 40, 40, "0");
	view.buttonPI = new CalcButton(420, 200, 40, 40, "pi");
	view.del = new CalcButton(340, 240, 40, 40, "Del");
	view.enter = new CalcButton(380, 240, 80, 40, "Enter");

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
	view.del->callback(delCallback);

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

	view.output->value("...");
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