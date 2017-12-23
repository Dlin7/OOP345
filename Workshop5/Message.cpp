#include <iostream>
#include <string>
#include <fstream>

#include "Message.h"
#include "Notifications.h"


using namespace std;

namespace w5 {

	Message::Message(std::ifstream& in, char c) {
		string storedTweet;
		string user;
		string reply = "";

		in >> user;

		in.ignore();
		getline(in, storedTweet, c);
	
		if (in.is_open() && !in.eof()) {
			int idx;
			if (storedTweet[0] == '@') { // If the tweet read starts with @ it's a reply
				for (size_t i = 1; i < storedTweet.length(); i++) {

					if (storedTweet[i] != ' ') {
						
						//i = storedTweet.length();
						reply = reply + storedTweet[i];
						
					}
					else {
						i = storedTweet.length();
					}
				}
				idx = storedTweet.find(' ') + 1;
				storedTweet = storedTweet.substr(idx, storedTweet.length());
			}
			/*else {
				storedTweet = storedTweet.substr(reply.length());
			}*/

			
			


	
			if (storedTweet != "" && storedTweet.length() != 0) {
				tweet = tweet + " User  : " + user + "\n";
				if (reply != "") {
					tweet = tweet + " Reply : " + reply + "\n";
				}
				//tweet = tweet + " Tweet : " + storedTweet + std::to_string(storedTweet.length()) + "\n";
				tweet = tweet + " Tweet : " + storedTweet + "\n";
			}
		}
		else {
			tweet = "";
			in.close();
		}

	}

	bool Message::empty() const {
		return tweet == "";
	}

	void Message::display(std::ostream& print) const {
		if (!empty()) {
			print << "Message" << endl;
			print << tweet << endl;
		}

	}


	Message::~Message() {
	}

}