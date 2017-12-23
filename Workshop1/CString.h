#ifndef _CSTRING_H_
#define _CSTRING_H_



extern const int MAX;

using namespace std;

namespace w1 {

	class CString {

		char* strInput;

	public:

		CString(const char* string);
		void display(ostream& obj);
		~CString();
	};

	ostream& operator <<(ostream& obj, CString str);

}

#endif
