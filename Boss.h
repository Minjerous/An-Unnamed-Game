#include <string>
using namespace std;
class Boss
{
public:
	Boss(string _name,int _Hp,int _Gongji,int _Fangyu,int _exp,int _money);
	int getHp();
	int getGongji();
	int getFangyu();
	int getExp();
	int getMoney();
	string getName();


	void setSkill1(string name1, int skill1_hurt, int skill1_type);
	void setSkill2(string name2, int skill2_hurt, int skill2_type);
	void setSkill3(string name3, int skill3_hurt, int skill3_type);
	void setSkill4(string name4, int skill4_hurt, int skill4_type);
	string skill1_name; int skill1_hurt; int skill1_type;
	string skill2_name; int skill2_hurt; int skill2_type;
	string skill3_name; int skill3_hurt; int skill3_type;
	string skill4_name; int skill4_hurt; int skill4_type;
private:
	string name;
	int hp;
	int gongji;
	int fangyu;
	int exp;
	int money;
};