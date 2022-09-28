#include "PasteCardAction.h"
#include "Output.h"
#include"Input.h"
#include "Grid.h"
#include "Ladder.h"
#include"Snake.h"
#include"Card.h"
#include"CardOne.h"
#include"CardTwo.h"
#include"CardThree.h"
PasteCardAction::PasteCardAction(ApplicationManager* pApp) :Action(pApp) {
	checkpaste = true;
}

PasteCardAction::~PasteCardAction() {

}

void PasteCardAction::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Paste Card: Click on Cell to Paste ...");
	newcellPos = pIn->GetCellClicked();
	if (newcellPos.IsValidCell() == false) {
		pGrid->PrintErrorMessage("Destination Cell Invalid! Click to continue...");
		pOut->ClearStatusBar();
		checkpaste = false;
		return;
	}
	if (newcellPos.GetCellNum() == 1 || newcellPos.GetCellNum() == 99) {
		pGrid->PrintErrorMessage("Error! Cannot place objects in 1st or last cell. Click to Continue...");
		pOut->ClearStatusBar();
		checkpaste = false;
		return;
	}
	Ladder* HasLadder = pGrid->GetLadder(newcellPos);
	if (HasLadder)
		if (HasLadder->GetPosition().GetCellNum() == newcellPos.GetCellNum())
		{
			pGrid->PrintErrorMessage(" Cell already has an object ! Click to continue ...");
			pOut->ClearStatusBar();
			checkpaste = false;
			return;
		}
	Snake* HasSnake = pGrid->GetSnake(newcellPos);
	if (HasSnake)
	{
		if (HasSnake->GetPosition().GetCellNum() == newcellPos.GetCellNum())
		{
			pGrid->PrintErrorMessage(" Cell already has an object ! Click to continue ...");
			pOut->ClearStatusBar();
			checkpaste = false;
			return;
		}
	}
	pOut->ClearStatusBar();
}

void PasteCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();
	if (checkpaste == true)
	{
		if (pGrid->GetClipboard())
		{
			Card* pastedcard;
			int cardNum = pGrid->GetClipboard()->GetCardNumber();
			switch (cardNum)
			{
			case 1:
				pastedcard = new CardOne(*(dynamic_cast <CardOne*> (pGrid->GetClipboard())));
				break;
			case 2:
				pastedcard = new CardTwo(*(dynamic_cast <CardTwo*> (pGrid->GetClipboard())));
				break;
			case 3:
				pastedcard = new CardThree(*(dynamic_cast <CardThree*> (pGrid->GetClipboard())));
				break;
			}
			pastedcard->setPosition(newcellPos);
		}
	}
	
}



