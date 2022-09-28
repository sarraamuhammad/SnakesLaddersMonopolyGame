// Moves the player backward with the same number of steps that he just rolled.
//If he reaches a ladder, a snake, or a card at the end of moving, take it.
#pragma once
#include "Card.h"
#include"Player.h"
class CardFive :
	public Card
{

public:
	CardFive(const CellPosition& pos); // A Constructor takes card position
	CardFive();//deafult constructor
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual void Save(ofstream& OutFile, objecttype GameObject);// Saves the GameObject parameters to the file
	virtual void Load(ifstream& Infile); // Loads and Reads the GameObject parameters from the file
	
	virtual ~CardFive(); // A Virtual Destructor
};




