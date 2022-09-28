#include "CutCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"
#include "Grid.h"
CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
}

CutCardAction::~CutCardAction()
{
}

void CutCardAction::ReadActionParameters() {

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Cut Card: Click on Card to Copy...");
	cellPos = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void CutCardAction::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (pGrid->GetCard(cellPos)) {
		pGrid->SetClipboard(pGrid->GetCard(cellPos));
		pGrid->RemoveObjectFromCell(cellPos);
	}

	pGrid->UpdateInterface();

}