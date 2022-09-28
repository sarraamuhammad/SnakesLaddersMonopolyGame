#include<fstream>
#include "CardFour.h"
//prevents the player from moving the next turn
CardFour::CardFour()
{
	cardNumber = 4;
}
CardFour::CardFour(const CellPosition& pos) :Card(pos)
{
	cardNumber = 4;
}
void CardFour::ReadCardParameters(Grid* pGrid)
{
}
void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	int x, y;
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	pPlayer->SetcheckPreventMove(true);
}
void CardFour::Save(ofstream& OutFile, objecttype GameObject)
{
	OutFile << " " << cardNumber << " " << position.GetCellNum();
}
void CardFour::Load(ifstream& Infile)
{

}

CardFour::~CardFour()
{
}
