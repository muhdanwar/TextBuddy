#include "CommandInvoker.h"


CommandInvoker::CommandInvoker(void) {
	_undo = new stack<Command *>;
	_redo = new stack<Command *>;
}

CommandInvoker *CommandInvoker::_invokerInstance = nullptr;

CommandInvoker *CommandInvoker::getInstance() {
	if (_invokerInstance == nullptr) {
		_invokerInstance = new CommandInvoker;
	}
	return _invokerInstance;
}

CommandInvoker::~CommandInvoker(void) {
}

void CommandInvoker::executeCommand(Command *command, vector<Task> *taskVector, Storage *storage) {
	command->execute(taskVector, storage);
}

void CommandInvoker::undo(vector<Task> *taskVector, Storage *storage) {
	if (_undo->empty()) {
		return;
	}
}

void CommandInvoker::redo(vector<Task> *taskVector, Storage *storage) {
	if (_redo->empty()) {
		return;
	}
	_redo->top()->execute(taskVector, storage);
}