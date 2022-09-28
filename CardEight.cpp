#include "CardEight.h"
#include"Player.h"
#include<fstream>
#include<iostream>
using namespace std;
CardEight::CardEight()
{
	cardNumber = 8;
}
CardEight::CardEight(const CellPosition& pos) :Card(pos)
{
	cardNumber = 8;
	// set the inherited cardNumber data member with the card number (8 here) to update and adjust all the member functions accordingly
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();

	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("New CardEight : Enter its wallet amount :");

	AmountOfCoins = pIn->GetInteger(pOut);

	while (AmountOfCoins < 0) // asks the user to re-enter each time  if he entered negative number
	{
		pOut->PrintMessage("Invalid Amount, please re-enter");

		AmountOfCoins = pIn->GetInteger(pOut);
	}
	pOut->ClearStatusBar();

}
int CardEight::getAmouintOfCoins()
{
	return AmountOfCoins;
}
void CardEight::setAmouintOfCoins(int s)
{
	if (s >= 0)
	{
		AmountOfCoins = s;
	}
}
void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Card::Apply(pGrid, pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	int x, y;
	pOut->PrintMessage("You can pay your way out of prison or don't play for 3 turns (1/2)");
	string answer = pIn->GetSrting(pOut);
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();

	int p = pPlayer->GetTurnCount();

	if (answer == "1")
	{
		if ((pPlayer->GetWallet() <= AmountOfCoins))

		{
			pOut->PrintMessage("The coins in your wallet is not enough, You have to skip your next 3 turns...click to continue. ");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			pPlayer->SetcheckPrison(true);
			
		}
		else
		{
			pOut->PrintMessage("You are out of prison. ");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			pPlayer->decrementWallet( AmountOfCoins);
		}
	}
	else if (answer == "2")
	{
		
		pPlayer->SetcheckPrison(true);
	}
	pPlayer->SetTurnCount(p);
}
void CardEight::Save(ofstream& OutFile, objecttype GameObject)
{
	OutFile << "" << cardNumber << " " << position.GetCellNum() << endl;
}
void CardEight::Load(ifstream& Infile)
{
}

CardEight::~CardEight(){}