#include <bits/stdc++.h>

using namespace std;

enum cardRank{
	CARD_2,
	CARD_3,
	CARD_4,
	CARD_5,
	CARD_6,
	CARD_7,
	CARD_8,
	CARD_9,
	CARD_10,
	CARD_JACK,
	CARD_QUEEN,
	CARD_KING,
	CARD_ACE,
	MAX_RANK
};

enum cardSuit{
	CARD_DIAMONDS,
	CARD_CLUBS,
	CARD_HEARTS,
	CARD_SPADES,
	MAX_SUIT
};

struct card{
	cardRank rank;
	cardSuit suit;
};

void printCard(const card &card){
	switch(card.rank){
		case CARD_2: cout<<"2"; break;
		case CARD_3: cout<<"3"; break;
		case CARD_4: cout<<"4"; break;
		case CARD_5: cout<<"5"; break;
		case CARD_6: cout<<"6"; break;
		case CARD_7: cout<<"7"; break;
		case CARD_8: cout<<"8"; break;
		case CARD_9: cout<<"9"; break;
		case CARD_10: cout<<"10"; break;
		case CARD_JACK: cout<<"J"; break;
		case CARD_QUEEN: cout<<"Q"; break;
		case CARD_KING: cout<<"K"; break;
		case CARD_ACE: cout<<"A"; break;
	}
	switch(card.suit){
		case CARD_DIAMONDS: cout<<"D"; break;
		case CARD_CLUBS: cout<<"C"; break;
		case CARD_HEARTS: cout<<"H"; break;
		case CARD_SPADES: cout<<"S"; break;
	}
}

void printDeck(card deck[]){
	for(int i=0;i<52;i++){
		printCard(deck[i]);
		cout<<" ";
	}
	cout<<endl;
}

void swapCard(card deck[]){
	unsigned seed = time (0); 
	for(int i=1;i<=2;i++)
	{
		srand(seed+(i*4));
		swap(deck[(rand()%52)+1],deck[(rand()%52)+1]);
	}
}

void swap(card &x, card &y){
	card temp;
	temp = x;
	x = y;
	y = temp;
}

void shuffleCard(card deck[]){
	unsigned int microseconds;
	unsigned seed = time (0); 
	for(int i=1;i<=52;i++)
	{
		srand(seed+(i*4));
		swap(deck[(rand()%52)+1],deck[(rand()%52)+1]);
	}
}

int getCardValue(card x){
	if(x.rank==CARD_ACE){
		return 11;
	}
	if(x.rank==CARD_JACK || x.rank==CARD_QUEEN || x.rank==CARD_KING){
		return 10;
	}
	else{
		return (x.rank+2);
	}
}

int main(){
	int inputnum;
	card deck[52];
	int card=0;
	for(int suit=0;suit<MAX_SUIT;suit++){
		for(int rank=0;rank<MAX_RANK;rank++){
			deck[card].suit=static_cast<cardSuit>(suit);
			deck[card].rank=static_cast<cardRank>(rank);
			card++;
		}
	}
	while(true){
	int input;
	cin>>input;
	if(input==1){
		printDeck(deck);
	}
	if(input==2){
		shuffleCard(deck);
	}
	if(input==3){
	cin>>inputnum;
	cout<< getCardValue(deck[inputnum]);
}
}
return 0;
}
