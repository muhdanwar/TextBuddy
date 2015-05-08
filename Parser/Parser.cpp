#include "Parser.h"

const string TRIMSTRING_DELIMITERS = " \t\n\v";

Parser *Parser::_parserInstance = nullptr;

Parser *Parser::getInstance() {
	if (_parserInstance == nullptr) {
		_parserInstance = new Parser;
	}
	return _parserInstance;
}

Parser::Parser(void) {
	_parserString = "";
	_userCommand = "";
	_userInput = "";
}

Parser::~Parser(void) {
}

void Parser::setParserString(const string input) {
	_parserString = input;
}

void Parser::parse() {
	extractCommandAndInput();
	convertToLowercase(_userCommand);
	trimString(_userCommand);
	trimString(_userInput);
}

void Parser::extractCommandAndInput() {
	if (_parserString == "") {
		return;
	}

	istringstream iss(_parserString);

	iss >> _userCommand;
	getline(iss, _userInput);
}

void Parser::convertToLowercase(string &input) {
	transform(input.begin(), input.end(), input.begin(), ::tolower);
}

void Parser::trimString(string &input) {
	size_t ptr;

	ptr = input.find_first_not_of(TRIMSTRING_DELIMITERS);
	if (ptr == string::npos) {
		return;
	}
	input = input.substr(ptr);

	ptr = input.find_last_not_of(TRIMSTRING_DELIMITERS);
	if (ptr == string::npos) {
		return;
	}
	input = input.substr(0, ptr + 1);
}

string Parser::getUserCommand() {
	return _userCommand;
}

string Parser::getUserInput() {
	return _userInput;
}