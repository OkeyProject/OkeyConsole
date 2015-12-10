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
	int CurrentTurn;
	Card hands[4][14];
private:
	Card ontable;
	void deal();
	CardStack* cardstack;
	Card tmpGetCard;
	int roundStatus;
};

#endif