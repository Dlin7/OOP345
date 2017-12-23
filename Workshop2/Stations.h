#ifndef _STATIONS_H_
#define _STATIONS_H_

#include <fstream>
#include <string>


#include "Station.h"

using namespace std;

namespace w2 {

	class Stations {
		char* filename;
		int stationsCount;
		Station* stationDB;


	public:
		Stations(char* file);
		void update() const;
		void restock() const;
		void report() const;

		~Stations();

	};

}
#endif
