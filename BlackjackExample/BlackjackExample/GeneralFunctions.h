#include "Card.h"

// Create cards
Card hand[52];

// Number of players
const int PLAYERSNUM = 7;
const int GAMELIMIT = 21;
const int DEALER = 16;
const int CARDSPERPLAYER = 2;

// Prototyes


// Functions
void displayCards(){
	
}

void shuffleCards(int counter){

	// S ~ suit[1 - 4][0 - 3]
	for (int s = 3; s <= 6; s++){
		// F ~ face of card
		for (int f = 1; f <= 13; f++){
			hand[counter] = Card(f, char(s)); 
			// Static cast s into a char
			counter++;
		}
	}

	for (int i = 0; i < 52; i++){
		// Keep randomizing cards by swapping positions 
		hand[i].swap((hand[rand() % 52]));
	}
}