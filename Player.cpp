#include "Player.h"
#include"Card.h"
#include "GameObject.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	justRolledDiceNum = 0;
	checkPreventMove = false;
	checkPrison = false;
	//hasExtraDiceRoll = false;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	if (wallet > 0)
		this->wallet = wallet;

	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}
void Player::SetStepCount(int step)
{
	stepCount = (step > 0) ? step : 0;
}
void Player::SetTurnCount(int turn)
{
	turnCount = (turn < 3 && turn > -1) ? turn : 0;
}
// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	pOut->DrawPlayer(GetCell()->GetCellPosition(), playerNum, playerColor);

	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	CellPosition pos = pCell->GetCellPosition();
	pOut->DrawPlayer(pos, playerNum, cellColor);

	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======
void  Player::rechargeWallet()
{
	wallet = wallet + (justRolledDiceNum * 10);

}
void Player::Move(Grid* pGrid, int diceNumber)
{
	Output* pOut = pGrid->GetOutput(); //first create input and output pointers 
	Input* pIn = pGrid->GetInput();
	int x, y; //to be used in get point clicked  //note: i'm using get point clicked most of the time Not get cell clicked to avoid if the user clicked outside the grid
	turnCount++;

	if (turnCount == 3)
	{
		rechargeWallet();
		pOut->PrintMessage("your new wallet amount is : " + to_string(wallet) + "click to continue.....");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		return; // recharges his wallet ,do not move and exit the function
	}

	if (pGrid->GetCurrentPlayer()->GetWallet() == 0)//checks that current player has enough money to move
	{
		pOut->PrintMessage("No enough money in your wallet , wait for your next turn to move ..click to continue.");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		return;//exits the function , do not move
	}

	setJustRolledDice(diceNumber);
	Player* pPlayer = pGrid->GetCurrentPlayer(); //create player pointer to get its current cell 

	CellPosition pos = (pPlayer->GetCell())->GetCellPosition(); //gets the current cell position of the current player;
	if (pCell->HasCard() == NULL)
		pOut->DrawPlayer(pos, playerNum, UI.CellColor_NoCard);
	else
		pOut->DrawPlayer(pos, playerNum, UI.CellColor_HasCard);

	pos.AddCellNum(justRolledDiceNum); //update the position of the current player 

	if (pos.IsValidCell() != 1) //check the updated cell position to be inside the grid range
	{
		pOut->PrintMessage("Destination out of range , try again  the next turn ,....... click to continue.");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
	pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), pos);

	if (pPlayer->GetCell()->GetCellPosition().GetCellNumFromPosition(pos) == 99)
	{
		pOut->PrintMessage("Congrats! you have reached the end cell.... click to continue");
		pGrid->SetEndGame(true);
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		return;
	}

	if (pCell->GetGameObject() != NULL)
		pCell->GetGameObject()->Apply(pGrid, pPlayer);
}


void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
void Player::decrementWallet( int value)
{
	wallet = wallet - value;
}
void  Player::setJustRolledDice(int value)
{
	if (value > 0 && value < 6)
		justRolledDiceNum = value;
}
int Player::getPlayerNum() const
{
	return playerNum;
}
void  Player::SetcheckPreventMove(bool checkPreventMove)
{
	this->checkPreventMove = checkPreventMove;
}
bool  Player::GetcheckPreventMove()
{
	return checkPreventMove;
}
int  Player::incrementTurnCount()
{
	return turnCount++;
}
void Player::SetcheckPrison(bool checkPrison)
{
	this->checkPrison = checkPrison;
}
bool Player::GetCheckPrison()
{
	return checkPrison;
}
int Player::GetPrisonedPlayerNum()
{
	return playerNum;
}

 void Player::SetcheckCardFive(bool checkCardFiveheck)
{
	 this->checkCardFive = checkCardFive;
}
bool Player::GetcheckCardFive()
{
	return checkCardFive;
}
int Player::getJustRolledDice()
{
	return justRolledDiceNum;
}