#include "stdafx.h"
#include "GameManager.h"
#include "CardStack.h"
#include <cstdlib>

GameManager::GameManager(){
	cardstack = new CardStack();
	deal();
	roundStatus = 0;
};

void GameManager::deal(){
	for (int j = 0; j < 4; j++){
		for (int i = 0; i < 14; i++){
			Card draw = cardstack->draw();
			hands[j][i] = draw;
		}
	}

	/*for (int i = 0; i < 4; i++){
		for (int j = 0; j < 14; j++){
			cout << hands[i][j].number << ":" << hands[i][j].color << " ";
		}
		cout << endl;
	}*/
};

void GameManager::getTurn(int turn){
	CurrentTurn = turn;
	//cout <<endl<< CurrentTurn << endl;
};

Card* GameManager::getHand(){
	return hands[CurrentTurn - 1];
}

Card GameManager::takeCard(int command){
		tmpGetCard = command ? ontable : cardstack->draw();
		roundStatus = 1;
		cout << "GameManager: get: " << tmpGetCard.number << ":" << tmpGetCard.color << endl;
		return tmpGetCard;
};

void GameManager::throwCard(Card* cd){
	if (roundStatus == 1){
		ontable.number = cd->number;
		ontable.color = cd->color;
		cout << "GameManager: throw: " << cd->number << ":" << cd->color << endl;
		cd->number = tmpGetCard.number;
		cd->color = tmpGetCard.color;
		roundStatus = 0;
	}
	else{
		cout << "Something wrong in Player" << CurrentTurn << endl;
		cout << "Discard before taking any card" << endl;
		system("Pause");
		exit(0);
	}

};