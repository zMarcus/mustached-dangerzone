//
//  main.cpp
//  BlackjackExample
//
//  Created by Marcus Omaiye on 5/22/14.
//  Copyright (c) 2014 cookies. All rights reserved.
//

#include "Card.h"
#include "GeneralFunctions.h"

int main(){

	int hit[PLAYERSNUM] = { 0 };
	int cardsValue[PLAYERSNUM] = { 0 };
	int index = 0;
	string players[7];
	char limit = ' ';

	ifstream fin("Input.txt");
	if (!fin){
		cout << "Error reading file 'Input.txt'!" << endl;
		system("pause");
		exit(0);
	}

	srand((unsigned)(time(0)));

	// Shuffle the cards

	system("pause");
}

















/*

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
	}
	else if (cardTotal == 21){
		youWin();
	}
	else if (cardTotal <= 20){
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
	}
	else if (cardTotal == 21){
		youWin();
	}
	else if (cardTotal <= 20){
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
	else if (cardTotal <= 20){
		cout << " {{ win or lose message depending on dealer's hand }}" << endl; 
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
	cout << "(You have won: " << score << " times.)" << endl;
	return;
}
*/









/**
#include <iostream>
#include <algorithm>
#include <memory>
#include <random>

// Card class
//
class Card
{
public:
enum rank{ ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
enum suit{ CLUBS, SPADES, DIAMONDS, HEARTS };
Card(rank r = ACE, suit s = HEARTS) : _rank(r), _suit(s) { }
int getValue() const
{
int value{ _rank };
if (value > 10)
value = 10;
return value;
}
private:
rank _rank;
suit _suit;
};


// Hand class
//
class Hand
{
	public:
	void add(std::shared_ptr<Card> aCard){ 
		_cards.push_back(std::move(aCard)); 
	}
	void clear() { 
		_cards.clear(); 
	}
	int getTotal() const
	{
		if (_cards.empty())
			return 0;
			int total{ 0 };
		
		for (auto& card : _cards)
			total += card->getValue();
			bool containsAce{ false };
		if (std::find_if(_cards.begin(), _cards.end(), [](const std::shared_ptr<Card>& card)
		{return card->getValue() == Card::ACE; }) != _cards.end())
			containsAce = true;
		if (containsAce && total <= 11)
			total += 10;
		return total;
	}

	protected:
	std::vector<std::shared_ptr<Card>> _cards;
};


// Deck class
//

class Deck : public Hand
{
public:
Deck() { }
Deck(int n)  { populate(n); shuffle(); }
void populate(int decks)
{
clear();
//create standard deck
for (int i = 0; i < decks; ++i)
{
for (int s = Card::CLUBS; s <= Card::HEARTS; ++s)
{
for (int r = Card::ACE; r <= Card::KING; ++r)
add(std::make_shared<Card>(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
}
}
}
void shuffle()
{
std::random_device rseed;
std::mt19937 mt(rseed());
std::shuffle(_cards.begin(), _cards.end(), mt);
}
void deal(Hand& hand)
{
if (!_cards.empty())
{
hand.add(_cards.back());
_cards.pop_back();
}
else
std::cout << "Out of cards. Unable to deal.";
}
bool empty() const { return _cards.empty(); }
};



// Main method
//

int main()
{

Hand player;
Deck deck{ 1 };
int blackjacks{ 0 }, hands{ 0 };
while (!deck.empty())
{
for (int i = 0; i < 2; ++i)
if(!deck.empty())
deck.deal(player);
//if (player.getTotal() <= 11)
//  deck.deal(player);
if (player.getTotal() == 21)
++blackjacks;
player.clear();
++hands;
}
std::cout << "After " << hands << " hands there were " << blackjacks << " blackjacks" << std::endl;

}
*/