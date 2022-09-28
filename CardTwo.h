#pragma once
#include "Card.h"
#include"Player.h"
#include"Grid.h"
class CardTwo :
    public Card
{
    //this class has no data members
public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position
    CardTwo();

	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	virtual void ReadCardParameters(Grid*pGrid);
	virtual void Save(ofstream& OutFile, objecttype GameObject);// Saves the GameObject parameters to the file
	virtual void Load(ifstream& Infile); // Loads and Reads the GameObject parameters from the file

	virtual ~CardTwo(); // A Virtual Destructor
};
//missing save and load functions
