#include "Task.h"


Task::Task(void) {
}


Task::~Task(void) {
}

void Task::initialize() {
	_taskType = FLOATING;
	_event = "";
	for (int i = 0; i < 3; i++) {
		_startDate[i] = -1;
		_endDate[i] = -1;
		_repeatDate[i] = -1;
	}
	for (int i = 0; i < 2; i++) {
		_startTime[i] = -1;
		_endTime[i] = -1;
	}
	_repeatType = NONE;
	_repeatWeekDay = -1;
	_repeatDayOfMonth = -1;
}

void Task::setTaskType(TaskType taskType) {
	switch (taskType) {
	case FLOATING:
		for (int i = 0; i < 3; i++) {
			_startDate[i] = -1;
			_endDate[i] = -1;
		}
		for (int i = 0; i < 2; i++) {
			_startTime[i] = -1;
			_endTime[i] = -1;
		}
		break;
	case DEADLINE:
		for (int i = 0; i < 3; i++) {
			_endDate[i] = -1;
		}
		for (int i = 0; i < 2; i++) {
			_endTime[i] = -1;
		}
		break;
	case TIMED:
		break;
	default:
		break;
	}

	_taskType = taskType;
}

void Task::setEvent(const string taskEvent) {
	_event = taskEvent;
}

void Task::setStartDate(const int day, const int mon, const int year) {
	_startDate[0] = day;
	_startDate[1] = mon;
	_startDate[2] = year;
}

void Task::setEndDate(const int day, const int mon, const int year) {
	_endDate[0] = day;
	_endDate[1] = mon;
	_endDate[2] = year;
}

void Task::setStartTime(const int hour, const int min) {
	_startTime[0] = hour;
	_startTime[1] = min;
}

void Task::setEndTime(const int hour, const int min) {
	_endTime[0] = hour;
	_endTime[1] = min;
}

TaskType Task::getTaskType() {
	return _taskType;
}

string Task::getEvent() {
	return _event;
}

int *Task::getStartDate() {
	return _startDate;
}

int *Task::getEndDate() {
	return _endDate;
}

int *Task::getStartTime() {
	return _startTime;
}

int *Task::getEndTime() {
	return _endTime;
}