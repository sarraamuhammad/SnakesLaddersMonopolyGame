#include "CardTen.h"
#include<fstream>
#include"Grid.h"
CardTen::CardTen(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 10; // set the inherited cardNumber data member with the card number (9 here)
	owner = NULL;
	Passer = NULL;
	sold = false;
	ownernumber = 0, ownerCellNumber = 0, passerCellNumber = 0, PasserNumber = 0;
}
CardTen::CardTen()
{
	cardNumber = 10;
	owner = NULL;
	Passer = NULL;
	sold = false;
	ownernumber = 0, ownerCellNumber = 0, passerCellNumber = 0, PasserNumber = 0;
} //deafult constructor
CardTen::~CardTen(void)
{
}
void CardTen::ReadCardParameters(Grid* pGrid)
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
}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	//ReadCardParameters(pGrid);


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Card::Apply(pGrid, pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	CellPosition PasserPosition;
	string answer;
	int x, y;
	if (sold == false)
	{

		pOut->PrintMessage("Do you want to buy this card?(y/n)");
		answer = pIn->GetSrting(pOut);
	}
	int playernumber;
	if (sold == false)
	{
		if (answer == "y")
		{

			if ((pPlayer->GetWallet() >= CardPrice))
			{
				pPlayer->decrementWallet(CardPrice);
				pOut->PrintMessage("You own this card now! ");
				sold = true;
				owner = pPlayer;

				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				ownerCellNumber = owner->GetCell()->GetCellPosition().GetCellNumFromPosition(owner->GetCell()->GetCellPosition());
				ownernumber = owner->getPlayerNum();
			}
		}
	}
	if (sold == true)
	{
		PasserPosition = pPlayer->GetCell()->GetCellPosition();
		passerCellNumber = PasserPosition.GetCellNumFromPosition(PasserPosition);
		PasserNumber = pPlayer->getPlayerNum();
		if (PasserNumber != ownernumber && passerCellNumber == ownerCellNumber) //check that the passer passes on the owner 's card
		{
			pPlayer->decrementWallet(PasserFees);

			int temp = owner->GetWallet() + PasserFees;
			owner->SetWallet(temp);
			pOut->PrintMessage(" Owner  new Wallet = " + to_string(owner->GetWallet()) + " , Passer  new Wallet = " + to_string(pPlayer->GetWallet()));
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
		for (int i = 2; i < 99; i++)
		{

		}
	}
}
void CardTen::Save(ofstream& OutFile, objecttype GameObject)
{
}
void CardTen::Load(ifstream& Infile)
{
}
Player* CardTen::GetOwner()
{
	return owner;
}
Player* CardTen::GetPasser()
{
	return Passer;
}

