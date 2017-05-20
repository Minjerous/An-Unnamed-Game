#include <string>
#include "Object.h"

Object::Object(string _name, string _explain, int _price, int _order) :name(_name), explain(_explain), price(_price),  order(_order){}
Object::~Object()
{
}

int Object::getOrder() const
{
	return order;
}
int Object::getPrice() const
{
	return price;
}
string Object::getName() const
{
	return name;
}
string Object::getExplain() const
{
	return explain;
}
void Object::setPrice(int _price)
{
	price = _price;
}
void Object::setName(string _name)
{
	name = _name;
}
void Object::setExplain(string _explain)
{
	explain = _explain;
}