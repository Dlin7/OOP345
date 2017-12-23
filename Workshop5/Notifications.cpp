#include "Notifications.h"
#include "Message.h"

#include <iostream>

using namespace std;

namespace w5 {

	Notifications::Notifications() {
		count = 0;
		message = nullptr;
	}

	Notifications::Notifications(const Notifications& object) { //copy constructor
		if (count > 0) {
			delete[] message;
			count = 0;
		}

		this->message = new Message[object.count];
		this->count = object.count;

		for (int i = 0; i < object.count; i++) {
			this->message[i] = object.message[i];
		}

	}

	Notifications& Notifications::operator=(const Notifications& object) { //copy assignment operator
		if (this != &object) {
			if (this->message != nullptr) {
				delete[] this->message;
				this->count = 0;
				this->message = nullptr;
			}

			this->message = new Message[object.count];
			this->count = object.count;

			for (int i = 0; i < object.count; i++) {
				this->message[i] = object.message[i];
			}
		}
		return *this;

		/*if (this->count > 0) {
			delete[] message;
			count = 0;
		}
		this->count = object.count;
		this->message = new Message[this->count];
		for (int i = 0; i <count; i++) {
			this->message[i] = object.message[i];
		}
		return *this;*/
	}
	Notifications::Notifications(Notifications&& object) { //move constructor
		this->count = object.count;
		this->message = object.message;

		object.message = nullptr;
		object.count = 0;

		//*this = move(object);

		/*if (this->count > 0) {
			delete[] message;
			count = 0;
		}
		this->count = object.count;
		this->message = object.message;

		object.count = 0;
		delete[] object.message;*/

	}
	Notifications&& Notifications::operator=(Notifications&& object) { //move assignment operator
		if (this != &object) {
			if (this->message != nullptr) {
				delete[] this->message;
				this->count = 0;
				this->message = nullptr;
			}

			this->message = object.message;
			this->count = object.count;

			object.message = nullptr;
			object.count = 0;
		}
		return move(*this);

		/*if (this->count > 0) {
			delete[] message;
			count = 0;
		}
		this->count = object.count;
		this->message = object.message;

		object.count = 0;
		delete[] object.message;
		object.message = nullptr;

		return std::move(*this);*/
	}

	void Notifications::operator+=(const Message& msg) {
		
		Message* newmessage = new Message[count + 1];

		for (int i = 0; i < count; i++) {
			newmessage[i] = message[i];
		}

		newmessage[count] = msg;

		if (this->message != nullptr) {
			delete[] this->message;
		}


		this->message = new Message[count + 1];
		this->message = newmessage;

		newmessage = nullptr;

		count++;

		/*if (this->count < 10) {
			Message* temp = new Message[this->count + 1];
			for (int i = 0; i < this->count; i++)
				temp[i] = this->message[i];

			temp[this->count] = msg;

			if (this->message != nullptr) {
				delete[] message;
			}

			this->message = new Message[this->count + 1];
			this->message = temp;
			this->count++;
			temp = nullptr;
		}*/
	}
	void Notifications::display(ostream& os) const {
		for (int i = 0; i < count; i++) {
			message[i].display(os);
		}
	}


	Notifications::~Notifications() {
		delete[] this->message;
		this->count = 0;

		/*if (this->message != nullptr) {
			delete[] this->message;
			this->message = nullptr;
			this->count = 0;
		}*/
	}

}