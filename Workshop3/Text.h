#ifndef W3_TEXT_H_
#define W3_TEXT_H_

#include <fstream>
#include <string>


namespace w3 {

	class Text
	{
	private: 
		std::string* data = nullptr;
		size_t lineCnt = 0;

	public:
		Text();
		Text(char* filename);
		Text(Text& source);
		Text& operator=(Text& operand);
		Text(Text&& source);
		Text& operator=(Text&& operand);
		size_t size() const;

		~Text();
	};

}

#endif

