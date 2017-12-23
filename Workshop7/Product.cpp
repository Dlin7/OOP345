#include <iomanip>
#include "Product.h"
#include "TaxableProduct.h"

using namespace std;

namespace w7 {

	iProduct* readProduct(std::ifstream& fs) {

		iProduct *product = nullptr;
		int id;
		double price;
		char end;

		fs >> id >> price;
		end = fs.get();

		if (end == ' ') {
			fs >> end;

			if (end == 'H') {
				TaxableProduct* tempProduct = new TaxableProduct(id, price, HST);
				product = tempProduct;
			}

			else if (end == 'P') {

				TaxableProduct* tempProduct = new TaxableProduct(id, price, PST);
				product = tempProduct;
			}
		}

		else {
			Product* tempProduct = new Product(id, price);
			product = tempProduct;
		}

		return product;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct* p) {

		p->display(os);
		return os;
	}

	void Product::display(std::ostream& os) const {
		os << setw(10) << prodNum << right << setw(10) << std::fixed << std::setprecision(2)
			<< Product::getCharge();
	}

}