#include <string>
#include <iostream>
#include "Skill.h"
using namespace std;
Skill::Skill(string _name, int _hurt, int _type, int _mp, int _levelupmoney, int _level) :
	name(_name), hurt(_hurt), type(_type), mp(_mp), levelupmoney(_levelupmoney), level(_level){}
Skill::~Skill()
{
}
string Skill::getName() const
{
	return name;
}
int Skill::getHurt() const
{
	return hurt; 
}
int Skill::getType() const
{
	return type;
}
int Skill::getMp() const
{
	return mp;
}
int Skill::getLevel() const
{
	return level;
}
int Skill::getLevelupmoney() const
{
	return levelupmoney;
}
void Skill::setName(string _name)
{
	name = _name;
}
void Skill::setHurt(int _hurt)
{
	hurt = _hurt;
}
void Skill::setType(int _type)
{
	type = _type;
}
void Skill::setMp(int _mp)
{
	mp = _mp;
}
void Skill::setLevel(int _level)
{
	level = _level;
}
void Skill::setLevelupmoney(int _levelupmoney)
{
	levelupmoney = _levelupmoney;
}