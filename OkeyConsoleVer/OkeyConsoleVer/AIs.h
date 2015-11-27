#if !defined AIS_H
#define AIS_H
#include "Card.h"
#include "GameManager.h"
class playerAI{
public:
	playerAI();
	void exec(GameManager* gm);
private:
	Card* getHand(GameManager* gm);
	Card takeCard(GameManager* gm,int command);
};

class botAI1{
public:
	botAI1();
};

class botAI2{
public:
	botAI2();
};

class botAI3{
public:
	botAI3();
};

#endif