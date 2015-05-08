#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

const string DEFAULT_FILENAME = "options.txt";
const string DEFAULT_FILEPATH = "";

const string COMMAND_LIST[] = {
	"add", "delete", "clear", "exit", "display"
};

const int COMMAND_NUM = 5;

class Options {
private:
	string _fileName;
	string _filePath;

	static Options *_optionsInstance;

	Options(void);
	~Options(void);
public:
	static Options *getInstance();
	map<string, string> loadOptionsMap();
	void storeOptionsMap(map<string, string>);
	void verifyOptionsMap(map<string, string> *);
	void completeOptionsMap(map<string, string> *);
	string getFullFileName();
};