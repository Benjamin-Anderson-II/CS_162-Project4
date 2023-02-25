#ifndef ROPE_H
#define ROPE_H

#include "event.h"

class Rope : public Event{
public:
	std::string show();
	EventTag getEventType();
	std::string percept();
};
#endif