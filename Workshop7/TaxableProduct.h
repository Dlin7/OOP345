#pragma once

#include "Product.h"
#define HST 0.13
#define PST 0.08

namespace w7 {

	class TaxableProduct : public Product {

	private:
		double prodTax;

	public:
		TaxableProduct(int n, double c, double t) : Product(n, c), prodTax(t) {}
		double getCharge() const;

		void display(std::ostream& os) const;
	};

}