#pragma once
#include <iostream>
#include <string>
#include <map>
#include "..\Parser\Parser.h"
#include "..\Options\Options.h"
#include "..\Storage\Storage.h"
#include "..\Command\CommandInvoker.h"

using namespace std;

const string ERROR_INVALID_COMMAND = "Invalid Command!";

class Logic {
private:
	static Logic *_logicInstance;

	Parser *_parser;
	Storage *_storage;
	Options *_options;
	CommandInvoker *_invoker;

	string _userCommand;
	string _userInput;
	string _message;
	map<string, string> _optionsMap;

	vector<Task> *_taskVector;

	vector<string> *_resultVector;

	Logic(void);
	~Logic(void);
public:
	static Logic *getInstance();

	void setUserInput(const string);
	string getUserCommand();
	vector<string> getResult();

	void execute(const string);

	void addTask();
	void deleteTask();
	void clearTask();
	void display();
};

