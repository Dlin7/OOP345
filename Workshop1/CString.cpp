#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CString.h"



namespace w1 {

	CString::CString(const char* string) {

		if (string[0] == '\0') {
			strInput[0] = '\0';
		}
		else {
			strInput = new char[MAX + 1];
			strncpy(strInput, string, MAX + 1);
			strInput[MAX] = '\0';
		}

	}

	void CString::display(std::ostream& obj) {
		obj << strInput;
	}

	CString::~CString() {
		//delete[] strInput;
	}


	std::ostream& operator<<(std::ostream& obj, CString str) {

		static int count = 0;

		obj << count << ": ";
		str.display(obj);
		count++;

		return obj;
	}

}
