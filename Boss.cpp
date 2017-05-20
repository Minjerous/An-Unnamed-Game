#include <string>
#include "Boss.h"

Boss::Boss(string _name, unsigned int _hp, unsigned int _gongji, unsigned int _fangyu, unsigned  int _exp, unsigned int _money):name(_name), hp(_hp), gongji(_gongji), fangyu(_fangyu), exp(_exp), money(_money){}

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

void Boss::setSkill1(string name1, unsigned  int hurt1, int type1)
{
	skill1_name = name1;
	skill1_hurt = hurt1;
	skill1_type = type1;
}
void Boss::setSkill2(string name2, unsigned int hurt2, int type2)
{
	skill2_name = name2;
	skill2_hurt = hurt2;
	skill2_type = type2;
}
void Boss::setSkill3(string name3, unsigned int hurt3, int type3)
{
	skill3_name = name3;
	skill3_hurt = hurt3;
	skill3_type = type3;
}
void Boss::setSkill4(string name4, unsigned int hurt4, int type4)
{
	skill4_name = name4;
	skill4_hurt = hurt4;
	skill4_type = type4;
}