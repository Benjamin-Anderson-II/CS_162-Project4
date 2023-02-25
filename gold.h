#ifndef GOLD_H
#define GOLD_H

#include "event.h"

class Gold : public Event {
public:
	std::string show();
	EventTag getEventType();
	std::string percept();
};
#endif