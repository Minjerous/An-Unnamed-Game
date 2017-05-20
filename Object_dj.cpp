#include <string>
#include "Object_dj.h"

Object_dj::Object_dj(string _name, string _explain, int _price, int _id, int _number, int _order)
	: Object(_name, _explain, _price, _order), id(_id),number(_number){}
Object_dj::~Object_dj()
{
}



int Object_dj::getID() const
{
	return id;
}
int Object_dj::getNumber() const
{
	return number;
}

void Object_dj::setID(int _id)
{
	id = _id;
}
void Object_dj::setNumber(int _number)
{
	number = _number;
}