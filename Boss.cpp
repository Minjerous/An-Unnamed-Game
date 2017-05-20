#include <string>
#include "Boss.h"

Boss::Boss(string _name, unsigned int _hp, unsigned int _gongji, unsigned int _fangyu, unsigned  int _exp, unsigned int _money, string skill1_name, int skill1_hurt, int skill1_type, string skill2_name, int skill2_hurt, int skill2_type, string skill3_name, int skill3_hurt, int skill3_type, string skill4_name, int skill4_hurt, int skill4_type) :name(_name), hp(_hp), gongji(_gongji), fangyu(_fangyu), exp(_exp), money(_money), skill1(skill1_name, skill1_hurt, skill1_type), skill2(skill2_name, skill2_hurt, skill2_type), skill3(skill3_name, skill3_hurt, skill3_type), skill4(skill4_name, skill4_hurt, skill4_type)
{
}

unsigned int Boss::getHp()
{
	return hp;
}
string Boss::getName()
{
	return name;
}
unsigned int Boss::getGongji()
{
	return gongji;
}
unsigned int Boss::getFangyu()
{
	return fangyu;
}
unsigned int Boss::getExp()
{
	return exp;
}
unsigned int Boss::getMoney()
{
	return money;
}