#include <string>
#include "道具.h"
Object_dj::Object_dj(string _name, string _explain, int _price,int _id)
{
	name = _name;
	explain = _explain;
	id = _id;
	number = 0;
	order = 0;
	price = _price;

}

int Object_dj::getID()
{
	return id;
}
int Object_dj::getNumber()
{
	return number;
}
int Object_dj::getOrder()
{
	return order;
}
int Object_dj::getPrice()
{
	return price;
}
string Object_dj::getName()
{
	return name;
}
string Object_dj::getExplain()
{
	return explain;
}

void Object_dj::setID(int _id)
{
	id = _id;
}
void Object_dj::setNumber(int _number)
{
	number = _number;
}
void Object_dj::setOrder(int _order)
{
	order = _order;
}
void Object_dj::setPrice(int _price)
{
	price = _price;
}
void Object_dj::setName(string _name)
{
	name = _name;
}
void Object_dj::setExplain(string _explain)
{
	explain = _explain;
}