#include <string>
using namespace std;

class Object_dj
{
public:
	Object_dj(string _name, string _explain, int _price, int _id,int _number = 0,int _order = 0);
	int getID() const;
	int getNumber() const;
	int getOrder() const;
	int getPrice() const;
	string getName() const;
	string getExplain() const;
	void setID(int _id);
	void setNumber(int _number);
	void setOrder(int _order);
	void setPrice(int _price);
	void setName(string _name);
	void setExplain(string _explain);

private:
	string name;
	string explain;
	int id;
	int price;
	int number;//数量
	const int order;//顺序

};