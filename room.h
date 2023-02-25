#ifndef ROOM_H
#define ROOM_H

#include "event.h"

enum RoomTag {CLOSED, EMPTY, EVENT};

class Room {
private:
	RoomTag m_type{};
	Event* m_event;
public:
	//constructors / destructors
	Room(RoomTag t);
	~Room();

	//getters
	RoomTag getTag();
	Event* getEvent();

	//setters
	void setTag(RoomTag t);
	void setEvent(EventTag e);

	//misc
	std::string display(bool);
};
#endif