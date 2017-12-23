#include <iomanip>
#include "Product.h"
#include "Sale.h"

using namespace std;

namespace w7 {

	Sale::Sale(const char* filename) {

		ifstream fileData(filename, ios::in | ios::out);

		if (fileData.is_open()) {
			while (fileData.good()) {
				products.push_back(readProduct(fileData));
			}
		}
		else {
			cout << "There was an error trying to open the file " << filename << endl;
		}
	}

	void Sale::display(ostream& os) const { // display list

		double customerTotal = 0;
		os << "Product No      Cost Taxable" << endl;

		for (unsigned int i = 0; i < products.size(); i++) {

			os << products[i+1];
			os << endl;
			customerTotal += products[i]->getCharge();
		}

		os << "     Total" << setw(10) << customerTotal << endl;
	}

	Sale::~Sale() { 
		for (auto p : products) delete p; 
	}
}