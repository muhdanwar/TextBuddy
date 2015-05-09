#include "Logic.h"

Logic::Logic(void) {
	_userCommand = "";
	_userInput = "";
	_taskVector = new vector<Task>;
	_resultVector = new vector<string>;

	_parser = _parser->getInstance();
	_storage = _storage->getInstance();
	_options = _options->getInstance();
	_optionsMap = _options->loadOptionsMap();
	_invoker = _invoker->getInstance();
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

vector<string> Logic::getResult() {
	return *_resultVector;
}

void Logic::execute(const string fullInput) {
	_parser->setParserString(fullInput);
	_parser->parse();

	_userCommand = _parser->getUserCommand();
	_userInput = _parser->getUserInput();

	try {
		if (_optionsMap.find(_userCommand) == _optionsMap.end()) {
			throw (std::out_of_range(ERROR_INVALID_COMMAND));
		}
		string userAction = _optionsMap[_userCommand];

		if (userAction == "add") {
			addTask();
		} else if (userAction == "delete") {
			deleteTask();
		} else if (userAction == "clear") {
			clearTask();
		} else if (userAction == "display") {
			display();
		} else if (userAction == "exit") {
			return;
		} else {
			throw (std::out_of_range (ERROR_INVALID_COMMAND));
		}
	} catch (std::out_of_range e) {
		_message = e.what();
	}
}

void Logic::addTask() {
	Task newTask;
	newTask.setEvent(_userInput);
	AddTask *addTask = new AddTask(newTask);

	_invoker->executeCommand(addTask, _taskVector, _storage);

	display();
}

void Logic::deleteTask() {
	display();
}

void Logic::clearTask() {
	ClearTask *clearTask = new ClearTask;

	_invoker->executeCommand(clearTask, _taskVector, _storage);

	display();
}

void Logic::display() {
	_resultVector->clear();

	for (unsigned int i = 0; i < _taskVector->size(); i++) {
		_resultVector->push_back((*_taskVector)[i].getEvent());
	}
}