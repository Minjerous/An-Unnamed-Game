#include <string>
#include <iostream>
#include "技能.h"
using namespace std;
Skill::Skill(string _name, int _hurt, int _number)
{
	name = _name;
	hurt = _hurt;
	number = _number;
}
string Skill::getName()
{
	return name;
}
int Skill::getHurt()
{
	return hurt; 
	
}