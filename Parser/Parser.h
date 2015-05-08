#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Parser {
private:
	static Parser *_parserInstance;

	string _parserString;
	string _userCommand;
	string _userInput;

	Parser(void);
	~Parser(void);
public:
	static Parser *getInstance();
	void setParserString(const string);
	void parse();
	void extractCommandAndInput();
	
	void convertToLowercase(string &);
	void trimString(string &);

	string getUserCommand();
	string getUserInput();
};