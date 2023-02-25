#include "chimera.h"
#include <iostream>
/*********************************************************************
** Function:		show()
** Description:		returns an "C" for Rope
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	"C" is returned
*********************************************************************/
std::string Chimera::show(){
	return "C";
}

/*********************************************************************
** Function:		getEventType()
** Description:		returns CHIMERA
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	CHIMERA is returned
*********************************************************************/
EventTag Chimera::getEventType(){
	return CHIMERA;
}

/*********************************************************************
** Function:		isDead()
** Description:		returns whether or not the Chimera has been slain
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	is_slain is returned
*********************************************************************/
bool Chimera::isDead(){
	return is_slain;
}

/*********************************************************************
** Function:		getX()
** Description:		returns the x position of the chimera
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	x position of the chimera is returned
*********************************************************************/
int Chimera::getX(){
	return c_x;
}

/*********************************************************************
** Function:		getY()
** Description:		returns the y position of the chimera
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	y position of the chimera is returned
*********************************************************************/
int Chimera::getY(){
	return c_y;
}

/*********************************************************************
** Function:		setX()
** Description:		Sets the x position of the chimera to the given parameter
** Parameters:		number ot set x position to
** Pre-Conditions:	none
** Post-Conditions:	chimera's x position is set to the parameter
*********************************************************************/
void Chimera::setX(int x){
	c_x = x;
}

/*********************************************************************
** Function:		setY()
** Description:		Sets the y position of the chimera to the given parameter
** Parameters:		number ot set y position to
** Pre-Conditions:	none
** Post-Conditions:	chimera's y position is set to the parameter
*********************************************************************/
void Chimera::setY(int y){
	c_y = y;
}

/*********************************************************************
** Function:		kill()
** Description:		Informs the player of the chimera's death and sets is_slain to true
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	is_slain = true
*********************************************************************/
void Chimera::kill(){
	std::cout << "The Chimera is slain! Return to the beginning to complete your quest!\n";
	is_slain = true;
}

/*********************************************************************
** Function:		percept()
** Description:		Returns a string informing the player of the contents of the room
** Parameters:		none
** Pre-Conditions:	none
** Post-Conditions:	String informing the player of what is in the room is returned
*********************************************************************/
std::string Chimera::percept(){
	return "You smell a terrible stench.\n";
}