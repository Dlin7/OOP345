#include <iostream>
#include <string>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include "Utilities.h"


char Utilities::delimiter;
std::ofstream Utilities::logFile;

Utilities::Utilities() {
	field_width = 1;
}

void Utilities::setFieldWidth(size_t fwidth) {
	field_width = fwidth;
}
	
size_t Utilities::getFieldWidth() const {
	return this->field_width;
}
	
const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& more) {

	bool passed = false;
	std::string token;


	try {
		for (int i = next_pos; i < 9999; i++) {
			if (str[0] == delimiter) {
				if (str[i + 1] == delimiter) { 
					next_pos = i + 1;
					throw std::string(str + "<-- *** no token found before the delimiter ***");
				}
				else {
					field_width = str.size();
					throw std::string(str + " <-- *** no token found before the delimiter ***");
				}
			}

			
			if (str[i] == '\0') { 
				token = str.substr(next_pos, i - (next_pos + 1)); // reads up to carriage return

				if (field_width < i - next_pos) {
					field_width = i - next_pos;
				}

				more = false;

				break;
			}
			else if (str[i] == delimiter) {
				token = str.substr(next_pos, i - next_pos);

				if (field_width < i - next_pos) { 
					field_width = i - next_pos;
				}

				if (str[i + 2] == '\0') {
					more = false;
				} 
				else {
					more = true;
				}

				next_pos = i + 1;


				break;
			}
		}

		while (!passed && !token.empty()) { // while token is not empty and not validated
			if (token.at(0) == ' ') { token.erase(0, 1); } // gets rid of empty space at the beginning
			else if (token.back() == ' ') { token.erase(token.length() - 1, 1); } // gets rid of empty space at the end
			else { passed = true; } // If no spaces at beginning or end it validates
		}
	}
	catch (const std::string& error) { 
		std::cout << error << std::endl;
		more = false;
	}
	return token; 
}

void Utilities::setDelimiter(const char pDelim) {
	Utilities::delimiter = pDelim;
}

void Utilities::setLogFile(const char* logfile) {
	logFile.close();
	logFile.open(logfile);
}
	
std::ofstream& Utilities::getLogFile() {
	return logFile;
}
