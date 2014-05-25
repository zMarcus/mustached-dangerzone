#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

class Card {
private: 
	int face;
	char suit;

public:
	Card(int = 0, char = ' ');
	void displayCard();
	void swap(Card&);
	void setCard(int, char);

	int getFace();
	char getSuit();
};