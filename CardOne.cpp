#include "CardOne.h"
#include<fstream>

CardOne::CardOne(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	walletAmount = 0;
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}
CardOne::CardOne() 
{
	cardNumber = 1;
   walletAmount = 0;
} //deafult constructor


void CardOne::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();

	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("New CardOne: Enter its wallet amount");

	walletAmount = pIn->GetInteger(pOut);

	while (walletAmount < 0) // asks the user to re-enter each time  if he entered negative number
	{
		pOut->PrintMessage("Invalid Amount, please re-enter");

		walletAmount = pIn->GetInteger(pOut);
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

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Card::Apply(pGrid, pPlayer);
	pPlayer->decrementWallet(walletAmount); //defined in class player
	
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne

}
void CardOne::Save(ofstream& OutFile, objecttype GameObject)
{
	OutFile << "" << cardNumber <<" " << position.GetCellNum() <<" " <<walletAmount;
}
void CardOne::Load(ifstream& Infile)
{

}

CardOne::~CardOne(void)
{
}