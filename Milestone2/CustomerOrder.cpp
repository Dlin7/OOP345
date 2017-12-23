#include "CustomerOrder.h"
#include "CustomerItem.h"
#include "Utilities.h"
#include "Item.h"
#include <iomanip>
#include <vector>

size_t CustomerOrder::field_width;

CustomerOrder::CustomerOrder(const std::string& strName) { //constructor

	order = nullptr;
	nOrders = 0;
	name = "";
	product = "";

	Utilities util;
	bool more = true;
	size_t pos = 0;

	name = util.nextToken(strName, pos, more);
	product = util.nextToken(strName, pos, more);

	while (more) {
		if (nOrders != 0) {
			CustomerItem* temp = new CustomerItem[nOrders];
			for (unsigned int i = 0; i < nOrders; i++) {
				temp[i] = order[i];
			}
			delete[] order;
			order = new CustomerItem[++nOrders];
			for (unsigned int i = 0; i < (nOrders - 1); i++) {
				order[i] = temp[i];
			}
			delete[] temp;

			order[nOrders - 1] = CustomerItem(util.nextToken(strName, pos, more));
		}
		else {
			order = new CustomerItem[++nOrders];
			order[nOrders - 1] = CustomerItem(util.nextToken(strName, pos, more));
		}

	}
	if (field_width < util.getFieldWidth())
		field_width = util.getFieldWidth();
}


CustomerOrder::CustomerOrder(const CustomerOrder&) { // copy constructor should never be called
	std::string errmsg = "Error: copy constructor is called";
	throw errmsg;
}
/*CustomerOrder& CustomerOrder::operator=(const CustomerOrder&) { // copy assignment operator

}*/
CustomerOrder::CustomerOrder(CustomerOrder&& co) NOEXCEPT { // move constructor
	order = nullptr;
    nOrders = 0;
    name = "";
    product = "";
    

	*this = std::move(co);

	co.name = "";
	co.product = "";
	co.order = nullptr;
	co.nOrders = 0;
	co.field_width = 0;
}
CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& co) NOEXCEPT { // move assignment operator
	if (this != &co) {
		if (order) {
			delete[] order;
		}
		name = co.name;
		product = co.product;
		nOrders = co.nOrders;
		order = co.order;

		co.name.clear();
		co.product.clear();
		co.nOrders = 0;
		co.order = nullptr;
	}

	return std::move(*this);
}
CustomerOrder::~CustomerOrder() { //destructor

	delete[] order;
	order = nullptr;
	
}
unsigned int CustomerOrder::noOrders() const { // retrun number of orders
	return nOrders;
}
const std::string& CustomerOrder::operator[](unsigned int i) const {
	if (i >= nOrders) {
		std::string errmsg = "The index is out of bounds";
		throw errmsg;
	}
	return order[i].getName();
}
void CustomerOrder::fill(Item& item) {
	for (unsigned int i = 0; i < nOrders; i++) {
		if (order[i].getName() == item.getName()) {
			order[i].fill(item.getCode());
			item++;
		}
	}
}
void CustomerOrder::remove(Item& item) {
	for (unsigned int i = 0; i < nOrders; i++) {
		if (order[i].getName() == item.getName()) {
			order[i].clear();
		}
	}
}
bool CustomerOrder::empty() const {
	if (name.empty()) {
		return true;
	}
	else {
		return false;
	}
}
void CustomerOrder::display(std::ostream& os) const {
	os << std::left << std::setw(field_width) << name << " : " << std::setw(field_width) << product << std::endl;
	for (unsigned int i = 0; i < nOrders; i++) {
		order[i].display(os);
	}
}