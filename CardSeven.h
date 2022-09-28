#pragma once
#include "Card.h"

// [ CardSeven ] Summary:
// Restarts the game for the first player whose cell is after the current player in the grid.
//Restarting the game for a player makes him go to cell number 1.
class CardSeven :public Card
{

public:
	CardSeven(const CellPosition& pos); // A Constructor takes card position
	CardSeven();//deafult constructor
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of cardSeven which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of cardSeven on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual void Save(ofstream& OutFile, objecttype GameObject);// Saves the GameObject parameters to the file
	virtual void Load(ifstream& Infile); // Loads and Reads the GameObject parameters from the file

	virtual ~CardSeven(); // A Virtual Destructor
};



