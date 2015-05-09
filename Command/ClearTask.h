#pragma once
#include <vector>
#include "Command.h"

class ClearTask : public Command {
private:
	string _message;
	vector<Task> _taskVector;
public:
	ClearTask(void);
	~ClearTask(void);
	void execute(vector<Task> *, Storage *);
};

