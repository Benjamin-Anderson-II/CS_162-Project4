#include "arrow.h"

/*********************************************************************
** Function:		Constructor
** Description:		Consttructs an Arrow
** Parameters:		(x, y) starting position, and direction of motion
** Pre-Conditions:	(x, y) exists on the map
** Post-Conditions:	Arrow is constructed
*********************************************************************/
Arrow::Arrow(int x, int y, Direction d){
	a_x = x;
	a_y = y;
	dir_of_motion = d;
}

/*********************************************************************
** Function:		getX()
** Description:		returns the x position of the arrow
** Parameters:		none
** Pre-Conditions:	arrow has been constructed
** Post-Conditions:	x position of the arrow is returned
*********************************************************************/
int Arrow::getX(){
	return a_x;
}

/*********************************************************************
** Function:		getY()
** Description:		returns the y position of the arrow
** Parameters:		none
** Pre-Conditions:	arrow has been constructed
** Post-Conditions:	y position of the arrow is returned
*********************************************************************/
int Arrow::getY(){
	return a_y;
}

/*********************************************************************
** Function:		getDirection()
** Description:		returns the direction of the arrow
** Parameters:		none
** Pre-Conditions:	arrow has been constructed
** Post-Conditions:	direction of the arrow is returned
*********************************************************************/
Direction Arrow::getDirection(){
	return dir_of_motion;
}

/*********************************************************************
** Function:		move()
** Description:		adjusts the position of the arrow based on its direction of travel
** Parameters:		none
** Pre-Conditions:	arrow has been constructed
** Post-Conditions:	the arrow is displaced by 1 from where it was before
*********************************************************************/
void Arrow::move(){
	switch(dir_of_motion){
		case NORTH:
		a_y--;
		break;
		case EAST:
		a_x++;
		break;
		case SOUTH:
		a_y++;
		break;
		case WEST:
		a_x--;
		break;
		default: break;
	}
}