#include "gold.h"
/*********************************************************************
** Function:		show()
** Description:		returns an "G" for Rope
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	"G" is returned
*********************************************************************/
std::string Gold::show(){
	return "G";
}

/*********************************************************************
** Function:		getEventType()
** Description:		returns GOLD
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	GOLD is returned
*********************************************************************/
EventTag Gold::getEventType(){
	return GOLD;
}

/*********************************************************************
** Function:		percept()
** Description:		Returns a string informing the player of the contents of the room
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	String informing the player of what is in the room is returned
*********************************************************************/
std::string Gold::percept(){
	return "You notice the shine of bullion in the distance.\n";
}