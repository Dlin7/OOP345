#pragma once

#include <vector>
#include <iomanip>

#include "Product.h"

using namespace std;

namespace w7 {

	class Sale {

	private:
		vector <iProduct*> products;

	public:
		Sale(const char* filename);

		void display(ostream& os) const;

		~Sale();

	};

}