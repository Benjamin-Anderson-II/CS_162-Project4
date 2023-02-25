#ifndef BATS_H
#define BATS_H

#include "event.h"

class Bats : public Event {
public:
	std::string show();
	EventTag getEventType();
	std::string percept();
};
#endif