//lesa sara
#include "CardTwelve.h"
#include<fstream>

CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber =12; // set the inherited cardNumber data member with the card number (9 here)
}
CardTwelve::CardTwelve() { cardNumber = 12; } //deafult constructor
CardTwelve::~CardTwelve(void)
{
}

void CardTwelve::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();

	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("New CardNine: Enter its price");

	CardPrice = pIn->GetInteger(pOut);

	while (CardPrice < 0) // asks the user to re-enter each time  if he entered negative number
	{
		pOut->PrintMessage("Invalid Amount, please re-enter");

		CardPrice = pIn->GetInteger(pOut);
	}
	pOut->ClearStatusBar();
	pOut->PrintMessage("Enter CardNine passer by fees");

	PasserFees = pIn->GetInteger(pOut);

	while (PasserFees < 0) // asks the user to re-enter each time  if he entered negative number
	{
		pOut->PrintMessage("Invalid Amount, please re-enter");

		CardPrice = pIn->GetInteger(pOut);
	}
	pOut->ClearStatusBar();


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."

	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar

}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Card::Apply(pGrid, pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	Cell* c;

	int x, y;
	pOut->PrintMessage("Do you want to buy this card?(y/n)");
	string answer = pIn->GetSrting(pOut);
	Player* playernext;

	if (answer == "y")
	{
		if ((pPlayer->GetWallet() <= CardPrice))

		{
			pOut->PrintMessage("You own this card now! ");
		}
		pPlayer->decrementWallet(CardPrice);
	}
	c = playernext->GetCell();
	CellPosition f = c->GetCellPosition();
	Card* GridCardOccupation = pGrid->GetCard(f);
	if (GridCardOccupation != NULL)
	{
		pOut->PrintMessage("You have to pay the fees to the owner of this card");
		pPlayer->decrementWallet(CardPrice);
		//pPlayer->se
	}

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number


}
void CardTwelve::Save(ofstream& OutFile, objecttype GameObject)
{
}
void CardTwelve::Load(ifstream& Infile)
{
}

