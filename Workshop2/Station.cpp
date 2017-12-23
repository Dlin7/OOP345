#include <iostream>
#include <string>

#include "Station.h"

using namespace std;

namespace w2 {
	Station::Station() {
		stName = "";
		stuPass = 0;
		aduPass = 0;
		
	}

	void Station::set(const string& stationName, unsigned student, unsigned adult) {
		stName = stationName;
		stuPass = student;
		aduPass = adult;

	}

	void Station::update(PassType kind, int amount) {
		switch (kind) {
		case studentPass:
			stuPass += amount;
			break;
		case adultPass:
			aduPass += amount;
			break;
		}

	} 


	unsigned Station::inStock(PassType kind) const {
		switch (kind) {
		case studentPass:
			return stuPass;
		case adultPass:
			return aduPass;
		default:
			return 0;

		}
	}

	const string& Station::getName() const {
		return stName;
	}

}
