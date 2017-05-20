#include <iostream>
#include "Guanqia.h"
using namespace std;

Guanqia::Guanqia(int _number, string _name, bool _kaiqi,bool _zhanling) :number(_number), name(_name), kaiqi(_kaiqi), zhanling(_zhanling){}

int Guanqia::getKaiqi()
{
		return kaiqi;
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