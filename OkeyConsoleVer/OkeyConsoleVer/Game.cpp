#include "stdafx.h"
#include "Game.h"
#include "GameManager.h"
#include "AIs.h"
Game::Game(){
	turn = 1;
	win = false;
	run();
};
void Game::run(){
	GameManager* gm = new GameManager();
	playerAI pi;
	while (!win){
		gm->getTurn(turn);
		cout << "Player" << turn << " is thinking..." << endl << endl;
		pi.exec(gm);
		turn = turn == 4 ? turn = 1 : turn+1;
	}
};