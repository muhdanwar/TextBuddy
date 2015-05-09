#pragma once
#include <sstream>
#include "Command.h"

const string SUCCESS_DELETE = "Successfully deleted line(s): ";
const string ERROR_INVALID_DELETE_INDEX = "Invalid line number(s): ";

class DeleteTask : public Command {
private:
	vector<int> _deletedLines;
	vector<Task> _deletedTasks;
	
	vector<int> _errorLines;
	vector<int> _successLines;

	string _message;
public:
	DeleteTask(vector<int>);
	~DeleteTask(void);

	void execute(vector<Task> *, Storage *);
};

