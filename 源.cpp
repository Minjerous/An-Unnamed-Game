#include <iostream>
#include <string>
using namespace std;

string Name; 
int HP = 100, GongJi = 20, FangYu = 20;
int Level = 1, Exp = 0; int MaxExp;
int Money = 0;

void zhuangtai(int GongJi_, int FangYu_, int HP_,int Money_,int Level_,int Exp_)
{
	int ZhanDouLi = GongJi * 2 + FangYu * 2 + HP;
	int MaxExp = Level * 10;
	cout << "你的战斗力为" << ZhanDouLi << "；\n";
	cout << "你的生命值为" << HP << "；\n";
	cout << "你的攻击力为" << GongJi << "；\n";
	cout << "你的防御力为" << FangYu << "；\n";
	cout << "你的等级为" << Level << "级；\n";
	cout << "你的经验值为" << Exp << "/" << MaxExp << "；\n";
	cout << "你的钢镚子为" << Money << "角；\n";
	cout << endl; 
}
void bag()
{
	int zero = 0;
	cout << 0 / zero;
}
void map()
{
	int zero = 0;
	cout << 0 / zero;
}
void LevelUp(int GongJi_, int FangYu_, int HP_, int Level_, int Exp_)
{
	int MaxExp_ = 10 * Level_;
	while(Exp_ >= MaxExp_)
	{
		Level_++;
		Exp_ =Exp_- MaxExp_;
		MaxExp_ = 10 * Level_;
		GongJi_ += 4;
		FangYu_ += 2;
		HP_ += 20;
	}
	if (Level_ > Level)
	{
		cout << "恭喜你升级了，同时获得了"<<(Level_-Level)*100<<"铜币\n";
		Money += (Level_ - Level) * 100;
	}
	Level = Level_;
	Exp = Exp_;
	GongJi = GongJi_;
	FangYu = FangYu_;
	HP = HP_;

}
void Version(float version)
{
	cout << "版本：" << version << endl;
}
void CheckName()
{
	cout << "请输入你的名字:\n";
	cin >> Name;
	if (Name == "肖海洋" || Name == "海洋" || Name == "xiaohaiyang" || Name == "XIAOHAIYANG" || Name == "haiyang" || Name == "HAIYANG" || Name == "海洛之神")
	{
		cout << "海洋，看见我地理课本了吗？\n\n";
	}
	else if (Name == "肖培成" || Name == "培成" || Name == "xiaopeicheng" || Name == "XIAOPEICHENG" || Name == "peicheng" || Name == "PEICHENG")
	{
			cout << "培成，实行计划！\n\n";
	}
	else if (Name == "马超" || Name == "machao" || Name == "MACHAO" || Name == "修罗马超")
	{
		cout << "马超，别忘了在211区玩呀！\n\n";
	}
	else if (Name == "巩新余" || Name == "新余" || Name == "gongxinyu" || Name == "GONGXINYU" || Name == "xinyu" || Name == "XINYU" || Name == "草帽路飞")
	{
		cout << "新余，你的许愿树成长度又满了....\n\n";
	}
	else
	{
		cout << "你好，" << Name << "，欢迎进入这个逗比的游戏。" << endl << endl;
	}
}
void DaiDing()
{
	int anjian;
	while (1==1)
	{
		cout << "请选择你要做什么：\n";
		cout << "1)背包(开发中)\n2)地图(开发中)\n3)状态\n";
		cin >> anjian;
		cout << "\n\n\n\n\n\n\n\n\n\n";
		switch (anjian)
		{
		case 1:bag(); break;
		case 2:map(); break;
		case 3:zhuangtai(GongJi, FangYu, HP, Money, Level, Exp);  break;
		default:cout << "输入错误\n\n";
		}
	}
}

int main()
{
	Version(1.06f);
	CheckName();
	zhuangtai(GongJi, FangYu, HP, Money, Level, Exp);
	system("pause"); 

	while (1 == 1)
	{
		DaiDing();
	}


	
	return 0;
}