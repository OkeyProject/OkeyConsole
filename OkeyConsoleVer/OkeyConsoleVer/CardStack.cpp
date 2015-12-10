
#include "stdafx.h"
#include "CardStack.h"
#include<cstdlib>
#include<iostream>
#include<time.h>
using namespace std;

CardStack::CardStack(){
	Card cards[104];
	for (int i = 0; i < 26; i++){
		for (int j = 0; j < 4; j++){
			int index = j*26+i;
			cards[index].number = i / 2 + 1;
			switch (j)
			{
			case 0:
				cards[index].color = "Black";
				break;
			case 1:
				cards[index].color = "Yellow";
				break;
			case 2:
				cards[index].color = "Red";
				break;
			case 3:
				cards[index].color = "Blue";
				break;
			default:
				break;
			}

			//cout << cards[index].number << " " << cards[index].color <<endl;
		}
	}
	wash(cards);
};

void CardStack::wash(Card cards[]){
	srand(time(NULL));
	for (int i = 0; i < 40000; i++){
		unsigned int a = (rand() % 104);
		unsigned int b = (rand() % 104);
		swap(cards[a], cards[b]);
	}

	for (int i = 0; i < 104; i++)
		deck.push(cards[i]);
};

Card CardStack::draw(){
	Card ret;
	if (!deck.empty()){
		ret = deck.top();
		deck.pop();
	}
	else{
		cout << "CardStack is empty!!!";
		system("Pause");
		exit(0);
	}
	return ret;
};