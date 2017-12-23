#ifndef w5_MESSAGE_H_
#define w5_MESSAGE_H_

#include <string>


namespace w5 {
	class Message
	{
		std::string tweet;

	public:
		
		Message() { tweet = ""; };
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream&) const;
		~Message();
	};

}

#endif

