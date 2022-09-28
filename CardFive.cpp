
#include "CardFive.h"
#include"player.h"
#include<fstream>
// Moves the player backward with the same number of steps that he just rolled.
//If he reaches a ladder, a snake, or a card at the end of moving, take it.
CardFive::CardFive()
{
	cardNumber = 5;
}
CardFive::CardFive(const CellPosition& pos) :Card(pos)
{
	cardNumber = 5;
}
void CardFive::ReadCardParameters(Grid* pGrid)
{
}
void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	int x, y;
	Card::Apply(pGrid, pPlayer);   //first , call apply of the base Class

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	CellPosition pos(pPlayer->GetCell()->GetCellPosition().GetCellNum()-pPlayer->getJustRolledDice());
	pGrid->UpdatePlayerCell(pPlayer, pos);
	if (pPlayer->GetCell()->GetGameObject())
		pPlayer->GetCell()->GetGameObject()->Apply(pGrid,pPlayer);
	
	
	
}

void CardFive::Save(ofstream& OutFile, objecttype GameObject)
{
	OutFile << " " << cardNumber << " " << position.GetCellNum() << " ";
}
void CardFive::Load(ifstream& Infile)
{

}

CardFive::~CardFive()
{
}

