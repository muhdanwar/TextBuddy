#include "ClearTask.h"


ClearTask::ClearTask(void) {
}


ClearTask::~ClearTask(void) {
}

void ClearTask::execute(vector<Task> *taskVector, Storage *storage) {
	for (unsigned int i = 0; i < taskVector->size(); i++) {
		_taskVector.push_back((*taskVector)[i]);
	}
	taskVector->clear();
}