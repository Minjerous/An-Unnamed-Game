#ifndef GUANQIA_H
#define GUANQIA_H
#include <string>
using namespace std;
class Guanqia
{
public:
	Guanqia(int _number, string _name, bool _kaiqi = false, bool _zhanling = false); 
	~Guanqia();
	int getKaiqi() const;
	void get() const;
	void set(bool _zhanling, bool _kaiqi); 
private:
	const int number;
	const string name;
	bool zhanling;
	bool kaiqi;

};
#endif