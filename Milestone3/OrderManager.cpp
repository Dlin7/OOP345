#include <algorithm>

#include "OrderManager.h"
#include "CustomerOrder.h"
#include "Item.h"
#include "ItemManager.h"


CustomerOrder&& OrderManager::extract() {
	return std::move(*this->end());
}

void OrderManager::validate(const ItemManager& itemMng, std::ostream& os) {
	std::vector<CustomerOrder>::iterator iter = this->begin();

	for (; iter != this->end(); iter++) { // iterates through each line record
		for (unsigned int i = 0; i < iter->noOrders(); i++) { // loops through each order
			
			auto validate = [&](const Item& item) {
				return !item.getName().compare((*iter)[i]);
			};

			if (std::find_if(itemMng.cbegin(), itemMng.cend(), validate) == itemMng.cend()) {
				os << (*iter)[i] << " is unavailable " << std::endl;
			}

		}
	}

}

void OrderManager::display(std::ostream& os) const {

	std::vector<CustomerOrder>::const_iterator iter = this->cbegin();
	for (; iter != this->cend(); iter++) {
		iter->display(os);
	}
}