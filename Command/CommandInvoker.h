#pragma once
#include <stack>
#include "AddTask.h"
#include "ClearTask.h"
#include "DeleteTask.h"

class CommandInvoker {
private:
	static CommandInvoker *_invokerInstance;

	stack<Command *> *_undo;
	stack<Command *> *_redo;

	CommandInvoker(void);
public:
	static CommandInvoker *getInstance();
	~CommandInvoker(void);

	void executeCommand(Command *, vector<Task> *, Storage *);
	void undo(vector<Task> *, Storage *);
	void redo(vector<Task> *, Storage *);
};