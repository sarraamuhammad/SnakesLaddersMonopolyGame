#include "CardSeven.h"
#include<fstream>
#include<iostream>
#include"CellPosition.h"
using namespace std;

CardSeven::CardSeven()
{
	cardNumber = 7;
}
CardSeven::CardSeven(const CellPosition& pos) :Card(pos)
{
	cardNumber = 7;
	// set the inherited cardNumber data member with the card number (7 here) to update and adjust all the member functions accordingly
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{
}
void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Card::Apply(pGrid, pPlayer);
	CellPosition cell1(1);
	 
	if(pGrid->getNextPlayer(pPlayer->GetCell()->GetCellPosition()))
	pGrid->UpdatePlayerCell(pGrid->getNextPlayer(pPlayer->GetCell()->GetCellPosition()), cell1);
	
}
void CardSeven::Save(ofstream& OutFile, objecttype GameObject)
{
	OutFile << "" << cardNumber << " " << position.GetCellNum() << endl;
}
void CardSeven::Load(ifstream& Infile)
{
}

CardSeven::~CardSeven() {}