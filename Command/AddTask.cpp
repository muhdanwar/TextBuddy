#include "AddTask.h"

AddTask::AddTask(Task task) {
	_input = task;
}

AddTask::~AddTask(void) {
}

void AddTask::execute(vector<Task> *taskVector, Storage *storage) {
	taskVector->push_back(_input);
}
