#pragma once

#include "iProduct.h"

namespace w7 {

	class Product : public iProduct {

	private:
		int prodNum;
		double prodCost;

	public:
		Product(int num, double cost) : prodNum(num), prodCost(cost) { }
		double getCharge() const { return prodCost; }
		void display(std::ostream& os) const;
	};

}

