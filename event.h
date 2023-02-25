#ifndef EVENT_H
#define EVENT_H

#include <string>

enum EventTag {NONE, LAVA, BATS, GOLD, CHIMERA, ROPE};

class Event {
public:
	virtual ~Event() = 0;
	virtual std::string show() = 0;
	virtual EventTag getEventType() = 0;
	virtual std::string percept() = 0;
};
#endif