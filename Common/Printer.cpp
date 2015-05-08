#include "Printer.h"

static const int defaultColour = LIGHT_GREY;

Printer::Printer(void) {
}


Printer::~Printer(void) {
}

Printer *Printer::_printerInstance = nullptr;

Printer *Printer::getInstance() {
	if (_printerInstance == nullptr) {
		_printerInstance = new Printer;
	}
	return _printerInstance;
}

void Printer::printSpaces(const int n) {
	for (int i = 0; i < n; i++) {
		cout << ' ';
	}
}

void Printer::printNewlines(const int n) {
	for (int i = 0; i < n; i++) {
		cout << endl;
	}
}

void Printer::print(const string output) {
	cout << output;
}

void Printer::print(const char output) {
	cout << output;
}

void Printer::colourPrint(const string output, const Colour colour) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
	cout << output;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultColour);
}

void Printer::colourPrint(const char output, const Colour colour) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
	cout << output;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultColour);
}

void Printer::colourPrint(void *funcPtr(void), const Colour colour) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
	funcPtr();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), defaultColour);
}
