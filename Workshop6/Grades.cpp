#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Grades.h"

using namespace std;

namespace w6 {

Grades::Grades() // default constructor
{

}
int c = 0;

Grades::Grades(const char* filename) // constructor
{
	ifstream fileData(filename);

	/*try {
		fileData.open(filename);
	}
	catch(const char* message) {
		cout << message;
	}*/

	if (fileData.is_open()) {
		while (fileData.good()) {

			int tempNo;
			double tempGrade;


			fileData >> tempNo;
			fileData >> tempGrade;



			if (fileData.eof()) {
				fileData.close();
			}
			else {
				stuNo.push_back(tempNo);
				stuGrade.push_back(tempGrade);

				tempGrade = 0;
				tempNo = 0;
			}
			

		}
		fileData.close();
	} 
	else {
		throw "The file cannot be opened";
	}

	

	
}



void Grades::displayGrades(std::ostream& os, string (*grade)(double grade)) const {
	
	for (unsigned int i = 0; i < stuNo.size(); i++) {
		
		os << stuNo[i] << " ";
			os << std::setprecision(2) << fixed << stuGrade[i];
		os << " " << grade(stuGrade[i]) << endl;

	}
}

Grades::~Grades() // destructor
{
}
	
}