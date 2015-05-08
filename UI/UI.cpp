#include "UI.h"

using namespace std;

UI::UI(void) {
	_logic = _logic->getInstance();
	_printer = _printer->getInstance();
}


UI::~UI(void) {
}

UI *UI::_UIInstance = nullptr;

UI *UI::getInstance() {
	if (_UIInstance == nullptr) {
		_UIInstance = new UI;
	}
	return _UIInstance;
}

void UI::runUI() {
	string userInput;
	while(true) {
		userInput = getUserInput();
		_logic->execute(userInput);
		_printer->colourPrint(_logic->getUserCommand(), RED);
		_printer->printSpaces(1);
		_printer->colourPrint(userInput, YELLOW);
		_printer->printNewlines(1);
		if (_logic->getUserCommand() == "exit") {
			break;
		}
	}
}

string UI::getUserInput() {
	string userInput;
	getline(cin, userInput);
	return userInput;
}