#pragma once

#include "Grid.h"
#include "Cell.h"

class Player
{
	Cell* pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
						   // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll				   // and reset again when reached 3
						   // it is used to indicate when to move and when to add to your wallet
	bool checkPreventMove;//used in cards 4 and 8(prison)
	bool checkPrison;
	bool checkCardFive;
public:

	Player(Cell* pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell* cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet
	void SetTurnCount(int turn);
	int GetTurnCount() const;	// A getter for the turnCount
	void SetStepCount(int step);

	//***********************************************************
	                   //these are added to be used in card 4,8

	void SetcheckPreventMove(bool checkPreventMove);
	bool GetcheckPreventMove();
	void SetcheckPrison(bool checkPrison);
	bool GetCheckPrison();
	int GetPrisonedPlayerNum();
	virtual void SetcheckCardFive(bool checkCardFiveheck);
	bool GetcheckCardFive();
	int getJustRolledDice();
	//***********************************************************
	
	/*
	
	bool CheckCard7();
	bool CheckMoveBackwards();
	///TODO: You can add setters and getters for data members here (if needed)
	*/
	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======

	void Move(Grid* pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
												// and Applies the Game Object's effect (if any) of the end reached cell 
												// for example, if the end cell contains a ladder, take it

	void AppendPlayerInfo(string& playersInfo) const; // Appends player's info to the input string, 
													   // for example: P0(wallet, turnCount)
	void decrementWallet( int value);
    void rechargeWallet(); // recharge the player wallet each three turns 
	void setJustRolledDice(int value); //check for the value (greater than 0 and less than or equal 6)
	int getPlayerNum() const;
	

	int incrementTurnCount();
};
