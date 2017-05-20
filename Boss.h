#include <string>
#include "Skill.h"
using namespace std;
class Boss
{
public:
	Boss(string _name, unsigned int _Hp, unsigned int _Gongji, unsigned int _Fangyu, unsigned int _exp, unsigned int _money, string skill1_name, int skill1_hurt, int skill1_type, string skill2_name, int skill2_hurt, int skill2_type, string skill3_name, int skill3_hurt, int skill3_type, string skill4_name, int skill4_hurt, int skill4_type );
	unsigned int getHp();
	unsigned int getGongji();
	unsigned int getFangyu();
	unsigned int getExp();
	unsigned int getMoney();
	string getName();

	Skill skill1;
	Skill skill2;
	Skill skill3;
	Skill skill4;

private:
	string name;
	unsigned int hp;
	unsigned int gongji;
	unsigned int fangyu;
	unsigned int exp;
	unsigned int money;
};