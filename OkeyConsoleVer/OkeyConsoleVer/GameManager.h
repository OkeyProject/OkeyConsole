#if !defined GAMEMANAGER_H
#define GAMEMANAGER_H
#include "stdafx.h"
#include "Card.h"
#include "CardStack.h"
#include "Game.h" 
class GameManager{
public:
	GameManager();
	void getTurn(int turn);
	Card* getHand();
	Card takeCard(int command);
	void throwCard(Card* cd);
	Card hands[4][14];
private:
	int CurrentTurn;
	Card ontable;
	void deal();
	CardStack* cardstack;
	Card tmpGetCard;
	int roundStatus;
};

#endif