#include "stdafx.h"
#include "AIs.h"

playerAI::playerAI(){
};

Card* playerAI::getHand(GameManager* gm){
	return gm->getHand();
};

Card playerAI::takeCard(GameManager* gm, int command){
	return gm->takeCard(command);
};

void playerAI::exec(GameManager* gm){
	Card* cd;
	cd = getHand(gm);
	cout << endl;
	for (int i = 0; i < 14; i++){
		cout << (cd + i)->color << ":" << (cd + i)->number << " ";
		if (i == 6) cout << endl;
	}
	cout << endl <<endl;
	Card tmp = gm->takeCard(0);
	gm->throwCard(cd+1);
	cout << endl;
	for (int i = 0; i < 14; i++){
		cout << (cd + i)->color << ":" << (cd + i)->number << " ";
		if (i == 6) cout << endl;
	}
	cout << endl<<endl;
	cout << "------------------------------------------------------------------------------" << endl;
	//Card tmp = *cd;
	//return tmp;
};
