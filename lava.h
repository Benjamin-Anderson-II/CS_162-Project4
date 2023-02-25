#ifndef LAVA_H
#define LAVA_H
#include "event.h"

class Lava : public Event{
public:
	std::string show();
	EventTag getEventType();
	std::string percept();
};
#endif