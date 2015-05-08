#pragma once
#include <iostream>
#include <string>
#include "..\Common\Printer.h"
#include "..\Logic\Logic.h"

class UI {

private:
	static UI *_UIInstance;

	Printer *_printer;
	Logic *_logic;

	UI(void);
	~UI(void);
public:
	static UI *getInstance();
	void runUI();
	string getUserInput();
};

