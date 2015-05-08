#pragma once
#include <iostream>
#include <string>
#include "Windows.h"

using namespace std;

enum Colour {
	BLACK, DARK_BLUE, DARK_GREEN, DARK_TURQOISE, DARK_RED, DARK_PINK, DARK_YELLOW, LIGHT_GREY,
	GREY, BLUE, GREEN, TURQOISE, RED, PINK, YELLOW, WHITE
};

class Printer {
private: 
	static Printer *_printerInstance;

	Printer(void);
	~Printer(void);
public:
	static Printer *getInstance();

	void printSpaces(const int);
	void printNewlines(const int);
	void print(const string);
	void print(const char);
	void colourPrint(const string, const Colour);
	void colourPrint(const char, const Colour);
	void colourPrint(void *(void), const Colour);
};