#include <iomanip>
#include "Product.h"
#include "TaxableProduct.h"

using namespace std;

namespace w7 {


	double TaxableProduct::getCharge() const { 
			return Product::getCharge() * (prodTax); 
		}

	void TaxableProduct::display(ostream& os) const {
		Product::display(os);
		if (prodTax == HST) {
			os << " HST";
		}
		else if (prodTax == PST) {
			os << " PST";
		}
	}


}