#include <string>
using namespace std;
class Guanqia
{
public:
	int getKaiqi();
	Guanqia(int _number, string _name);
	void get();
	void set(bool _zhanling, bool _kaiqi); 
private:
	int number;
	string name;
	bool zhanling;
	bool kaiqi;

};