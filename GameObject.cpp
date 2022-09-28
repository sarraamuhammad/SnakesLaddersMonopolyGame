#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	if(pos.IsValidCell()) //added
	position = pos; // Sets Position
}
GameObject::GameObject() {} //deafult constructor
CellPosition GameObject::GetPosition() const
{
	return position;
}
void GameObject::setPosition(CellPosition pos)
{
	if (pos.IsValidCell())
		position = pos;
}

GameObject::~GameObject()
{
}