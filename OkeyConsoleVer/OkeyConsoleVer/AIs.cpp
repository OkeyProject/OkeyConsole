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

void classify_color(Card* cd, Card* cd_color, string color){
	int cnt = 0;
	for (int i = 0; i < 15; i++){
		if (cd[i].color == color){
			cd_color[cnt] = cd[i];
			cnt++;
		}
	}
};

void sort_color(Card* cd_color){
	for (int i = 0; i < 14; i++){
		for (int j = 0; j < 14 - i; j++){
			if (cd_color[j].number > cd_color[j + 1].number){
				Card temp[1];
				temp[0] = cd_color[j + 1];
				cd_color[j + 1] = cd_color[j];
				cd_color[j] = temp[0];
			}
		}
	}
};

int find_num_combination(Card* cd_color, int i){
	int ret = 0;
	if (i == 14)
		return ret;
	else
		if (cd_color[i + 1].number == cd_color[i].number + 1){
			ret++;
			ret += find_num_combination(cd_color, i + 1);
		}
		return ret;
}

void moveto(Card* category, Card moved){
	for (int i = 0; i < 15; i++)
		if (category[i].number == 0){
			category[i] = moved;
			break;
		}
			
}

void rebuild_num(Card* cd_color, Card* done, Card* usef, Card* usel){
	for (int i = 0; i < 15; i++){
		int cnt = 0;
		if (cd_color[i].number != 0){
			cnt = find_num_combination(cd_color, i);
			if (cnt == 0)
				moveto(usel, cd_color[i]);
			else if (cnt == 1){
				moveto(usef, cd_color[i]);
				moveto(usef, cd_color[i + 1]);
			}
			else
			for (int j = 0; j <= cnt; j++)
				moveto(done, cd_color[i + j]);
		}
		i = i + cnt;
	}
}

void find_color_combination(Card* done, Card* usef, Card* usel,int i,int j){
	int flag = 2;
	for (int k = j; k < 15; k++){
		if (usel[k].number == usel[i].number &&  usel[k].color != usel[i].color && usel[k].color != usel[j].color){
			flag = 3;
			for (int l = k; l < 15; l++){
				if (usel[l].number == usel[i].number &&  usel[l].color != usel[i].color && usel[l].color != usel[j].color && usel[l].color != usel[k].color){
					moveto(done, usel[i]);
					moveto(done, usel[j]);
					moveto(done, usel[k]);
					moveto(done, usel[l]);
					usel[i].number = 0;
					usel[j].number = 0;
					usel[k].number = 0;
					usel[l].number = 0;
					usel[i].color = "white";
					usel[j].color = "white";
					usel[k].color = "white";
					usel[l].color = "white";
					flag = 4;
				}
				else if (l == 14 && flag == 3){
					moveto(done, usel[i]);
					moveto(done, usel[j]);
					moveto(done, usel[k]);
					usel[i].number = 0;
					usel[j].number = 0;
					usel[k].number = 0;
					usel[i].color = "white";
					usel[j].color = "white";
					usel[k].color = "white";
					flag = 3;
				}
			}
		}
		else if (k == 14 && flag == 2){
			moveto(usef, usel[i]);
			moveto(usef, usel[j]);
			usel[i].number = 0;
			usel[j].number = 0;
			usel[i].color = "white";
			usel[j].color = "white";
		}
	}
}

void rebuild_color(Card* done, Card* usef, Card* usel){
	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 15; j++){
			if (usel[i].number == usel[j].number && usel[i].color != usel[j].color)
				find_color_combination(done, usef, usel, i, j);
		}
	}
}


void Sort(Card* cd, Card* done, Card* usef, Card* usel){
	Card cd_black[15], cd_blue[15], cd_red[15], cd_yellow[15];

	classify_color(cd, cd_black, "black");
	classify_color(cd, cd_blue, "blue");
	classify_color(cd, cd_red, "red");
	classify_color(cd, cd_yellow, "yellow");
	sort_color(cd_black);
	sort_color(cd_blue);
	sort_color(cd_red);
	sort_color(cd_yellow);
	rebuild_num(cd_black, done, usef, usel);
	rebuild_num(cd_blue, done, usef, usel);
	rebuild_num(cd_red, done, usef, usel);
	rebuild_num(cd_yellow, done, usef, usel);
	rebuild_color(done, usef, usel);
	rebuild_color(done, usef, usel);
	rebuild_color(done, usef, usel);
	rebuild_color(done, usef, usel);
	
};

void playerAI::exec(GameManager* gm){
	Card cd[15];
	Card* bcd;
	Card done[15];
	Card usef[15];
	Card usel[15];
	bcd = getHand(gm);
	for (int i = 0; i < 14; i++)
		cd[i] = bcd[i];
	Card tmp = gm->takeCard(0);
	cd[14] = tmp;
	Sort(cd, done, usef, usel);
	if (gm->CurrentTurn == 1){
		cout << "done:" << endl;
		for (int i = 0; i < 15; i++)
			if (done[i].number != 0)
				cout << done[i].color << "\t" << done[i].number << endl;

		cout << "useless:" << endl;
		for (int i = 0; i < 15; i++)
			if (usel[i].number != 0)
				cout << usel[i].color << "\t" << usel[i].number << endl;

		cout << "useful:" << endl;
		for (int i = 0; i < 15; i++)
			if (usef[i].number != 0)
				cout << usef[i].color << "\t" << usef[i].number << endl;
		system("pause");
	}
	/*
	for (int i = 0; i < 14; i++){
		cout << (cd + i)->number << ":" << (cd + i)->color << " ";
		if (i == 6) cout << endl;
	}*/
	int p = 0;
	bool flag = true;
	while (flag == true){
		for (int i = 0; i < 15; i++){
			if (usel[p].number == cd[i].number && usel[p].color == cd[i].color && usel[p].number != 0){
				gm->throwCard(cd + i);
				cd[i] = cd[14];
				cd[14].color = "white";
				cd[14].number = 0;
				flag = false;
				break;
			}
			if (p == 14){
				p = 0;
				while (flag == true){
					for (int i = 0; i < 15; i++){
						if (usef[p].number == cd[i].number && usef[p].color == cd[i].color && usef[p].number != 0){
							gm->throwCard(cd + i);
							cd[i] = cd[14];
							cd[14].color = "white";
							cd[14].number = 0;
							flag = false;
							break;
						}
					}
					p++;
					if (p == 14){
						p = 0;
						continue;
					}
						
				}
			}
		}
		p++;
	}
	
	for (int i = 0; i < 14; i++){
		gm->hands[gm->CurrentTurn-1][i] = cd[i];
	}
	/*/
	for (int i = 0; i < 14; i++){
		cout << (cd + i)->number << ":" << (cd + i)->color << " ";
		if (i == 6) cout << endl;
	}*/
	
	cout << "------------------------------------------------------------------------------" << endl;
	//Card tmp = *cd;
	//return tmp;
};
