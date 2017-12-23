#include <iostream>
#include "process.h"
#include "CString.h"

using namespace std;

void process(char* string) {
	w1::CString object(string);
	std::cout << object << endl;
	//w1::CString display(string);
}