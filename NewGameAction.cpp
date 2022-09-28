#include"NewGameAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
}

void NewGameAction::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pGrid->PrintErrorMessage("Are you sure you want to go to start a new game? y/n");
	isnew = pIn->GetSrting(pOut);
	pOut->PrintMessage("Starting New Game: Click Anywhere to Continue ...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void NewGameAction::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	if (isnew == "y") {
		pGrid->NewGame();
	}
}

NewGameAction::~NewGameAction() {

}