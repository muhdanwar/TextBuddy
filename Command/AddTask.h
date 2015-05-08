#pragma once
#include "Command.h"

class AddTask : public Command {
private:
	Task _input;
public:
	AddTask(Task);
	~AddTask(void);

	void execute(vector<Task> *, Storage *);
};

