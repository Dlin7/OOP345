#include <vector>

#include "ItemManager.h"
#include "Item.h"

void ItemManager::display(std::ostream& os, bool insert) const {
	std::vector<Item>::const_iterator iter = this->cbegin();

	for (; iter != this->cend(); iter++) {
		iter->display(os, insert);
	}
}