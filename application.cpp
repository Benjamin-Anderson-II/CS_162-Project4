

#include "game.h"

#include <iostream>
#include <string.h>
using namespace std;

/*********************************************************************
** Function:		
** Description:		
** Parameters:		
** Pre-Conditions:	
** Post-Conditions:	
*********************************************************************/
int main(int argc, char const *argv[]){
	int size{};
	bool debug{};
	//convert command line arguments to useful data
	try{
		if(argc!=3 || atoi(argv[1])<4) // board must be at least a 4x4
			throw 0;

		size = atoi(argv[1]);

		if(strcmp(argv[2], "false")==0)
			debug = false;
		else if(strcmp(argv[2], "true")==0) 
			debug = true;
		else
			throw 0;

	} catch (...){
		cout << "Invalid Command Line Arguments\n";
		return 1;
	}
	//cout << "Confuse\n";
	Game* game = new Game(size, debug);
	game->play();
	delete game;
	return 0;
}