#ifndef W6_GRADES_H
#define w6_GRADES_H

#include <vector>

namespace w6 {

	class Grades {
	private:
		std::vector<int> stuNo;
		std::vector<double> stuGrade;
		//char letterGrade;

	public:
		Grades();//constructor
		~Grades();//destructor

		Grades(const char* address);


		void displayGrades(std::ostream& os, std::string (*grade)(double grade)) const;
	};

}

#endif