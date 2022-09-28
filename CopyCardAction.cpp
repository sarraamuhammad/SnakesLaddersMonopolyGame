#include "CopyCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"
#include "Grid.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
}

CopyCardAction::~CopyCardAction()
{
}

void CopyCardAction::ReadActionParameters() {

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Copy Card: Click on Card to Copy...");
	cellPos = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void CopyCardAction::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (pGrid->GetCard(cellPos)!=NULL) 
	{
		pGrid->SetClipboard(pGrid->GetCard(cellPos));
	}
	pGrid->UpdateInterface();

}
