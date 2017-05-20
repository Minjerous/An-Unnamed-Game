#ifndef OBJECT_H
#define OBJECT_H
#include <string>
using namespace std;

class Object
{
public:
	Object(string _name, string _explain, int _price, int _order = 0);
	~Object();
	int getOrder() const;
	int getPrice() const;
	string getName() const;
	string getExplain() const;
	void setOrder(int _order);
	void setPrice(int _price);
	void setName(string _name);
	void setExplain(string _explain);

protected:
	string name;
	string explain;
	int price;
	const int order;//Ë³Ðò

};
#endif