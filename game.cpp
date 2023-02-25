#include "game.h"
#include "room.h"
#include "chimera.h"
#include "bats.h"
#include "gold.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cctype>

using namespace std;

/*********************************************************************
** Function:		Constuctor
** Description:		initializes a Game object
** Parameters:		command line arguments from the main function
** Pre-Conditions:	size must be at least 3
** Post-Conditions:	The board is fully formed, events and all
*********************************************************************/
Game::Game(int size, bool debug){
	is_debug = debug;
	for(int i = 0; i < size+2; i++){
		vector<Room> v;
		for(int j = 0; j < size+2; j++)
			v.push_back(Room(EMPTY));
		map.push_back(v);
	}
	//dig(size*size-size*2); //may or may not use later
	readyRooms();
	placeEvents();
	placePlayer();
}

/*********************************************************************
** Function:		Destrutor
** Description:		deletes all pointers in the member variables
** Parameters:		None
** Pre-Conditions:	Game is over
** Post-Conditions:	Current instance of game object is deleted
*********************************************************************/
Game::~Game(){
	delete player;
}

/*********************************************************************
** Function:		Copy Constructor
** Description:		Constructor that deep copies "other"
** Parameters:		Preformed Game object
** Pre-Conditions:	"other" must be already instantiated
** Post-Conditions:	Two separate objects exist each with the same amount of allocated space and the same variable data
*********************************************************************/
Game::Game(const Game& other){
	is_debug = other.is_debug;
	map = other.map;
	player = new Player(*other.player);
	chimera = dynamic_cast<Chimera*>(map[other.chimera->getY()][other.chimera->getX()].getEvent());
	chimera->setX(other.chimera->getX());
	chimera->setY(other.chimera->getY());
}

/*********************************************************************
** Function:		Assignment Operator Overload
** Description:		Deep copies "other" into the object to the left of the assignment operator
** Parameters:		Preformed Game object
** Pre-Conditions:	two instances of Game must already exist
** Post-Conditions:	The two pre-existing objects now hold the same data
*********************************************************************/
Game& Game::operator=(const Game& other){
	delete player;

	is_debug = other.is_debug;
	map = other.map;
	player = new Player(*other.player);
	chimera = dynamic_cast<Chimera*>(map[other.chimera->getY()][other.chimera->getX()].getEvent());
	chimera->setX(other.chimera->getX());
	chimera->setY(other.chimera->getY());

	return *this;
}

/*********************************************************************
** Function:		readyRooms()
** Description:		changes 7 random rooms to 'Event' rooms
** Parameters:		none
** Pre-Conditions:	layout must be empty rooms surrounded by a wall of closed rooms 
** Post-Conditions:	there will be 7 random rooms that have been converted
*********************************************************************/
void Game::readyRooms(){
	srand(time(NULL));
	/**
	 * Logic:
	 * 1. makes a list with length size*size, 
	 * 2. then removes indices until 7 remain.
	 * 3. convert 1d indeces to 2d indeces and place events at those locations
	*/
	vector<int> indeces;
	for(unsigned int i = 0; i < (map.size()-2)*(map.size()-2); i++)
		indeces.push_back(i);

	int rand_idx;
	while(indeces.size()>7){
		rand_idx = rand() % indeces.size();
		indeces.erase(indeces.begin() + rand_idx);
	}

	for(unsigned int i = 0; i < indeces.size(); i++){
		map[indeces[i]/(map.size()-2)+1][indeces[i]%(map.size()-2)+1].setTag(EVENT);
	}

	for(unsigned int i = 0; i < map.size(); i++){
		map[i][0]. setTag(CLOSED);
		map[0][i]. setTag(CLOSED);
		map[i][map.size()-1].setTag(CLOSED);
		map[map.size()-1][i].setTag(CLOSED);
	}

}

