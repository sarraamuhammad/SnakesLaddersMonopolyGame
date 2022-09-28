#pragma once

#include "Action.h"

class NewGameAction : public Action
{
	string isnew;
public:
	NewGameAction(ApplicationManager* pApp);

	virtual ~NewGameAction();

	virtual void ReadActionParameters();

	virtual void Execute();
};

