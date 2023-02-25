#include "room.h"
#include "chimera.h"
#include "bats.h"
#include "gold.h"
#include "lava.h"
#include "rope.h"
using namespace std;

/*********************************************************************
** Function:		Constructor
** Description:		Constructs an room
** Parameters:		a tag stating what kind of room it is (EMPTY, CLOSED, EVENT)
** Pre-Conditions:  none
** Post-Conditions:	a new room is created
*********************************************************************/
Room::Room(RoomTag t){
	m_type = t;
	m_event = nullptr;
}

/*********************************************************************
** Function:		Destructor
** Description:		fully deletes the room
** Parameters:		none
** Pre-Conditions:	Room must exist
** Post-Conditions:	Room does not exist
*********************************************************************/
Room::~Room(){
	delete m_event;
	m_event = nullptr;
}

/*********************************************************************
** Function:		getTag()
** Description:		returns the tag variable
** Parameters:		none
** Pre-Conditions:	room has been constructed
** Post-Conditions:	type of room is returned
*********************************************************************/
RoomTag Room::getTag(){
	return m_type;
}

/*********************************************************************
** Function:		setTag()
** Description:		sets the type of room
** Parameters:		type of room to set to
** Pre-Conditions:	t must be a room tag
** Post-Conditions:	typr of room is set to the parameter type
*********************************************************************/
void Room::setTag(RoomTag t){
	m_type = t;
}

/*********************************************************************
** Function:		setEvent()
** Description:		checks the Event type e and creates an event of said type in m_event 
** Parameters:		what event is going in the room
** Pre-Conditions:	e must be an event tag
** Post-Conditions:	a new event has been created in m_event (unless e = NONE)
*********************************************************************/
void Room::setEvent(EventTag e){
	switch(e){
		case NONE:
		delete m_event;
		m_event = nullptr;
		break;
		case LAVA:
		delete m_event;
		m_event = new Lava();
		break;
		case BATS:
		delete m_event;
		m_event = new Bats();
		break;
		case CHIMERA:
		delete m_event;
		m_event = new Chimera();
		break;
		case ROPE:
		delete m_event;
		m_event = new Rope();
		break;
		case GOLD:
		delete m_event;
		m_event = new Gold();
		default: break;
	}
}

/*********************************************************************
** Function:		getEvent()
** Description:		returns a pointer to the event in the room
** Parameters:		none
** Pre-Conditions:	room must exist
** Post-Conditions:	will return the event, nullptr = "no event"
*********************************************************************/
Event* Room::getEvent(){
	return m_event;
}

/*********************************************************************
** Function:		display()
** Description:		prints what is in the room only if debug = true
** Parameters:		bool specifying whether the game is in debug mode
** Pre-Conditions:	room must exist
** Post-Conditions:	String is returned (' ' if debug/empty room)
*********************************************************************/
string Room::display(bool debug){
	if(debug){
		if(m_event!=nullptr)
			return m_event->show();
	}
	return " ";
}