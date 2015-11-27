#if !defined GAME_H
#define GAME_H
#include "stdafx.h"
class Game{
public:
	Game();
	int turn;
private:
	void run();
	bool win;
};

#endif