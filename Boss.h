#include <string>
using namespace std;
class Boss
{
public:
	Boss(string _name, unsigned int _Hp, unsigned int _Gongji, unsigned int _Fangyu, unsigned int _exp, unsigned int _money);
	unsigned int getHp();
	unsigned int getGongji();
	unsigned int getFangyu();
	unsigned int getExp();
	unsigned int getMoney();
	string getName();


	void setSkill1(string name1, unsigned int skill1_hurt, int skill1_type);
	void setSkill2(string name2, unsigned int skill2_hurt, int skill2_type);
	void setSkill3(string name3, unsigned  int skill3_hurt, int skill3_type);
	void setSkill4(string name4, unsigned int skill4_hurt, int skill4_type);
	string skill1_name; int skill1_hurt; int skill1_type;
	string skill2_name; int skill2_hurt; int skill2_type;
	string skill3_name; int skill3_hurt; int skill3_type;
	string skill4_name; int skill4_hurt; int skill4_type;
private:
	string name;
	unsigned int hp;
	unsigned int gongji;
	unsigned int fangyu;
	unsigned int exp;
	unsigned int money;
};