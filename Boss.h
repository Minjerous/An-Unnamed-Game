#ifndef BOSS_H
#define BOSS_H
#include <string>
#include "Skill.h"
using namespace std;
class Boss
{
public:
	Boss(string _name, unsigned int _Hp, unsigned int _Gongji, unsigned int _Fangyu, unsigned int _exp, unsigned int _money, string skill1_name, int skill1_hurt, int skill1_type, string skill2_name, int skill2_hurt, int skill2_type, string skill3_name, int skill3_hurt, int skill3_type, string skill4_name, int skill4_hurt, int skill4_type );
	~Boss();
	unsigned int getHp() const;
	unsigned int getGongji() const;
	unsigned int getFangyu() const;
	unsigned int getExp() const;
	unsigned int getMoney() const;
	string getName() const;

	Skill skill1;
	Skill skill2;
	Skill skill3;
	Skill skill4;

private:
	const string name;
	const unsigned int hp;
	const unsigned int gongji;
	const unsigned int fangyu;
	const unsigned int exp;
	const unsigned int money;
};
#endif