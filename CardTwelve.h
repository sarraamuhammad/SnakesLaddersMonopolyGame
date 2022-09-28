#pragma once

#include "Card.h"

// [ CardTwelve ] Summary:
// Gives the player the option to buy this cell and all cells containing a card with the same
//number.

class CardTwelve : public Card
{
	// CardOne Parameters:
	int CardPrice; // the wallet value to decrease from the player
	int PasserFees;
public:
	CardTwelve(const CellPosition& pos); // A Constructor takes card position
	CardTwelve();
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual void Save(ofstream& OutFile, objecttype GameObject);// Saves the GameObject parameters to the file
	virtual void Load(ifstream& Infile); // Loads and Reads the GameObject parameters from the file

	virtual ~CardTwelve(); // A Virtual Destructor
};

