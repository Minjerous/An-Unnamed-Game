﻿#include <string>
#include "Object_dj.h"

Object_dj::Object_dj(string _name, string _explain, int _price, int _id, int _number, int _order) :
	name(_name), explain(_explain), price(_price), id(_id),number(_number),order(_order){}

int Object_dj::getID() const
{
	return id;
}
int Object_dj::getNumber() const
{
	return number;
}
int Object_dj::getOrder() const
{
	return order;
}
int Object_dj::getPrice() const
{
	return price;
}
string Object_dj::getName() const
{
	return name;
}
string Object_dj::getExplain() const
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