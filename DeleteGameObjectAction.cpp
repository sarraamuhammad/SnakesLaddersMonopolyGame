#include "DeleteGameObjectAction.h"
#include "Input.h"
#include"Output.h"
#include "Card.h"
#include "Grid.h"
DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{
}

DeleteGameObjectAction::~DeleteGameObjectAction()
{
}

void DeleteGameObjectAction::ReadActionParameters() {
	int x, y;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Delete Object: Click on Object to Delete...");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void DeleteGameObjectAction::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	pGrid->RemoveObjectFromCell(cellPos);
	pGrid->UpdateInterface();
}