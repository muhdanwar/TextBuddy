#pragma once

#include <iostream>
#include <string>

using namespace std;

enum TaskType {
	FLOATING, DEADLINE, TIMED
};

enum RepeatType {
	NONE = -1, WEEKDAY, MONTHLY, YEARLY 
};

class Task {
private:
	TaskType _taskType;
	string _event;
	int _startDate[3];
	int _endDate[3];
	int _startTime[2];
	int _endTime[2];
	RepeatType _repeatType;
	int _repeatWeekDay;
	int _repeatDayOfMonth;
	int _repeatDate[3];
public:
	Task(void);
	~Task(void);
	void initialize();
	void setTaskType(TaskType);
	void setEvent(const string);
	void setStartDate(const int, const int, const int);
	void setEndDate(const int, const int, const int);
	void setStartTime(const int, const int);
	void setEndTime(const int, const int);
	TaskType getTaskType();
	string getEvent();
	int *getStartDate();
	int *getEndDate();
	int *getStartTime();
	int *getEndTime();
};

