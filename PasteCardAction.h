#pragma once
#include "Action.h"
#include"Card.h"
class PasteCardAction :
    public Action
{
    CellPosition newcellPos;
    bool checkpaste;

public:
    PasteCardAction(ApplicationManager* pApp); //constructor
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~PasteCardAction();//destructor
};

