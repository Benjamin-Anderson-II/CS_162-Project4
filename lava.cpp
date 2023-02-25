#include "lava.h"
/*********************************************************************
** Function:		show()
** Description:		returns an "L" for Rope
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	"L" is returned
*********************************************************************/
std::string Lava::show(){
	return "L";
}

/*********************************************************************
** Function:		getEventType()
** Description:		returns LAVA
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	LAVA is returned
*********************************************************************/
EventTag Lava::getEventType(){
	return LAVA;
}

/*********************************************************************
** Function:		percept()
** Description:		Returns a string informing the player of the contents of the room
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	String informing the player of what is in the room is returned
*********************************************************************/
std::string Lava::percept(){
	return "You feel an intense blast of heat.\n";
}