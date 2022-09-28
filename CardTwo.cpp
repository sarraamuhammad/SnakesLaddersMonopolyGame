#include "CardTwo.h"
#include"Player.h"
#include "Ladder.h"
#include<fstream>
CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (1 here)
}
CardTwo::CardTwo()
{}
void CardTwo::ReadCardParameters(Grid*pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New Card two. Click to continue...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}
//has no parameters ReadCardParameters();
void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	//calls Apply function of the base class" Card"
	Card::Apply(pGrid,pPlayer);

	//creats pointer from input,output,cell classes
	Input* pIn = pGrid->GetInput();

	Output* pOut = pGrid->GetOutput();

	Cell *pCell = pPlayer->GetCell();

	//call function next ladder that return the adress of the next ladder, if exists , otherwise returns NULL;

	Ladder* nextLadder = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());// Get next ladder takes parameter of type Cellposition

	if (nextLadder == NULL)
	{
		int x, y;
		pOut->PrintMessage("No next Ladders , click to continue... ");

		pIn->GetPointClicked(x, y);

		pOut->ClearStatusBar();

		return;  // ends the function if no next ladder
	}
	else 
	{
		CellPosition pos = nextLadder->GetPosition(); 
		pOut->PrintMessage("congrats! you can now move to the next ladder ...click  to continue");
		/*
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		pGrid->UpdatePlayerCell(pPlayer, pos);
		*/
		nextLadder->Apply(pGrid,pPlayer);




	}
}
void CardTwo::Save(ofstream& OutFile, objecttype GameObject)
{
	OutFile << "" << cardNumber << " " << position.GetCellNum();
}
void CardTwo::Load(ifstream& Infile)
{

}
CardTwo::~CardTwo(void)
{
}

