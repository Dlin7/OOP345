#include <iostream>
#include <cstring>
#include "CString.h"
#include "process.h"

using namespace std;

const int MAX = 3;

int main(int argc, char* argv[]) {
	//argc = 3;
	//argv[0] = "ws";
	//argv[1] = "oop345";
	//argv[2] = "btp305";


	cout << "Command Line :";

	for (int i = 0; i < argc; i++) {
		cout << " " << argv[i];
	}

	cout << endl;

	if (argc == 1) {	
		cout << "Insufficent number of arguments (Min. 1)" << endl;
		return 0;
	}

	cout << "Maximum number of characters to be stored : " << MAX << endl;

	for (int i = 1; i < argc; i++) {
		process(argv[i]);
	}

	return 0;
}