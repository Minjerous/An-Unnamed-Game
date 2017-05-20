#ifndef OBJECT_DJ_H
#define OBJECT_DJ_H
#include <string>
#include "Object.h"
using namespace std;

class Object_dj:virtual public Object
{
public:
	Object_dj(string _name, string _explain, int _price, int _id,int _number = 0,int _order = 0);
	~Object_dj();
	int getID() const;
	int getNumber() const;
	void setID(int _id);
	void setNumber(int _number);

private:
	int id;
	int number;//数量
};
#endif