#pragma once
#include "Card.h"

// [ CardEight ] Summary:
// This card is a prison.
//When a player stops at a Card8 cell, the player should choose either to pay specific
//amount of coins to go out of the prison, or stay in prison and not playing for 3 turns.
class CardEight :public Card
{


public:
	int AmountOfCoins;

	CardEight(const CellPosition& pos); // A Constructor takes card position
	CardEight();//deafult constructor
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of cardSeven which is: walletAmount
	int getAmouintOfCoins();
	void setAmouintOfCoins(int s);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of cardSeven on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual void Save(ofstream& OutFile, objecttype GameObject);// Saves the GameObject parameters to the file
	virtual void Load(ifstream& Infile); // Loads and Reads the GameObject parameters from the file

	virtual ~CardEight(); // A Virtual Destructor
};