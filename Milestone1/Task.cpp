#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Task.h"
#include "Utilities.h"


size_t Task::field_width;
Task::Task(const std::string& record) {
	slots = 1;        
	pNextTask[redirect] = nullptr;  
	pNextTask[passed] = nullptr; 

	Utilities read;
	size_t pos = 0;
	std::string token;
	bool more = true;
	


	for (int i = 0; more; i++) { 
		token = read.nextToken(record, pos, more);
		if (!token.empty()) {
			switch (i) {
			case 0:
				name = token;
				break;
			case 1: 
				if (more) {
					slots = token;
				}
				break;
			case 2: 
				nextTask[passed] = token;
				break;
			case 3: 
				nextTask[redirect] = token;
				break;
			}
		}



		if (field_width < read.getFieldWidth()) {
			field_width = read.getFieldWidth(); 
		}
	}

}

bool Task::validate(const Task& pTask) {

	if (pTask.name == nextTask[passed]) {
		pNextTask[passed] = &pTask;
	}
	else if (pTask.name == nextTask[redirect]) {
		pNextTask[redirect] = &pTask;
	}
	return (nextTask[passed].empty() || pNextTask[passed]) 
		&& (nextTask[redirect].empty() || pNextTask[redirect]);
}


const std::string& Task::getName() const {
	return name;
}

unsigned int Task::getSlots() const {
	return stoi(slots);
}

const Task* Task::getNextTask(Quality pValid) const {

	int status;
	if (pNextTask[0] == nullptr) { 
		throw std::string("*** Validate [" + nextTask[passed] + "] @ [" + name + "] ***");
	}

	switch (pValid) {
	case 1:  
		status = passed;
		break;
	case 0:  
		status = redirect;
		break;
	}
	return pNextTask[status];
}

size_t Task::getFieldWidth() {
	return field_width;
}

void Task::display(std::ostream& os) const {
	if (pNextTask[passed]) {
		std::cout << "Task Name    : " << std::setw(16) << "[" + name + "]" << "[" + slots + "]" << std::endl;
		std::cout << " Continue to : " << std::setw(15) << "[" + nextTask[passed] + "]  " << std::endl;
		if (!nextTask[redirect].empty()) {
			std::cout << " Redirect to : " << std::setw(15) << "[" + nextTask[redirect] + "]" << std::endl;
		}
	}
	else {
		if (nextTask[passed].empty()) { 
			std::cout << "Task Name    : " << std::left << std::setw(16) << "[" + name + "]" << "[1]" << std::endl;
		}
		else {
			std::cout << "Task Name    : " << std::left << std::setw(16) << "[" + name + "]" << "[" + slots + "]" << std::endl;
			std::cout << " Continue to : " << std::left << std::setw(16) << "[" + nextTask[passed] + "]" << "*** to be validated ***" << std::endl;

			if (!nextTask[redirect].empty()) {
				std::cout << " Redirect to : " << std::left << std::setw(16) << "[" + nextTask[redirect] + "]" << "*** to be validated ***" << std::endl;

			}
		}
	}

}


