#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (0 <= v && v < 9) {
		vCell = v;
		return true;
	}
	else
		return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h >= 0 && h < 11) {
		hCell = h;
		return true;
	}
	else

		return false; // this line sould be changed with your implementation
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	///TODO: Implement this function as described in the .h file
	if ((0 <= vCell < 9) && (0 <= hCell < 11))
		return true;
	else
		return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
									  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
	int cellNum = 0;
	switch (cellPosition.hCell) {
	case(0): return cellNum = 1 + ((8 - (cellPosition.vCell)) * 11);
		break;
	case(1): return cellNum = 2 + ((8 - (cellPosition.vCell)) * 11);
		break;
	case(2): return cellNum = 3 + ((8 - (cellPosition.vCell)) * 11);
		break;
	case(3): return cellNum = 4 + ((8 - (cellPosition.vCell)) * 11);
		break;
	case(4): return cellNum = 5 + ((8 - (cellPosition.vCell)) * 11);
		break;
	case(5): return cellNum = 6 + ((8 - (cellPosition.vCell)) * 11);
		break;
	case(6): return cellNum = 7 + ((8 - (cellPosition.vCell)) * 11);
		break;
	case(7): return cellNum = 8 + ((8 - (cellPosition.vCell)) * 11);
		break;
	case(8): return cellNum = 9 + ((8 - (cellPosition.vCell)) * 11);
		break;
	case(9): return cellNum = 10 + ((8 - (cellPosition.vCell)) * 11);
		break;
	case(10): return cellNum = 11 + ((8 - (cellPosition.vCell)) * 11);
		break;
	}


	return cellNum; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file

	if (1 <= cellNum && cellNum <= 11) {
		position.SetVCell(8);
	}
	else if (12 <= cellNum && cellNum <= 22) {
		position.SetVCell(7);
	}
	else if (23 <= cellNum && cellNum <= 33) {
		position.SetVCell(6);
	}
	else if (34 <= cellNum && cellNum <= 44) {
		position.SetVCell(5);
	}
	else if (45 <= cellNum && cellNum <= 55) {
		position.SetVCell(4);
	}
	else if (56 <= cellNum && cellNum <= 66) {
		position.SetVCell(3);
	}
	else if (67 <= cellNum && cellNum <= 77) {
		position.SetVCell(2);
	}
	else if (78 <= cellNum && cellNum <= 88) {
		position.SetVCell(1);
	}
	else if (89 <= cellNum && cellNum <= 99) {
		position.SetVCell(0);
	}
	if (cellNum == (99 - (11 * position.vCell))) {
		position.SetHCell(10);
	}
	else if (cellNum == (98 - (11 * position.vCell))) {
		position.SetHCell(9);
	}
	else if (cellNum == (97 - (11 * position.vCell))) {
		position.SetHCell(8);
	}
	else if (cellNum == (96 - (11 * position.vCell))) {
		position.SetHCell(7);
	}
	else if (cellNum == (95 - (11 * position.vCell))) {
		position.SetHCell(6);
	}
	else if (cellNum == (94 - (11 * position.vCell))) {
		position.SetHCell(5);
	}
	else if (cellNum == (93 - (11 * position.vCell))) {
		position.SetHCell(4);
	}
	else if (cellNum == (92 - (11 * position.vCell))) {
		position.SetHCell(3);
	}
	else if (cellNum == (91 - (11 * position.vCell))) {
		position.SetHCell(2);
	}
	else if (cellNum == (90 - (11 * position.vCell))) {
		position.SetHCell(1);
	}
	else if (cellNum == (89 - (11 * position.vCell))) {
		position.SetHCell(0);
	}


	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum(int addedNum)
{

	/// TODO: Implement this function as described in the .h file
	int x;
	x = GetCellNumFromPosition(*this);
	x += addedNum;
	(*this) = GetCellPositionFromNum(x);

	// Note: this function updates the data members (vCell and hCell) of the calling object

}
/*
CellPosition CellPosition:: SubtractCellNum(int subtractednumber)
{
	int x;
	x = GetCellNumFromPosition(*this);
	x -= subtractednumber;
	 (*this) = GetCellPositionFromNum(x);

}
*/