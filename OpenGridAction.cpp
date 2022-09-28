#include "OpenGridAction.h"
#include<fstream>
#include"GameObject.h"
#include"Input.h"
#include "Output.h"
#include"Grid.h"
#include"Ladder.h"
#include "Snake.h"
#include"Card.h"
#include"Player.h"
#include"Cell.h"
#include"CardOne.h"


OpenGridAction::OpenGridAction(ApplicationManager* pApp) :Action(pApp) {
}

void OpenGridAction::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Open Grid: Enter File Name...");
	savefilename = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}

void OpenGridAction::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	ifstream savefile;
	int ladders, snakes, cards;
	savefile.open(savefilename);
	if (!savefile.is_open())
	{
		pGrid->PrintErrorMessage("File Does Not Exist!. Click to continue ... ");
		return;
	}
	CellPosition firstcell(1);
	if (pGrid->GetNextLadder(firstcell) || pGrid->GetNextSnake(firstcell) || pGrid->GetNextCard(firstcell))
	{
		pGrid->EmptyGrid();
	}
	savefile >> ladders;
	GameObject* pLoadObject;
	for (int i = 0; i < ladders; i++)
	{
		pLoadObject = new Ladder();
		pLoadObject->Load(savefile);
		pGrid->AddObjectToCell(pLoadObject);
	}
	savefile >> snakes;
	for (int i = 0; i < snakes; i++)
	{
		pLoadObject = new Snake();
		pLoadObject->Load(savefile);
		pGrid->AddObjectToCell(pLoadObject);
	}
	savefile >> cards;
	for (int i = 0; i < cards; i++)
	{
		int cardNum;
		savefile >> cardNum;
		switch (cardNum)
		{
		case 1:
			pLoadObject = new CardOne();
			pLoadObject->Load(savefile);
			pGrid->AddObjectToCell(pLoadObject);
			break;

		}
	}
	savefile.close();
}

OpenGridAction::~OpenGridAction() {


}