/*********************************************************************
** Function:		placeEvents()
** Description:		puts events in all of the rooms that have the EVENT tag
** Parameters:		none
** Pre-Conditions:	the readyRooms() function must be performed before this one 
** Post-Conditions:	the map will have all of the events laid out
*********************************************************************/
void Game::placeEvents(){
	srand(time(NULL));
	int rand_idx;
	vector<EventTag> events = {LAVA, LAVA, BATS, BATS, GOLD, CHIMERA, ROPE};

	for(unsigned int i = 1; i < map.size(); i++){
		for(unsigned int j = 1; j < map.size(); j++){
			if(map[i][j].getTag()==EVENT){
				rand_idx = rand() % events.size();
				map[i][j].setEvent(events[rand_idx]);
				events.erase(events.begin() + rand_idx);
				if(map[i][j].getEvent()->getEventType()==CHIMERA){
					chimera = dynamic_cast<Chimera*>(map[i][j].getEvent());
					chimera->setX(j);
					chimera->setY(i);
				}
			}
		}
	}
}

/*********************************************************************
** Function:		placePlayer()
** Description:		Places the player at the rope position
** Parameters:		none
** Pre-Conditions:	player must not be placed yet
** Post-Conditions:	new Player object created
*********************************************************************/
void Game::placePlayer(){
	for(unsigned int i = 1; i < map.size()-1; i++){
		for(unsigned int j = 1; j < map.size()-1; j++){
			if(map[i][j].getEvent()==nullptr) continue;
			if(map[i][j].getEvent()->getEventType()==ROPE){
				player = new Player(j, i);
				goto end; // stops loop if item found
			}
		}
	}
	end:;
}

/*********************************************************************
** Function:		play()
** Description:		The main loop for the game
** Parameters:		none
** Pre-Conditions:	There must be a preexisting game Object that is being played through
** Post-Conditions:	The game is over
*********************************************************************/
void Game::play(){
	system("clear");
	system("clear");
	cout << "You enter the cave. Find the gold or kill the chimera to win.\n";

	while(true){
		if(triggerEvents()) break;
		gatherInformation(); // gather percepts in readable format
		displayMap();
		act(); // either shoot or move
	}
	
	if(win)
		cout << "YOU WON!!!!\n";
	else
		cout << "YOU DIED!!\n";
	cout << "GAME OVER\n\n";
}

/*********************************************************************
** Function:		act()
** Description:		gives a way for the player to interact with the map
** Parameters:		none
** Pre-Conditions:	The game is ready to be played
** Post-Conditions:	The character has performed an action
*********************************************************************/
void Game::act(){
	cout << "Direction input sytle: 'wasd'. To fire an arrow press space before the direction.\n";
	string input = "";
	while(!isValidInput(input))
		getline(cin, input);
	switch(input[0]){

		case 'w': // NORTH
		movePlayer(NORTH);
		break;

		case 'a': // WEST
		movePlayer(WEST);
		break;

		case 's': // SOUTH
		movePlayer(SOUTH);
		break;

		case 'd': // EAST
		movePlayer(EAST);
		break;

		case ' ': // FIRE ARROW
		if((player->getNumArrows())>0){
			if(!fireArrow(input[1])){
				relocateChimera();
				cout << "You hear the chimera run into a different room.\n";
			}
		} else
			cout << "No more arrows\n";
		break;
	}
}

/*********************************************************************
** Function:		movePlayer()
** Description:		moves the player in a direction
** Parameters:		direction of motion
** Pre-Conditions:	player and map must exist
** Post-Conditions:	player is 0-1 space from where it started
*********************************************************************/
void Game::movePlayer(Direction dir){
	//NESW
	int p_x = player->getX();
	int p_y = player->getY();
	if(testAhead(p_x, p_y, dir))
		if(dir%2==0) // North/South
			player->setY(p_y+(dir-1));
		else
			player->setX(p_x-(dir-2));
	else
		cout << "You run into a wall.\n";
}

/*********************************************************************
** Function:		testAhead()
** Description:		tests to see if the next room is a closed room or not
** Parameters:		starting x and y, and the direction to check
** Pre-Conditions:	(x, y) must be a location on the map
** Post-Conditions:	a boolean is returned, true for "can move into room," and false for the opposite
*********************************************************************/
bool Game::testAhead(int x, int y, Direction d){
	switch(d){
		case NORTH:
		if(map[y-1][x].getTag()==CLOSED) return false;
		return true;
		break;
		case EAST:
		if(map[y][x+1].getTag()==CLOSED) return false;
		return true;
		break;
		case SOUTH:
		if(map[y+1][x].getTag()==CLOSED) return false;
		return true;
		break;
		case WEST:
		if(map[y][x-1].getTag()==CLOSED) return false;
		return true;
		break;
		default: return false; // STATIONARY / bad input
	}
}

