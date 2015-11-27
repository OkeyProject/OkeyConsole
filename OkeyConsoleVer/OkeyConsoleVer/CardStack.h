#if !defined CARDSTACK_H
#define CARDSTACK_H

#include<string>
#include<stack>
#include "Card.h"

class CardStack{
	
public:
	CardStack();
	Card draw();
private:
	stack<Card> deck;
	void wash(Card cards[]);

};


#endif
