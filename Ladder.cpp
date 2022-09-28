
#include "Ladder.h"
#include"Player.h"
#include<iostream>
#include<fstream>
using namespace std;
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	//validation: the start and end cells at the same vertical column and at the start cell is below the endcell
	if (endCellPos.IsValidCell())
	{
		if (startCellPos.HCell() == endCellPos.HCell() && startCellPos.VCell() > endCellPos.VCell())

			this->endCellPos = endCellPos;
	}
	///TODO: Do the needed validation
}
Ladder::Ladder() {}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	//GameObject::Apply(pGrid,pPlayer); use func move

	Output* pOut = pGrid->GetOutput();

	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("you have reached a ladder!...click to continue");

	int x, y;

	pIn->GetPointClicked(x, y);

	pOut->ClearStatusBar();
	
	//moves the player from the start cell of the ladder to the end cell

	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder::Save(ofstream& savefile, objecttype gameobject) {
	if (gameobject==ladders){
		savefile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
	}
}
void Ladder::Load(ifstream& savefile) {
	int startcell, endcell;
	savefile >> startcell >> endcell;
	CellPosition startc(startcell);
	CellPosition endc(endcell);
	position = startc;
	endCellPos = endc;
}


Ladder::~Ladder()
{
}
