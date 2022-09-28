#include<fstream>
#include "CardThree.h"

//gives the player an extra dice roll
CardThree::CardThree()
{
	cardNumber = 3;
}
CardThree::CardThree(const CellPosition& pos):Card(pos)
{
	cardNumber = 3;
}
void CardThree::ReadCardParameters(Grid* pGrid)
{
}
void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	
	int x, y;
	Card::Apply(pGrid, pPlayer);   //first , call apply of the base Class
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You're given an extra dice roll...click to continue playing.");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	pGrid->ExtraDice();
	//player.cpp: decrement turncount of pPlayer by 1 when player reaches this card
	 

}
void CardThree::Save(ofstream& OutFile, objecttype GameObject)
{
	OutFile <<" " << cardNumber << " " << position.GetCellNum();
}
void CardThree::Load(ifstream& Infile)
{

}

 CardThree::~CardThree()
 {
 }