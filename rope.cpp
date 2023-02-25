#include "rope.h"
/*********************************************************************
** Function:		show()
** Description:		returns an "R" for Rope
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	"R" is returned
*********************************************************************/
std::string Rope::show(){
	return "R";
}

/*********************************************************************
** Function:		getEventType()
** Description:		returns ROPE
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	ROPE is returned
*********************************************************************/
EventTag Rope::getEventType(){
	return ROPE;
}

/*********************************************************************
** Function:		percept()
** Description:		returns an empty string, because you cant perceive the rope
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	empty string is returned
*********************************************************************/
std::string Rope::percept(){
	return "";
}