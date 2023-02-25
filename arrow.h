#ifndef ARROW_H
#define ARROW_H

enum Direction {NORTH, EAST, SOUTH, WEST};

class Arrow {
private:
	Direction dir_of_motion;
	int a_x;
	int a_y;
public:
	Arrow(int, int, Direction);

	int getX();
	int getY();
	Direction getDirection();

	void move();
};
#endif