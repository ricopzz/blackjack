#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;

/* enum&structs */
enum cardRank{
	CD_2,CD_3,CD_4,CD_5,CD_6,CD_7,CD_8,CD_9,CD_10,CD_J,CD_Q,CD_K,CD_A,MAX_RANK
};

enum cardSuit{
	CD_D,CD_C,CD_H,CD_S,MAX_SUIT
};

struct card{
	cardRank rank;
	cardSuit suit;
};

/* Global variables */
card deck[52];
int cardV,Dcard;
bool dcheck=false;
bool pcheck=false;

/* functions */
void insertCard(){
	int card=0;
	for(int suit=0;suit<MAX_SUIT;suit++){
			for(int rank=0;rank<MAX_RANK;rank++){
				deck[card].suit=static_cast<cardSuit>(suit);
				deck[card].rank=static_cast<cardRank>(rank);
				card++;
			}
		}
}

void printCard(const card &card){
	switch(card.rank){
		case CD_2: cout<<"2"; break;
		case CD_3: cout<<"3"; break;
		case CD_4: cout<<"4"; break;
		case CD_5: cout<<"5"; break;
		case CD_6: cout<<"6"; break;
		case CD_7: cout<<"7"; break;
		case CD_8: cout<<"8"; break;
		case CD_9: cout<<"9"; break;
		case CD_10: cout<<"10"; break;
		case CD_J: cout<<"J"; break;
		case CD_Q: cout<<"Q"; break;
		case CD_K: cout<<"K"; break;
		case CD_A: cout<<"A"; break;
	}
	switch(card.suit){
		case CD_D: cout<<"D"; break;
		case CD_C: cout<<"C"; break;
		case CD_H: cout<<"H"; break;
		case CD_S: cout<<"S"; break;
	}
}

void printDeck(card deck[]){
	for(int i=0;i<52;i++){
		printCard(deck[i]);
		cout<<" ";
	}
	cout<<endl;
}

int getCardValue(card x){
	if(x.rank==CD_A){
		return 11;
	}
	if(x.rank==CD_J || x.rank==CD_Q || x.rank==CD_K){
		return 10;
	}
	else{
		return (x.rank+2);
	}
}

void drawFirstCard(card deck[]){
	unsigned seed = time (0);
	cardV=0;
	srand(seed+1);
	card a=deck[rand()%53];
	card b=deck[rand()%53];
	printCard(a);
	Sleep(500);cout<<" ";
	printCard(b);Sleep(500);
	cardV=getCardValue(a) + getCardValue(b);
	cout<<" ( "<<cardV<<" )";
}

void drawNextCard(card deck[]){
	unsigned seed = time(0);
	srand(seed);
	card a=deck[rand()%53];
	printCard(a);
	Sleep(500);
	cardV+=getCardValue(a);
}

void drawDealerNext(card deck[]){
	unsigned seed = time(0);
	srand(seed);
	card a=deck[rand()%53];
	printCard(a);
	Sleep(500);
	Dcard+=getCardValue(a);
}

void drawDealer(card deck[]){
	unsigned seed = time (0);
	srand(seed);
	card a=deck[rand()%52];
	card b=deck[rand()%52];
	printCard(a);
	Sleep(500);cout<<" ";
	printCard(b);Sleep(500);
	Dcard=getCardValue(a) + getCardValue(b);
	if(Dcard>17){
		cout<<" ( "<<Dcard<<" )"<<endl;
		dcheck=true;
	}	
	if(Dcard<=17 && dcheck==false){
		cout<<" ";
		drawDealerNext(deck);
		dcheck=true;
		if(Dcard>21){
			cout<<"BUZZ!";
			dcheck=true;
		}
		cout<<" ( "<<Dcard<<" )"<<endl;
	}
}

/* main */
int main(){
	int totalPlayer;
	int card=0;
	string playerName;
	int save;
	int j=0;
	int choice;
	
	cout<<"\tWelcome to blackjack game!"<<endl<<endl;
	insertCard();
	cout<<"Enter player name : ";
	cin>>playerName;
	cout<<endl;
	cout<<playerName<<", your card is : ";drawFirstCard(deck);cout<<endl;Sleep(500);
	while(true){
		int count;
		cout<<playerName<<", 1. Hit | 2. Stand"<<endl<<"Choice : ";
		cin>>choice;
		if(choice==1){
			cout<<"Drawing next card : ";Sleep(500);
			drawNextCard(deck);
			cout<<" ( "<<cardV<<" )"<<endl;
			if(cardV>21 && pcheck==false){
				cout<<"BUZZ!"<<endl<<endl;
				pcheck=true;
				break;
			}
		}
		if(choice==2){
			save=cardV;	
			cout<<endl;
			break;
		}
	}
	cout<<"Dealer's turn . . .";Sleep(1000);cout<<endl;
	drawDealer(deck);
	if(cardV<Dcard && dcheck==true){
		cout<<"Dealer won the match!";
	}
	if(cardV==Dcard){
		cout<<"Draw!";
	}
	if(Dcard<cardV && pcheck==false){
		cout<<playerName<<" won the match!";
	}
	if(Dcard<cardV && pcheck==true){
		cout<<"Dealer won the match!";
	}

	return 0;
}
