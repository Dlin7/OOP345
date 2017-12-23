#include "CustomerItem.h"
#include "Item.h"
#include <iomanip>

CustomerItem::CustomerItem(const std::string& strName) {
	name = strName;
	code = 0;
	filled = false;
}

bool CustomerItem::asksFor(const Item& item) const {
	if (name == item.getName()) {
		return true;
	}
	else {
		return false;
	}
	
}
bool CustomerItem::isFilled() const {
	return filled;
}
void CustomerItem::fill(const unsigned int c) {
	code = c;
	filled = true;
}
void CustomerItem::clear() {
	code = 0;
	filled = false;
}
const std::string& CustomerItem::getName() const {
	return name;
}
void CustomerItem::display(std::ostream& os) const {
	char sign;
	if (filled)	sign = '+';
	else sign = '-';

	if (!name.empty()) {
		os << " " << sign << " [" << std::right << std::setw(CODE_WIDTH)
			<< std::setfill('0') << code << std::setfill(' ') << "] "
			<< name << std::endl;
	}
}