/*********************************************************************
** Function:		fireArrow()
** Description:		fires an arrow in the direction specified from the player's location
** Parameters:		preparsed input from user specifying the direction
** Pre-Conditions:	the parameter character must be w, a, s, or d
** Post-Conditions:	an arrow is fired, and true is returned if the chimera is slain
*********************************************************************/
bool Game::fireArrow(char dir){
	int p_x = player->getX();
	int p_y = player->getY();
	Arrow* arrow = player->getArrow();

	//makes an arrow that will move away from the player
	switch(dir){
		case 'w':
		arrow = new Arrow(p_x, p_y, NORTH);
		break;
		case 'a':
		arrow = new Arrow(p_x, p_y, WEST);
		break;
		case 's':
		arrow = new Arrow(p_x, p_y, SOUTH);
		break;
		case 'd':
		arrow = new Arrow(p_x, p_y, EAST);
		break;
		default: break;
	}

	Room* r;
	for(int i = 0; i < 3; i++){ // will move 3 spaces before falling
		if(!testAhead(arrow->getX(), arrow->getY(), arrow->getDirection())){ // hit a wall
			cout << "Your arrow clinks against the wall.\n";
			break;
		}
		arrow->move();

		//checks if it kills the chimera
		r = &(map[arrow->getY()][arrow->getX()]);
		if( r->getTag()==EVENT &&
			r->getEvent()->getEventType()==CHIMERA){
				dynamic_cast<Chimera*>(r->getEvent()) -> kill();
				r->setTag(EMPTY);
				player->loseArrow();
				return true;
			}
	}
	cout << "Your arrow crashes against the ground.";
	player->loseArrow();
	return false;
}

/*********************************************************************
** Function:		isValidInput()
** Description:		test whether the user input is valid
** Parameters:		user input in string form
** Pre-Conditions:	none
** Post-Conditions:	true for valid false for not
*********************************************************************/
bool Game::isValidInput(string input){
	if(input.length()==0 || input.length()>2) // checks size
		return false;
	char i;
	if(input.length()==1) // for movement
		i = tolower(input[0]);
	else if (input.length()==2 && input[0] == ' ') // for arrow shooting
		i = tolower(input[1]);
	else 
		return false;

	switch(i){ // makes sure the action is happening in a proper direction
		case 'w':
		return true;
		case 'a':
		return true;
		case 's':
		return true;
		case 'd':
		return true;
		default: 
		return false;
	}
}

/*********************************************************************
** Function:		relocateChimera()
** Description:		randomly teleports the chimera to an empty map room
** Parameters:		none
** Pre-Conditions:	chimera and map must exist with at least one empty room
** Post-Conditions:	chimera is no longer in it's starting location, or on the player
*********************************************************************/
void Game::relocateChimera(){
	//get old loc before removing
	int old_x = chimera->getX();
	int old_y = chimera->getY();

	//get all Rooms with EMPTY tag
	int new_index = getRandEmptyRoomIdx();

	//reset old room to basic room
	map[old_y][old_x].setEvent(NONE); // deletes the old Chimera
	map[old_y][old_x].setTag(EMPTY);

	//make a pointer so it doesn't delete the actual room at the end of the funct
	Room* new_room = &(map[new_index/map.size()][new_index%map.size()]);
	new_room->setTag(EVENT);
	new_room->setEvent(CHIMERA);
	chimera = dynamic_cast<Chimera*>(new_room->getEvent());
	chimera->setX(new_index%map.size());
	chimera->setY(new_index/map.size());
}

