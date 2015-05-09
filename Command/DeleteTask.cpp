#include "DeleteTask.h"


DeleteTask::DeleteTask(vector<int> deletedLines) {
	_deletedLines = deletedLines;
	_message = "";
}


DeleteTask::~DeleteTask(void) {
}

void DeleteTask::execute(vector<Task> *taskVector, Storage *storage) {
	int numDeletedTasks = 0;
	for (unsigned int i = 0; i < _deletedLines.size(); i++) {
		_deletedLines[i] -= numDeletedTasks;
		try {
			if (_deletedLines[i] < 0 || _deletedLines[i] >= (int) taskVector->size()) {
				throw (std::out_of_range(ERROR_INVALID_DELETE_INDEX));
			}
			_successLines.push_back(_deletedLines[i]);
			taskVector->erase(taskVector->begin() + _deletedLines[i]);
			numDeletedTasks++;
		} catch (out_of_range e) {
			_errorLines.push_back(_deletedLines[i]);
		}
	}

	ostringstream oss;
	if (_successLines.size() > 0) {
		oss << SUCCESS_DELETE;
		for (unsigned int i = 0; i < _successLines.size(); i++) {
			if (i > 0) {
				oss << ", ";
			}
			oss << _successLines[i];
		}
	}
	if (_errorLines.size() > 0) {
		oss << ", " << ERROR_INVALID_DELETE_INDEX;
		for (unsigned int i = 0; i < _errorLines.size(); i++) {
			if (i > 0) {
				oss << ", ";
			}
			oss << _errorLines[i];
		}
	}
	_message = oss.str();
}