#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"

AddCardAction::AddCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters()
{
	int x, y;
	Grid* pGrid = pManager->GetGrid();

	Input* pIn = pGrid->GetInput();

	Output* pOut = pGrid->GetOutput();

	
	pOut->PrintMessage("Type card number : ");

	int r = pIn->GetInteger(pOut);

	while (r > 13 || r < 0)
	{
		pOut->PrintMessage("Enter a valid card number from 1 to 12");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
		cardNumber = r;
		pOut->PrintMessage("click on the card cell.");
		cardPosition = pIn->GetCellClicked();
		pOut->ClearStatusBar();
	
}



void AddCardAction::Execute()
{
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	// 1- The first line of any Action Execution is to read its parameter first
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card* pCard = NULL; // will point to the card object type


	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;

		// A- Add the remaining cases


	case 2:
		pCard = new CardTwo(cardPosition);
		break;

		// A- Add the remaining cases
	case 3:
		pCard = new CardThree(cardPosition);
		break;

		// A- Add the remaining cases


	case 4:
		pCard = new CardFour(cardPosition);
		break;

	case 5:
		pCard = new CardFive(cardPosition);
		break;

		// A- Add the remaining cases


	case 6:
		pCard = new CardSix(cardPosition);
		break;

	case 7:
		pCard = new CardSeven(cardPosition);
		break;

		// A- Add the remaining cases


	case 8:
		pCard = new CardEight(cardPosition);
		break;

	case 9:
		pCard = new CardNine(cardPosition);
		break;



	case 10:
		pCard = new CardTen(cardPosition);
		break;



	case 11:
		pCard = new CardEleven(cardPosition);
		break;

	case 12:
		pCard = new CardTwelve(cardPosition);
		break;

		// A- Add the remaining cases
	}


	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		Grid* grid = pManager->GetGrid();
		pCard->ReadCardParameters(grid);
		// A- We get a pointer to the Grid from the ApplicationManager

		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type

		// C- Add the card object to the GameObject of its Cell:

		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		bool r = grid->AddObjectToCell(pCard);
		if (r == false)
		{
			grid->PrintErrorMessage("Error!!The cell is not empty");

		}


	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
