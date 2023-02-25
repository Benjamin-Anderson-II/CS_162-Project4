#include "bats.h"
/*********************************************************************
** Function:		show()
** Description:		returns an "B" for Rope
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	"B" is returned
*********************************************************************/
std::string Bats::show(){
	return "B";
}

/*********************************************************************
** Function:		getEventType()
** Description:		returns BATS
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	BATS is returned
*********************************************************************/
EventTag Bats::getEventType(){
	return BATS;
}

/*********************************************************************
** Function:		percept()
** Description:		Returns a string informing the player of the contents of the room
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	String informing the player of what is in the room is returned
*********************************************************************/
std::string Bats::percept(){
	return "You hear wings flapping.\n";
}