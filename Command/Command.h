#pragma once
#include <vector>
#include "..\Common\Task.h"
#include "..\Storage\Storage.h"

class Command {
public:
	Command(void);
	~Command(void);
	virtual void execute(vector<Task> *, Storage *);
};