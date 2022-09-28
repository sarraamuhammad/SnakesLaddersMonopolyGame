#include<fstream>
#include "CardSix.h"
#include<iostream>
using namespace std;
//
// Instructs the player to go to a specific cell.
// If the destination cell contains a ladder, snake, or card, take it.
// Input data in design mode :
//Cell to move to
CardSix::CardSix()  //deafult constructor
{
	cardNumber = 6;
	CellToMove= position; //the deafult value of the cell to move to is the same cell (no change)
}
CardSix::CardSix(const CellPosition& pos):Card(pos)
{
	cardNumber = 6;
	CellToMove= position;
}
void CardSix::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New card Six !... click to set cell you want to move to :  ");
	CellToMove = pIn->GetCellClicked(); //sets the cellToMove
	pOut->ClearStatusBar();
}

CellPosition CardSix:: getCellToMove()
{
	return CellToMove;
}
void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	
	Card::Apply(pGrid, pPlayer);   //first , call apply of the base Class

	pGrid->UpdatePlayerCell(pPlayer, CellToMove);
	if (pPlayer->GetCell()->GetGameObject())
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid, pPlayer);

	
	

}
void CardSix::Save(ofstream& OutFile, objecttype GameObject)
{
	OutFile << cardNumber << " " << position.GetCellNum() << " " << CellToMove.GetCellNum();
}
void CardSix::Load(ifstream& Infile)
{

}

CardSix::~CardSix()
{
}

