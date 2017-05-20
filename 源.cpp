#include <iostream>
#include <string>
using namespace std;

string Name;
void XianShi(int GongJi, int FangYu, int HP)
{
	int ZhanDouLi = GongJi * 2 + FangYu * 2 + HP;
	cout << "你的战斗力为" << ZhanDouLi << "\n";
	cout << "你的生命值为" << HP << "\n";
	cout << "你的攻击力为" << GongJi << "\n";
	cout << "你的防御力为" << FangYu << "\n";
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
	else
		if (Name == "肖培成" || Name == "培成" || Name == "xiaopeicheng" || Name == "XIAOPEICHENG" || Name == "peicheng" || Name == "PEICHENG")
		{
			cout << "培成，实行计划！\n\n";
		}
		else
			if (Name == "马超" || Name == "machao" || Name == "MACHAO" || Name == "修罗马超")
			{
				cout << "马超，别忘了在211区玩呀！\n\n";
			}
			else
			{
				cout << "你好，" << Name << "，欢迎进入这个逗比的游戏。" << endl << endl;
			}
}

int main()
{
	Version(1.03f);

	CheckName();

	int HP = 100;
	int GongJi = 20;
	int FangYu = 20;
	XianShi(GongJi, FangYu, HP);
	system("pause");
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "错误：0x80072ee2		您的计算机配置不足以运行该游戏，请更换硬件或计算机.";
	system("pause");
	return 0;
}
