#include "Input.h"

#include "Output.h"

//======================================================================================//
//								General Functions									    //
//======================================================================================//

Input::Input(window* pW)
{
	pWind = pW; // point to the passed window
}

////////////////////////////////////////////////////////////////////////////////////////// 

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y); // Note: x and y of WaitMouseClick are sent by reference
}

////////////////////////////////////////////////////////////////////////////////////////// 

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	// ESCAPE key is pressed
			return "";	// returns nothing as user has cancelled label
		if (Key == 13)	// ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	// BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

////////////////////////////////////////////////////////////////////////////////////////// 

int Input::GetInteger(Output* pO) const
{

	///TODO: implement the GetInteger function as described in Input.h file 
	//       using function GetString() defined above and function stoi()

	string input;
	int integer;
	input = GetSrting(pO);
	integer = stoi(input);


	// Note: stoi(s) converts string s into its equivalent integer (for example, "55" is converted to 55)

	return integer; // this line should be changed with your implementation
}

//======================================================================================//
//								Game  Functions									        //
//======================================================================================//

ActionType Input::GetUserAction() const
{
	int x = -1, y = -1;
	GetPointClicked(x, y);

	//  ============ GUI in the Design mode ============
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// [1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			// Check which Menu item was clicked
			// ==> This assumes that menu items are lined up horizontally <==
				// Divide x coord of the point clicked by the menu item width (integer division)
				// If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_ADD_LADDER: return ADD_LADDER;
			case ITM_ADD_SNAKE: return ADD_SNAKE;
			case ITM_ADD_CARD: return ADD_CARD;
			case ITM_TO_PLAY_MODE: return TO_PLAY_MODE;
			case ITM_CUT_CARD: return CUT_CARD;
				///TODO: Add cases for the other items of Design Mode

			case ITM_COPY_CARD:return COPY_CARD;
			case ITM_DELETE_CARD:return DELETE_CARD;
			case ITM_PASTE_CARD:return PASTE_CARD;
			case ITM_SAVE_GRID:return SAVE_GRID;
			case ITM_OPEN_GRID:return OPEN_GRID;
			case ITM_EXIT:return EXIT;

			default: return EMPTY;	// A click on empty place in toolbar
			}
		}

		// [2] User clicks on the grid area
		if ((y >= UI.ToolBarHeight) && (y < UI.height - UI.StatusBarHeight))
		{
			return GRID_AREA;
		}

		// [3] User clicks on the status bar
		return STATUS;

	}
	// ============ GUI in the Play mode ============
	else
	{
		int ClickedItemOrder = (x / UI.MenuItemWidth);
		///TODO:
		// perform checks similar to Design mode checks above for the Play Mode
		// and return the corresponding ActionType
		switch (ClickedItemOrder)
		{
		case ITM_ROLL_DICE:return ROLL_DICE; // just for now ==> This should be updated
		case ITM_SWITCH_TO_DESIGN_MODE:return TO_DESIGN_MODE;
		case ITM_NEW_GAME:return NEW_GAME;
		case ITM_INPUT_DICE_VALUE:return INPUT_DICE_VALUE;
		case ITM_EXIT_PLAY_MODE:return EXIT;
		default: return EMPTY;
		}



	}

}

////////////////////////////////////////////////////////////////////////////////////////// 

CellPosition Input::GetCellClicked() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	// Get the coordinates of the user click

	CellPosition cellPos;

	if (UI.InterfaceMode == MODE_DESIGN)
	{
		if (y >= UI.ToolBarHeight && y <= (UI.height - UI.StatusBarHeight))
		{
			///TODO: SetHCell and SetVCell of the object cellPost appropriately
			//       using the coordinates x, y and the appropriate variables of the UI_Info Object (UI)
			for (int i = 0; i < 11; i++) {
				if ((UI.CellWidth * i) <= x && x < ((i + 1) * UI.CellWidth)) {
					cellPos.SetHCell(i);
					break;
				}
			}

			for (int i = 0; i < 9; i++) {

				if (((i + 1) * UI.CellHeight) <= y && y < ((i + 2) * UI.CellHeight))
				{
					cellPos.SetVCell(i);
					break;
				}


			}
		}

		return cellPos;
	}
}
////////////////////////////////////////////////////////////////////////////////////////// 
