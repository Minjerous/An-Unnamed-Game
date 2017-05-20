#include <iostream>
#include "关卡.h"
using namespace std;
int Guanqia::getKaiqi()
{
		return kaiqi;
}
Guanqia::Guanqia(int _number, string _name)
{
		name = _name;
		number = _number;
		zhanling = false;
		kaiqi = false;
}
void Guanqia::get()
{
	cout << number << ")\t" << name << "\t";
	if (kaiqi == true)//判断是否开启或占领并输出 
	{
		if (zhanling == true)
		{
			cout << "已占领\n";
		}
		else
		{
			cout << "已开启\n";
		}
	}
	else
	{
		cout << "未开启\n";
	}
}
void Guanqia::set(bool _zhanling, bool _kaiqi)//更改是否开启或占领 
{
	zhanling = _zhanling;
	kaiqi = _kaiqi;
}