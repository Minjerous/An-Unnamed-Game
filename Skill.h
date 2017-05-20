#include <string>
using namespace std;
class Skill
{
public:
	Skill(string _name, int _hurt, int _mp,int _levelupmoney,int _level = 0);
	string getName();
	int getHurt();
	int getMp();
	int getLevel();
	int getLevelupmoney();

	void setName(string _name);
	void setHurt(int _hurt);
	void setMp(int _mp);
	void setLevel(int _level);
	void setLevelupmoney(int _money);

	
private:
	string name;
	int hurt;
	int mp;
	int level;
	int levelupmoney;
};