/*********************************************************************
** Function:		gatherInformation()
** Description:		prints all of the percepts from the events surrounding the player
** Parameters:		none
** Pre-Conditions:	map and player must exist
** Post-Conditions:	a string stating what is surrounding the player is printed
*********************************************************************/
void Game::gatherInformation(){
	int p_x = player->getX();
	int p_y = player->getY();
	string to_print = "--------------------------------------------------\n";
	
	//check North
	if(map[p_y-1][p_x].getEvent()!=nullptr && map[p_y-1][p_x].getTag()!=CLOSED)
		to_print += map[p_y-1][p_x].getEvent()->percept();
	//check South
	if(map[p_y+1][p_x].getEvent()!=nullptr && map[p_y+1][p_x].getTag()!=CLOSED)
		to_print += map[p_y+1][p_x].getEvent()->percept();
	//check West
	if(map[p_y][p_x-1].getEvent()!=nullptr && map[p_y][p_x-1].getTag()!=CLOSED)
		to_print += map[p_y][p_x-1].getEvent()->percept();
	//check East
	if(map[p_y][p_x+1].getEvent()!=nullptr && map[p_y][p_x+1].getTag()!=CLOSED)
		to_print += map[p_y][p_x+1].getEvent()->percept();

	to_print += "--------------------------------------------------\n";
	cout << to_print;
}

/*********************************************************************
** Function:		triggerEvent()
** Description:		triggers an event if the player is standing in an event room
** Parameters:		none
** Pre-Conditions:	player and map must exist
** Post-Conditions:	returns whether or not the game is over (true = over)
*********************************************************************/
bool Game::triggerEvents(){
	int p_x = player->getX();
	int p_y = player->getY();

	//if the player is on an event tile trigger the event
	if(map[p_y][p_x].getTag()==EVENT){
		switch(map[p_y][p_x].getEvent()->getEventType()){

			case LAVA:
			cout << "You burn to death in lava\n";
			win = false;
			return true;

			case BATS:{
				cout << "The bats carry you away to a random room.\n";
				int new_loc = getRandEmptyRoomIdx();
				player->setX(new_loc%map.size());
				player->setY(new_loc/map.size());
			}
			break;
			case GOLD:
			cout << "You aquired the gold\n";
			player->aquireGold();
			map[p_y][p_x].setEvent(NONE);
			map[p_y][p_x].setTag(EMPTY);
			break;

			case ROPE:
			if(chimera->isDead() || player->isGoldAquired()){
				win = true;
				return true;
			}
			break;

			case CHIMERA:
			if(!chimera->isDead()){
				cout << "The chimera kills you.\n";
				win = false;
				return true;
			}
			break;
			default: 
			cout << "You Broke It...\n";
			break;
		}
	}
	return false;
}

/*********************************************************************
** Function:		getRandEmptyRoomIdx()
** Description:		gets the index of a random empty room excluding the player's location
** Parameters:		none
** Pre-Conditions:	map must exist
** Post-Conditions:	index of an empty room is returned
*********************************************************************/
int  Game::getRandEmptyRoomIdx(){
	int num_empty_rooms = (map.size()-2)*(map.size()-2)-7;
	int empty_room_indexes[num_empty_rooms];
	int counter = 0;
	for(unsigned int i = 0; i < map.size(); i++){
		for(unsigned int j = 0; j < map.size(); j++){
			if(map[i][j].getTag()==EMPTY //room is empty
				&&  !(i==player->getY()
					&&j==player->getX())){ // not at player's loc
					empty_room_indexes[counter] = i*map.size()+j;
					counter++;
				}
		}
	}
	srand(time(NULL));
	return empty_room_indexes[rand()%num_empty_rooms];
}

/*********************************************************************
** Function:		displayMap()
** Description:		displays the map in a readable format. Will print Event locations if debug is enabled
** Parameters:		none
** Pre-Conditions:	both map and player exist
** Post-Conditions:	readable map is printed to the board
*********************************************************************/
void Game::displayMap(){
	unsigned int player_x = player->getX();
	unsigned int player_y = player->getY();
	string board = "";
	for(unsigned int i = 1; i < map.size()-1; i++){
		for(unsigned int j = 1; j < map.size()-1; j++){
			board+="+---";
		}
		board+="+\n";
		for(unsigned int j = 1; j < map.size()-1; j++){
			board+="| ";
			if(player_x==j&&player_y==i) 
				board+="*";
			else 
				board+=map[i][j].display(is_debug);
			board+=" ";
		}
		board+="|\n";
	}
	for(unsigned int i = 1; i < map.size()-1; i++){
		board+="+---";
	}
	board+="+\n";
	cout << board;
}