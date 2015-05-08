#include "Logic.h"

Logic::Logic(void) {
	_userCommand = "";
	_userInput = "";

	_parser = _parser->getInstance();
	_storage = _storage->getInstance();
	_options = _options->getInstance();
	_optionsMap = _options->loadOptionsMap();
}

Logic::~Logic(void) {
}

Logic *Logic::_logicInstance = nullptr;

Logic *Logic::getInstance() {
	if (_logicInstance == nullptr) {
		_logicInstance = new Logic;
	}
	return _logicInstance;
}

void Logic::setUserInput(const string input) {
	_userInput = input;
}

string Logic::getUserCommand() {
	return _userCommand;
}

void Logic::execute(const string fullInput) {
	_parser->setParserString(fullInput);
	_parser->parse();

	_userCommand = _parser->getUserCommand();
	_userInput = _parser->getUserInput();


}