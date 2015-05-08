#include "Options.h"


Options::Options(void) {
	_fileName = DEFAULT_FILENAME;
	_filePath = DEFAULT_FILEPATH;
}


Options::~Options(void) {
}

Options *Options::_optionsInstance = nullptr;

Options *Options::getInstance() {
	if (_optionsInstance == nullptr) {
		_optionsInstance = new Options;
	}
	return _optionsInstance;
}

map<string, string> Options::loadOptionsMap() {
	string fullFileName = getFullFileName();
	string userCommand = "";
	string userAction = "";
	fstream inFile;
	map<string, string> optionMap;

	inFile.open(fullFileName, fstream::in);
	while (inFile >> userCommand) {
		inFile >> userAction;
		optionMap[userCommand] = userAction;
	}
	inFile.close();

	try {
		verifyOptionsMap(&optionMap);
	} catch (out_of_range e) {
		completeOptionsMap(&optionMap);
		storeOptionsMap(optionMap);
	}
	return optionMap;
}

void Options::storeOptionsMap(map<string, string> optionsMap) {
	map<string, string>::iterator iter;
	fstream outFile;
	string fullFileName = getFullFileName();

	outFile.open(fullFileName.c_str(), fstream::out, fstream::trunc);
	for (iter = optionsMap.begin(); iter != optionsMap.end(); iter++) {
		outFile << iter->first << ' ' << iter->second << endl;
	}
	outFile.close();
}

void Options::verifyOptionsMap(map<string,string> *optionMap) {
	for (int i = 0; i < COMMAND_NUM; i++) {
		if (optionMap->find(COMMAND_LIST[i]) == optionMap->end()) {
			throw (std::out_of_range(COMMAND_LIST[i]));
		}
	}
}

void Options::completeOptionsMap(map<string, string> *optionMap) {
	for (int i = 0; i < COMMAND_NUM; i++) {
		if (optionMap->find(COMMAND_LIST[i]) == optionMap->end()) {
			(*optionMap)[COMMAND_LIST[i]] = COMMAND_LIST[i];
		}
	}
}

string Options::getFullFileName() {
	if (_filePath != "") {
		return _filePath + "//" + _fileName;
	}
	return _fileName;
}
