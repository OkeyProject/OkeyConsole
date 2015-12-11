#include "stdafx.h"
#include "AIs.h"
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

botAI1::botAI1() {
};


Card* botAI1::getHand(GameManager* gm) {
	return gm->getHand();
};

Card botAI1::takeCard(GameManager* gm, int command) {
	return gm->takeCard(command);
};


void botAI1::exec(GameManager* gm) {
	Card* cd;
	cd = getHand(gm);
	botAI1::init(cd);
	cout << endl;
	for (int i = 0; i < 14; i++) {
		cout << (cd + i)->color << ":" << (cd + i)->number << " ";
		if (i == 6) cout << endl;
	}
	cout << endl << endl;
	scanf("%*s");
	puts("lalala~~~~~~~~~~~~~~~~~~~~~~~");
///////////////////do something here////////////////////////
	Card tmp = gm->takeCard(0);
	gm->throwCard(cd + 1);


////////////////////////////////////////////////////////////
	cout << endl;
	for (int i = 0; i < 14; i++) {
		cout << (cd + i)->color << ":" << (cd + i)->number << " ";
		if (i == 6) cout << endl;
	}
	cout << endl << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	
};


void botAI1::init(Card * cd) {
	//	string Black = "Black", Yellow = "Yellow", Red = "Red", Blue = "Blue";
	vector<Card> tmp;
	int map[4][14] = { 0 } , cnt = 0;
////////////// put Card into map/////////////////////////////
	for (int i = 0; i < 14; i++) {
		string color = (cd + i)->color;
		int num = (cd + i)->number;
		if (color == "Black") {
			map[0][num] ++;
		}
		else if (color == "Yellow") {
			map[1][num] ++;
		}
		else if (color == "Red") {
			map[2][num] ++;
		}
		else if (color == "Blue") {
			map[3][num] ++;
		}
	}
//////////get done and useful column/////////////////////
	cnt = 0;
	for (int i = 0; i < 14; i++) {
		Card tmpcard;	 
		cnt = 0;
		for (int j = 0; j < 4; j++ )
			if (map[j][i]) cnt++;
		if (cnt > 2) {
			for (int j = 0; j < 4; j++)
				if (map[j][i]) {
					switch (j) {
					case 0:
						tmpcard.color = "Black", tmpcard.number = i;
						break;
					case 1:
						tmpcard.color = "Yellow", tmpcard.number = i;
						break;
					case 2:
						tmpcard.color = "Red", tmpcard.number = i;
						break;
					case 3:
						tmpcard.color = "Blue", tmpcard.number = i;
						break;
					}
					map[j][i]--;
					tmp.push_back(tmpcard);
				}
			done.push_back(tmp);
			total -= cnt;
		}
	}
////////////get done row ////////////////////////////
	cnt = 0;
	for (int i = 0; i < 4; i++) {
		Card tmpcard;
		for (int j = 0, k = 0; j < 14; j++) {
			cnt = 0;
			if (map[i][j]) {
				for (k = j + 1; k < 14; k++) {
					if (map[i][k]) cnt++;
					else break;
				}
			}
			if (cnt > 2) {
				for (; j < k; j++) {
					switch (j) {
					case 0:
						tmpcard.color = "Black", tmpcard.number = i;
						break;
					case 1:
						tmpcard.color = "Yellow", tmpcard.number = i;
						break;
					case 2:
						tmpcard.color = "Red", tmpcard.number = i;
						break;
					case 3:
						tmpcard.color = "Blue", tmpcard.number = i;
						break;
					}
					map[i][j]--;
					tmp.push_back(tmpcard);
				}
				done.push_back(tmp);
				total -= cnt;
			}
		}
	}
/////////// get usefule column //////////////////////////
	cnt = 0;
	for (int i = 0; i < 14; i++) {
		Card tmpcard;
		cnt = 0;
		for (int j = 0; j < 4; j++)
			if (map[j][i]) cnt++;
		if (cnt == 2) {
			for (int j = 0; j < 4; j++)
				if (map[j][i]) {
					switch (j) {
					case 0:
						tmpcard.color = "Black", tmpcard.number = i;
						break;
					case 1:
						tmpcard.color = "Yellow", tmpcard.number = i;
						break;
					case 2:
						tmpcard.color = "Red", tmpcard.number = i;
						break;
					case 3:
						tmpcard.color = "Blue", tmpcard.number = i;
						break;
					}
					map[j][i]--;
					tmp.push_back(tmpcard);
				}
			useful.push_back(tmp);
		}
	}
////////////// get useful row //////////////////////////
	cnt = 0;
	for (int i = 0; i < 4; i++) {
		Card tmpcard;
		for (int j = 0, k = 0; j < 14; j++) {
			cnt = 0;
			if (map[i][j]) {
				for (k = j + 1; k < 14; k++) {
					if (map[i][k]) cnt++;
					else break;
				}
			}
			if (cnt == 2) {
				for (; j < k; j++) {
					switch (j) {
					case 0:
						tmpcard.color = "Black", tmpcard.number = i;
						break;
					case 1:
						tmpcard.color = "Yellow", tmpcard.number = i;
						break;
					case 2:
						tmpcard.color = "Red", tmpcard.number = i;
						break;
					case 3:
						tmpcard.color = "Blue", tmpcard.number = i;
						break;
					}
					map[i][j]--;
					tmp.push_back(tmpcard);
				}
				useful.push_back(tmp);
			}
		}
	}
////////////// get trash card /////////////////////////
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 14; j++)
			while (map[i][j]--) {
				Card tmpcard;
				switch (i) {
				case 0:
					tmpcard.color = "Black", tmpcard.number = j;
					break;
				case 1:
					tmpcard.color = "Yellow", tmpcard.number = j;
					break;
				case 2:
					tmpcard.color = "Red", tmpcard.number = j;
					break;
				case 3:
					tmpcard.color = "Blue", tmpcard.number = j;
					break;
				}
				trash.push_back(tmpcard);
			}
////////////// put sorted card /////////////////////////
	int ptr = -1;
	for (int i = 0; i < done.size(); i++) {
		for (int j = 0; j < done[i].size(); j++)
			(cd + (++ptr))->color = done[i][j].color, (cd + ptr)->number = done[i][j].number;
	}
	for (int i = 0; i < useful.size(); i++) {
		for (int j = 0; j < useful[i].size(); j++)
			(cd + (++ptr))->color = useful[i][j].color, (cd + ptr)->number = useful[i][j].number;
	}
	for (int i = 0; i < trash.size(); i++) {
		(cd + (++ptr))->color = trash[i].color , (cd + ptr)->number = trash[i].number;
	}

}