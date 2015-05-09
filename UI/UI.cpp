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
		if (_logic->getUserCommand() == "exit") {
			break;
		}
		generateDisplay(_logic->getResult());
	}
}

string UI::getUserInput() {
	string userInput;
	getline(cin, userInput);
	return userInput;
}

void UI::generateDisplay(vector<string> resultVector) {
	for (unsigned int i = 0; i < resultVector.size(); i++) {
		ostringstream oss;
		oss << i + 1 << ". ";
		_printer->colourPrint(oss.str(), YELLOW);
		_printer->colourPrint(resultVector[i], WHITE);
		_printer->printNewlines(1);
	}
}