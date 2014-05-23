#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

int card1, card2, card3, card4;
int cardTotal;
string hitStay;

int score = 0;

int main(){

	void dealCards();
	void dealThirdCard();
	void dealFourthCard();
	void youLose();
	void youWin();
	void dealerPlay();


	cout << "\n-------------\n-------------Blackjack \n-------------\n-------------\n\n";
	cout << "Welcome to the Blackjack game!\nPress ENTER to have your first 2 cards dealt.\n";
	cin.get();

	dealCards();
	cout << "Card 1: " << card1 << endl; 
	cout << "Card 2: " << card2 << endl;
	cardTotal = card1 + card2;
	cout << "Your cards total: " << cardTotal << endl;
	
	if (cardTotal > 21){
		youLose();
	} else if (cardTotal == 21){
		youWin();
	} else if (cardTotal <= 20){
		cout << "HIT or STAY?" << endl;
		cin >> hitStay;
		if (hitStay == "HIT"){
			dealThirdCard();
		}
		if (hitStay == "STAY"){
			dealerPlay();
		}
	}

	cout << "Card1: " << card1 << endl;
	cout << "Card2: " << card2 << endl;
	cout << "Card3: " << card3 << endl;
	cardTotal += card3;
	cout << "Your cards total: " << cardTotal << endl;
	cin.get();

	if (cardTotal > 21){
		youLose();
	} else if (cardTotal == 21){
		youWin();
	} else if (cardTotal <= 20){
		cout << "HIT or STAY?" << endl;
		cin >> hitStay;
		if (hitStay == "HIT"){
			dealFourthCard();
		}
		if (hitStay == "STAY"){
			dealerPlay();
		}
	}

	cout << "Card1: " << card1 << endl;
	cout << "Card2: " << card2 << endl;
	cout << "Card3: " << card3 << endl;
	cout << "Card4: " << card4 << endl;
	cardTotal += card4;
	cout << "Your cards total: " << cardTotal << endl;
	cin.get();

	if (cardTotal > 21){
		youLose();
	}
	else if (cardTotal == 21){
		youWin();
	}

	cin.get();
	return 0;
}

void dealCards(){

	srand(time(NULL));
	card1 = rand() % 11 + 1;
	card2 = rand() % 11 + 1;
	return;
}

void dealThirdCard(){

	srand(time(NULL));
	card3 = rand() % 11 + 1;
}

void dealFourthCard(){

	srand(time(NULL));
	card4 = rand() % 11 + 1;
}

void dealerPlay(){

	return;
}

void youLose(){
	cout << "Bust!  Better luck next time.  Play again?" << endl;
	return;
}

void youWin(){
	score++;
	cout << "You win!  Congratulations; play again?" << endl;
	cout << "(You have won: " + score << " times.)" << endl;
	return;
}
