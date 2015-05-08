#pragma once
#include <iostream>
#include <string>
#include <map>
#include "..\Parser\Parser.h"
#include "..\Storage\Storage.h"
#include "..\Options\Options.h"

using namespace std;

class Logic {
private:
	static Logic *_logicInstance;

	Parser *_parser;
	Storage *_storage;
	Options *_options;

	string _userCommand;
	string _userInput;
	map<string, string> _optionsMap;

	Logic(void);
	~Logic(void);
public:
	static Logic *getInstance();

	void setUserInput(const string);
	string getUserCommand();
	
	void execute(const string);
};

