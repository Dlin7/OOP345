#ifndef w5_NOTIFICATIONS_H_
#define w5_NOTIFICATIONS_H_

#include "Message.h"

namespace w5 {

	class Notifications
	{
	private:
		Message* message;
		int count;

	public:
		

		Notifications();
		Notifications(const Notifications& object);
		Notifications& operator=(const Notifications& object);
		Notifications(Notifications&& object);
		Notifications&& operator=(Notifications&& object);

		void operator+=(const Message& msg);
		void display(std::ostream& os) const;
		~Notifications();
	};

}

#endif