#include "Card.h"

// Constructor
Card::Card(int cardFace, char cardSuit){
	face = cardFace;
	suit = cardSuit;
}

// Swap function
void Card::swap(Card& c){
	// Create a temporary card to hold the face and suit
	Card temp;
	temp.face = c.face;
	temp.suit = c.suit;

	c.face = this->face;
	c.suit = this->suit;

	this->face = temp.face;
	this->suit = temp.suit;
}

// Display card and suit
void Card::displayCard(){
	switch (face)
	{
	case 11: 
		cout << 'J';
		break;
	case 12: 
		cout << 'Q';
		break;
	case 13: 
		cout << 'K';
		break;
	case 1: 
		cout << 'A';
		break;
	default:
		cout << face;
		break;
	}

	cout << "of " << suit;
}

// Set card while we have the variables
// won't have to make a new class
void Card::setCard(int cardFace, char cardSuit){
	face = cardFace;
	suit = cardSuit;
}

// Face getter
int Card::getFace(){
	return face; 
}

// Suit getter
char Card::getSuit(){
	return suit;
}