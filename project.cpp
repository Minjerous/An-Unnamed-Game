#include <iostream>
using namespace std;


void XianShi(int GongJi,int FangYu,int HP) 
{
	int ZhanDouLi=GongJi*2+FangYu*2+HP;
	cout<<"你的战斗力为"<<ZhanDouLi<<"\n";
	cout<<"你的生命值为"<<HP<<"\n";
	cout<<"你的攻击力为"<<GongJi<<"\n";
	cout<<"你的防御力为"<<FangYu<<"\n";
} 
int main()
{
	string Name;
	int a;
	char Yes_or_No;
	cout<<"版本号：V1.0\n" ;
	cout<<"先声明下，这是一个很无趣的游戏.\n";
	cout<<"你确定要玩吗？（Y/N）\n";
	cin>> Yes_or_No;
	if (Yes_or_No!='Y'&&Yes_or_No!='y')
		cout<<"退出中..." ;
	else
	
	cout<<"请输入你的名字:\n";
	cin>>Name;
	if(Name=="肖海洋"||Name=="海洛之神"||Name=="xiaohaiyang")
	{
		cout<<"海洋，看见我地理课本了吗？\n\n" ;
	} 
	else 
	{
		cout<<"你好，"<<Name<<"，欢迎进入这个逗比的游戏。"<<endl<<endl ;
	}
	
	int HP=100;
	int GongJi=20;
	int FangYu=20;
	XianShi(GongJi,FangYu,HP);
	cout<<"按任意键加回车继续\n";
	cin>>a; 
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"错误：0x80072ee2		您的计算机配置不足以运行该游戏，请更换硬件或计算机." ;
	cin>> a;
	return 0;
} 
