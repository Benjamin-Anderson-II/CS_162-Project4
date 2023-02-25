#include "player.h"
using namespace std;

/*********************************************************************
** Function:		Constructor
** Description:		Constructs a player
** Parameters:		position in terms of (x, y)
** Pre-Conditions:	(x, y) mus tbe a location on the map
** Post-Conditions:	a new player is created 
*********************************************************************/
Player::Player(unsigned int x, unsigned int y){
	p_x = x;
	p_y = y;
	has_gold = false;
	num_arrows = 3;
	arrow = nullptr;
}

/*********************************************************************
** Function:		Destructor
** Description:		destroys the player
** Parameters:		none
** Pre-Conditions:	player must exist
** Post-Conditions:	player no longer exists
*********************************************************************/
Player::~Player(){
	delete arrow;
}

/*********************************************************************
** Function:		Copy Constructor
** Description:		constructs a new player as a deep copy of the parameter
** Parameters:		pre-existing player
** Pre-Conditions:	1 player must already exist
** Post-Conditions:	2 identical players now exist
*********************************************************************/
Player::Player(const Player& other){
	num_arrows = other.num_arrows;
	p_x = other.p_x;
	p_y = other.p_y;
	has_gold = other.has_gold;
	if(other.arrow!=nullptr)
		arrow = new Arrow(*other.arrow);
}

/*********************************************************************
** Function:		Assignemnt Operator Overload
** Description:		Makes 1 player a deep copy of another
** Parameters:		pre-existing player
** Pre-Conditions:	2 players must exist
** Post-Conditions:	both players are identical
*********************************************************************/
Player& Player::operator=(const Player& other){
	if(arrow!=nullptr)
		delete arrow;
	num_arrows = other.num_arrows;
	p_x = other.p_x;
	p_y = other.p_y;
	has_gold = other.has_gold;
	if(other.arrow!=nullptr)
		arrow = new Arrow(*other.arrow);

	return *this;
}

/*********************************************************************
** Function:		getX()
** Description:		returns the x position of the player
** Parameters:		none
** Pre-Conditions:	player has been constructed
** Post-Conditions:	x position of the player is returned
*********************************************************************/
unsigned int Player::getX(){
	return p_x;
}

/*********************************************************************
** Function:		getY()
** Description:		returns the y position of the player
** Parameters:		none
** Pre-Conditions:	player has been constructed
** Post-Conditions:	y position of the player is returned
*********************************************************************/
unsigned int Player::getY(){
	return p_y;
}

/*********************************************************************
** Function:		getNumArrows()
** Description:		returns the number of arrows the player has left to use
** Parameters:		none
** Pre-Conditions:	player has been constructed
** Post-Conditions:	current number of arrows the player has available is returned
*********************************************************************/
int Player::getNumArrows(){
	return num_arrows;
}

/*********************************************************************
** Function:		getArrow()
** Description:		returns the player's Arrow
** Parameters:		none
** Pre-Conditions:	player has been constructed
** Post-Conditions:	the player's Arrow has been constructed
*********************************************************************/
Arrow* Player::getArrow(){
	return arrow;
}

/*********************************************************************
** Function:		setX()
** Description:		Sets the x position of the player to the given parameter
** Parameters:		number ot set x position to
** Pre-Conditions:	player must be created
** Post-Conditions:	player's x position is set to the parameter
*********************************************************************/
void Player::setX(unsigned int x){
	p_x = x;
}

/*********************************************************************
** Function:		setY()
** Description:		Sets the y position of the player to the given parameter
** Parameters:		number ot set y position to
** Pre-Conditions:	player must be created
** Post-Conditions:	player's y position is set to the parameter
*********************************************************************/
void Player::setY(unsigned int y){
	p_y = y;
}

/*********************************************************************
** Function:		aquireGold()
** Description:		sets has_gold to true
** Parameters:		none
** Pre-Conditions:	player must exist
** Post-Conditions:	has_gold is true
*********************************************************************/
void Player::aquireGold(){
	has_gold = true;
}

/*********************************************************************
** Function:		isGoldAquired()
** Description:		returns the value of has_gold
** Parameters:		none
** Pre-Conditions:	player has been constructed
** Post-Conditions:	has_gold is returned
*********************************************************************/
bool Player::isGoldAquired(){
	return has_gold;
}

/*********************************************************************
** Function:		loseArrow()
** Description:		decreases num_arrows and deletes current arrow
** Parameters:		none
** Pre-Conditions:	Arrow is constructed
** Post-Conditions:	arrow is destroyed, and the number of available arrows is decreased by 1
*********************************************************************/
void Player::loseArrow(){
	delete arrow;
	num_arrows--;
}