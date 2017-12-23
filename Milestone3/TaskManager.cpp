#include <algorithm>
#include <iostream>
#include <vector>

#include "TaskManager.h"
#include "Task.h"
#include "ItemManager.h"
#include "Item.h"

using namespace std;

void TaskManager::validate(std::ostream& os) {

	size_t orderQty = this->size(); 
	bool valid = true;
	for (auto i = 0u; i < orderQty && valid; i++) { // loop to iterate through the vector container
		bool invalid = true;
		for (auto j = 0u; j < orderQty && invalid; j++) { // loop to iterate through each task 
			if (this->at(i).validate(this->at(j))) {
				invalid = false;
			}
		}
		valid = !invalid;
	}
	if (!valid) {
		std::cerr << "*** Not all Tasks have been validated ***\n";
	}
}

void TaskManager::validate(const ItemManager& task, std::ostream& os) {
	std::vector<Item>::const_iterator iter;
	iter = task.cbegin();

	for (; iter != task.cend(); iter++) {

		auto removerCheck = [&](const Task& task) {
			if (task.getName() == iter->getRemover()) { return true; }
			else { return false; }
		};

		auto fillerCheck = [&](const Task& task) {
			if (task.getName() == iter->getFiller()) { return true; }
			else { return false; }
		};

		if (std::find_if(this->cbegin(), this->cend(), removerCheck) == this->cend()) { // check object for matching remover task
			os << iter->getRemover() << " is unavailable" << endl;
		}

		if (std::find_if(this->cbegin(), this->cend(), fillerCheck) == this->cend()) { // check object for matching filler task
			os << iter->getFiller() << " is unavailable" << endl;
		}

		
	}

}

void TaskManager::display(std::ostream& os) const {
	std::vector<Task>::const_iterator iter = this->cbegin();

	for (; iter != this->cend(); iter++) {
		iter->display(os);
	}
}