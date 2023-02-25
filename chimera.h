#ifndef CHIMERA_H
#define CHIMERA_H

#include "event.h"

class Chimera : public Event{
private:
	bool is_slain{};

	int c_x{};
	int c_y{};
public:
	bool isDead();
	int getX();
	int getY();

	void setX(int);
	void setY(int);

	void kill();

	std::string show();
	EventTag getEventType();
	std::string percept();
};
#endif