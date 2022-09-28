
// Instructs the player to go to a specific cell.
// If the destination cell contains a ladder, snake, or card, take it.
// Input data in design mode :
//Cell to move to

#pragma once
#include "Card.h"
#include"Player.h"
#include"Ladder.h"
#include"Snake.h"
class CardSix :
	public Card
{ //one parameter 
	CellPosition CellToMove;

public:
	CardSix(const CellPosition& pos); // A Constructor takes card position

	CardSix();//deafult constructor

	

	CellPosition getCellToMove();

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual void Save(ofstream& OutFile, objecttype GameObject); // Saves the GameObject parameters to the file

	virtual void Load(ifstream& Infile); // Loads and Reads the GameObject parameters from the file

	virtual ~CardSix(); // A Virtual Destructor
};



