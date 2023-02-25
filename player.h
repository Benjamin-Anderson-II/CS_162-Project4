#ifndef PLAYER_H
#define PLAYER_H

#include "arrow.h"
#include "room.h"
#include <vector>

class Player {
private:
	int num_arrows;
	Arrow* arrow;
	unsigned int p_x{};
	unsigned int p_y{};
	bool has_gold{};
public:
	Player(unsigned int, unsigned int);

	~Player();
	Player(const Player&);
	Player& operator=(const Player&);

	bool isGoldAquired();
	unsigned int getX();
	unsigned int getY();
	int getNumArrows();
	Arrow* getArrow();

	void aquireGold();
	void setX(unsigned int);
	void setY(unsigned int);
	void loseArrow();
};
#endif