#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>



#include "Station.h"
#include "Stations.h"

using namespace std;

namespace w2 {

	Stations::Stations(char* file) {
		fstream fileInput(file);

		if (!fileInput.is_open()) {
			cout << "error" << file << endl;
		}
		
		fileInput >> stationsCount;
		fileInput.ignore(100, '\n');
		

		stationDB = new Station[stationsCount];

		string stationName;

		unsigned stuPass = 0, aduPass = 0;

		for (int i = 0; i < stationsCount; i++) {
			getline(fileInput, stationName, ';');

			

			fileInput >> stuPass;
			fileInput >> aduPass;

			fileInput.ignore();

			stationDB[i].set(stationName, stuPass, aduPass);
		}

		fileInput.close();
	}

	void Stations::update() const {
		cout << endl << "Passes Sold :" << endl << "-------------" << endl;

		for (int i = 0; i < stationsCount; i++) {
			int soldStu, soldAdu;

			cout << stationDB[i].getName() << endl;
			cout << " Student Passes sold : ";
			cin >> soldStu;
			cout << " Adult   Passes sold : ";
			cin >> soldAdu;
			stationDB[i].update(studentPass, -soldStu);
			stationDB[i].update(adultPass, -soldAdu);
		}
	}
	void Stations::restock() const {
		cout << endl << "Passes Added :" << endl << "--------------" << endl;
	

		for (int i = 0; i < stationsCount; i++) {
			int student, adult;

			cout << stationDB[i].getName() << endl;
			cout << " Student Passes added : ";
			cin >> student;
			cout << " Adult   Passes added : ";
			cin >> adult;
			stationDB[i].update(studentPass, student);
			stationDB[i].update(adultPass, adult);
		}
	}

	void Stations::report() const {
		cout << endl << "Passes in Stock : Student Adult" << endl;
		cout << "-------------------------------" << endl;
		for (int i = 0; i < stationsCount; i++) {

			cout << left << setw(22) << stationDB[i].getName();
			cout << right << setw(3) << stationDB[i].inStock(studentPass);
			cout << right << setw(6) << stationDB[i].inStock(adultPass) << endl;
		}
	}

	Stations::~Stations() {

		if (stationDB) {
			delete[] stationDB;
			stationDB = nullptr;
		}
	}

}



