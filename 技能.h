#include <string>
using namespace std;
class Skill
{
public:
	Skill(string _name,int _hurt,int _number);
	string getName();
	int getHurt();
private:
	string name;
	int hurt;
	int number;
};