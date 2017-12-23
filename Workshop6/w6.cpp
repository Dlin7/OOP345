// Workshop 6 - Lambda Expression
// w6.cpp

#include <iostream>
#include <string>
#include "Grades.h"

using namespace w6;
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] <<
			": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << " file_name\n";
		return 1;
	}
	

	Grades grades(argv[1]);
	// define the lambda expression for letter
	

	auto letter = [](double grade) { 
		string letterGrade;

		if (grade >= 90) {
			letterGrade = "A+";
		}
		else if (grade >= 80) {
			letterGrade = "A";
		}
		else if (grade >= 75) {
			letterGrade = "B+";
		}
		else if (grade >= 70) {
			letterGrade = "B";
		}
		else if (grade >= 65) {
			letterGrade = "C+";
		}
		else if (grade >= 60) {
			letterGrade = "C";
		}
		else if (grade >= 55) {
			letterGrade = "D+";
		}
		else if (grade >= 50) {
			letterGrade = "D";
		}
		else if (grade < 50) {
			letterGrade = "F";
		}
		
		return letterGrade;
	
	};

	grades.displayGrades(std::cout, letter); // adds student number and grade to ostream while storing values



	std::cout << "Press any key to continue ... ";
	std::cin.get();
}