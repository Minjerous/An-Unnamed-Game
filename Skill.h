#include <string>
using namespace std;

class Skill
{
public:
	Skill(string _name, int _hurt, int _type, int _mp = 0, int _levelupmoney = 0, int _level = 0);
	string getName();
	int getHurt();
	int getType();
	int getMp();
	int getLevel();
	int getLevelupmoney();

	void setName(string _name);
	void setHurt(int _hurt);
	void setType(int type);
	void setMp(int _mp);
	void setLevel(int _level);
	void setLevelupmoney(int _money);

	
private:
	string name;
	int hurt;
	int type;
	int mp;
	int level;
	int levelupmoney;
};