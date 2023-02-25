#ifndef GAME_H
#define GAME_H
#include "room.h"

#include <vector>
#include <string>
#include "player.h"
#include "chimera.h"

class Game {
private:
	std::vector<std::vector<Room>> map;
	bool is_debug;
	Player* player;
	Chimera* chimera;

	bool win{};

	//initialization functions
	void readyRooms();
	void placeEvents();
	void placePlayer();

	//gameplay functions
	void gatherInformation();
	bool triggerEvents();
	int  getRandEmptyRoomIdx();
	bool testAhead(int, int, Direction);
	void act();
	void movePlayer(Direction);
	bool fireArrow(char);
	bool isValidInput(std::string);
	void relocateChimera();

public:
	Game(int size, bool debug);
	~Game();
	Game(const Game&);
	Game& operator=(const Game&);

	void play();

	void displayMap();
};

#endif