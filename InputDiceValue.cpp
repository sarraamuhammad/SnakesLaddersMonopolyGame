
#include "InputDiceValue.h"
#include "Grid.h"
#include "Player.h"


InputDiceValue::InputDiceValue(ApplicationManager * pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void InputDiceValue::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please, enter a dice value between 1-6");
	DiceValue = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
	while (DiceValue > 6 || DiceValue < 1)
	{
		pOut->PrintMessage("Please, Re-enter a dice value between 1-6");
		DiceValue = pIn->GetInteger(pOut);
		pOut->ClearStatusBar();
	}


}

void InputDiceValue::Execute()
{

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid)
	if (pGrid->GetEndGame() == true)
	{
		pOut->PrintMessage(" The Game is finished. Thank you ! Click to continue ....");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}

	// 2- Get the "current" player from pGrid ( in case the game wasn't finished )
	Player* CurrentPlayer = pGrid->GetCurrentPlayer();
	if (pGrid->GetEndGame() == true)
	{
		pOut->PrintMessage(" The Game is finished. Thank you ! Click to continue ....");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}
	/*if (CurrentPlayer->GetcheckPreventMove())    //card four
	{
		
		do {
			
			int x, y;
			pOut->PrintMessage("you are prevented from moving next turn...click to continue");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			pGrid->AdvanceCurrentPlayer();
			CurrentPlayer->incrementTurnCount();
			CurrentPlayer->rechargeWallet();
			i++;
		} while (i == 0);
			if (i == 3)
			{
				i = 0;
			}
		//return;}
	*/

	if (CurrentPlayer->GetCheckPrison())        
	{
		int x, y;
		pOut->PrintMessage(" You are now in prison ...click to continue.");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();

		int PrisonedPlayerNum = CurrentPlayer->GetPrisonedPlayerNum();
		int r=CurrentPlayer->GetTurnCount();
		for (int i = r; i < 3; i++)
		{
			if (CurrentPlayer->getPlayerNum() == PrisonedPlayerNum)
			{
				pOut->PrintMessage("you're still in prison...click to continue.");
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				pGrid->AdvanceCurrentPlayer();
				CurrentPlayer->incrementTurnCount();
				return;
			}
		}
	}

	
	// 3- ReadActionParameters
	ReadActionParameters();
		string msg = "You got a dice value of : " + to_string(DiceValue);
		pOut->PrintMessage(msg);
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	// 4- Move the currentPlayer using function Move of class player
	CurrentPlayer->Move(pGrid, DiceValue);
	// 5- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
}

InputDiceValue::~InputDiceValue()
{
}
