#pragma once
#include "Action.h"
class OpenGridAction :
	public Action
{

	string savefilename;

public:
	OpenGridAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~OpenGridAction();
};

