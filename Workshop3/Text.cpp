#include <fstream>
#include <iostream>
#include <string>

#include "Text.h"


using namespace std;


namespace w3 {
	Text::Text() { //default constructor
		lineCnt = 0;
		data = nullptr;
	}

	Text::Text(char* filename) 
	{

		fstream file;
		string str;
		
		file.open(filename, ios::in | ios::out);
		
		if (file.is_open()) {
			while (getline(file, str)) {
				this->lineCnt++;
			}

			this->data = new string[this->lineCnt];

		}
		else {
			cout << "file cannot be opened" << endl;
		}


	}

	Text::Text(Text& source) { //copy constructor
	


			this->data = new string[source.lineCnt];
			this->lineCnt = source.lineCnt;

			for (size_t i = 0; i < source.lineCnt; i++) {
				this->data[i] = source.data[i];
			}
		


	}

	Text& Text::operator=(Text& operand) {

		if (this != &operand) {
			if (this->data != nullptr) {
				delete[] this->data;
				this->lineCnt = 0;
				this->data = nullptr;
			}

			this->data = new string[operand.lineCnt];
			this->lineCnt = operand.lineCnt;

			for (size_t i = 0; i < operand.lineCnt; i++) {
				this->data[i] = operand.data[i];
			}
		}

		return *this;
	}

	Text::Text(Text&& source) { //move constructor



		this->lineCnt = source.lineCnt;

		this->data = source.data;

		//for (size_t i = 0; i < source.lineCnt; i++) {
		//	this->data[i] = source.data[i];
		//}

		source.data = nullptr;
		source.lineCnt = 0;
	}


	Text& Text::operator=(Text&& operand) {
		

		if (this != &operand) {
			if (this->data != nullptr) {
				delete[] this->data;
				this->lineCnt = 0;
				this->data = nullptr;
			}


			this->lineCnt = operand.lineCnt;

			this->data = operand.data;

			//for (size_t i = 0; i < operand.lineCnt; i++) {
			//	this->data[i] = operand.data[i];
			//}

			operand.data = nullptr;
			operand.lineCnt = 0;
		}

		return *this;
	}

	Text::~Text()
	{
		delete[] this->data;
		this->lineCnt = 0;
	}

	size_t Text::size() const {
		return lineCnt;
	}
}