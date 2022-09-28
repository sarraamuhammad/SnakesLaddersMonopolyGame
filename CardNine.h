#pragma once
#include "Card.h"
#include"player.h"

// [ CardNine ] Summary:
// Gives the player the option to buy this cell and all cells containing a card with the same
//number.

class CardNine : public Card
{
	 bool sold;
	Player* owner;
	Player* Passer;

   int CardPrice; 
   int PasserFees;
   int  ownernumber;
   int ownerCellNumber;
   int passerCellNumber;
   int PasserNumber;

public:
	CardNine(const CellPosition& pos); // A Constructor takes card position
	CardNine();
	virtual Player* GetOwner();
	virtual Player* GetPasser();
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual void Save(ofstream& OutFile, objecttype GameObject);// Saves the GameObject parameters to the file
	virtual void Load(ifstream& Infile); // Loads and Reads the GameObject parameters from the file

	virtual ~CardNine();
}; 

