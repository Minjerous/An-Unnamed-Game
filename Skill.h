#ifndef SKILL_H
#define SKILL_H
#include <string>
using namespace std;

class Skill
{
public:
	Skill(string _name = "", int _hurt = 0, int _type = 0, int _mp = 0, int _levelupmoney = 0, int _level = 0);
	~Skill();
	string getName() const;
	unsigned int getHurt() const;
	unsigned int getType() const;
	unsigned int getMp() const;
	unsigned int getLevel() const;
	unsigned int getLevelupmoney() const;

	void setName(string _name);
	void setHurt(int _hurt);
	void setType(int type);
	void setMp(int _mp);
	void setLevel(int _level);
	void setLevelupmoney(int _money);

	
private:
	string name;
	unsigned int hurt;
	unsigned int type;
	unsigned int mp;
	unsigned int level;
	unsigned int levelupmoney;
};
#endif