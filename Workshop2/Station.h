#ifndef _STATION_H_
#define _STATION_H_

#include <iostream>
#include <string>


using namespace std;

namespace w2 {

	enum PassType {
		studentPass,
		adultPass
	};

	class Station {
		unsigned int stuPass;
		unsigned int aduPass;
		string stName;


	public:

		Station();
		void set(const string& stationName, unsigned student, unsigned adult);
		void update(PassType kind, int amount);
		unsigned inStock(PassType kind) const;

		const std::string& getName() const;


	};
}

#endif