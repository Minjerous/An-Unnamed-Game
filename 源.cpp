#include <iostream>
#include <cstdlib> 
#include <string>
#include <ctime>
#include "Guanqia.h"
#include "Skill.h"
#include "Object_dj.h"
#include "Boss.h"
using namespace std;

int anjian;
string Name;
int Hp = 50, Mp = 50, GongJi = 10, FangYu = 0;
int Level = 1, Exp = 0, MaxExp = 10;
int Money = 0;

Skill skill_1("", 0, 0);
Skill skill_2("", 0, 0);
Skill skill_3("", 0, 0);
Skill skill_4("", 0, 0);
Skill putonggongji("普通攻击", 80, 0);
Skill zhuangji("撞击", 50, 0);
Guanqia a_a(1, "大操场  "); 
Guanqia a_b(2, "大门    ");
Guanqia a_c(3, "男生宿舍");
Guanqia a_d(4, "实验楼  ");
Guanqia a_e(5, "办公楼  ");
Guanqia a_f(6, "艺术楼  ");
Guanqia a_g(7, "小操场  ");
Guanqia a_h(8, "教学楼  ");
Guanqia a_i(9, "食堂    ");
Guanqia a_j(10, "女生宿舍");
Boss kanmendashu ( "看门大叔", 100, 10, 0 ,5,5);
Object_dj bag_1("", "", 0, 0);
Object_dj bag_2("", "", 0, 0);
Object_dj bag_3("", "", 0, 0);
Object_dj bag_4("", "", 0, 0);
Object_dj bag_5("", "", 0, 0);
Object_dj bag_6("", "", 0, 0);
Object_dj bag_7("", "", 0, 0);
Object_dj bag_8("", "", 0, 0);
Object_dj bag_9("", "", 0, 0);
Object_dj xuantie("玄铁","在炼丹炉内打造装备所需的材料",2,1);
Object_dj sichou("丝绸", "在炼丹炉内打造装备所需的材料", 2,2);
Object_dj tanmu("檀木", "在炼丹炉内打造装备所需的材料", 2,3);

void Role_Show(int GongJi_, int FangYu_, int HP_, int Money_, int Level_, int Exp_); 
void Role_CheckName();
void Role_LevelUp(int _exp);
void Bag_Show();
void Bag_Show_dj(Object_dj *dj);
void Bag_Get_dj(Object_dj *dj);
void Bag_Get_zb();
void Skill_Show();
void Skill_Show_skill(Skill _skill);
void Skill_Study();
void Skill_Study_output(int _number,Skill _skill);
void Skill_Study_skill(Skill _skill);
void Map_Show();
void Save_Show();
void About_Show();
void Exit_Show();
void Fighting(Boss boss);




int main()
{
	//初始化背包数据成员
	bag_1.setOrder(1);
	bag_2.setOrder(2);
	bag_3.setOrder(3);
	bag_4.setOrder(4);
	bag_5.setOrder(5);
	bag_6.setOrder(6);
	bag_7.setOrder(7);
	bag_8.setOrder(8);
	bag_9.setOrder(9);
	//开始定义Boss技能	1:攻击 2:护盾 3:加血
	kanmendashu.setSkill1("呼叫120", 50,3);
	kanmendashu.setSkill2("关门", 60,2);
	kanmendashu.setSkill3("呼叫120", 50, 3);
	kanmendashu.setSkill4("关门", 60, 2);
	//开启第一关
	a_a.set(0, 1);
	//初始化技能
	putonggongji.setLevel(1);//开启普通攻击
	
	skill_1.setHurt(putonggongji.getHurt());
	skill_1.setName(putonggongji.getName());
	skill_1.setMp(putonggongji.getMp());

	while (true)
	{
		cout << "1)新的开始  2)读取存档（未开启）" << endl;
		cin >> anjian;
		system("cls");
		if (anjian == 1)
		{
			break;
		}
		else
		{
			cout << "该功能未开启"<<endl;
			system("pause");
			system("cls");
		}
	}

	Role_CheckName();
	system("pause");
	system("cls");
	cout << "你现在的状态为：\n";
	Role_Show(GongJi, FangYu, Hp, Money, Level, Exp);
	

	while (true)
	{
		cout << "请选择你要做什么：\n";
		cout << "1)角色\n2)背包\n3)技能\n4)地图\n5)保存\n6)关于\n7)退出\n";
		cin >> anjian;
		system("cls");
		switch (anjian)
		{
		case 1:Role_Show(GongJi, FangYu, Hp, Money, Level, Exp);  break;
		case 2:Bag_Show(); break;
		case 3:Skill_Show(); break;
		case 4:Map_Show(); break;
		case 5:Save_Show(); break;
		case 6:About_Show(); break;
		case 7:Exit_Show(); if (anjian == 1) return 0; break;
		default:;
		}
	}
	return 0;
}


void Role_Show(int GongJi_, int FangYu_, int HP_, int Money_, int Level_, int Exp_)
{
	cout << "昵称：" << Name << "；\n\n";
	int ZhanDouLi = Hp + Mp + GongJi * 2 + FangYu * 2;
	cout << "战斗力:" << ZhanDouLi << "；\n\n";
	cout << "生命值:" << Hp << "；\n";
	cout << "魔法值:" << Mp << "；\n\n";
	cout << "攻击力:" << GongJi << "；\n";
	cout << "防御力:" << FangYu << "；\n\n";
	cout << "等级:" << Level << "级；\n";
	cout << "经验值:" << Exp << "/" << MaxExp << "；\n";
	cout << endl;
	system("pause");
	system("cls");
}
void Role_CheckName()
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
	else if (Name == "刘希涛" || Name == "希涛" || Name == "liuxitao" || Name == "LIUXITAO" || Name == "xitao" || Name == "XITAO")
	{
		cout << "希涛，看见我物理配套来没？？？\n\n";
	}
	else if (Name == "孔龙" || Name == "恐龙" || Name == " konglong" || Name == "KONGLONG")
	{
		cout << "这是一个彩蛋，不是恐龙蛋。。。\n\n";
	}
	else
	{
		cout << "你好，" << Name << "，欢迎进入这个逗比的游戏。" << endl << endl;
	}
}
void Role_LevelUp(int _exp)
{
	Exp += _exp;
	int old_level;
	while (Exp >= MaxExp)
	{
		old_level = Level;
		Level++;
		Exp = Exp - MaxExp;
		MaxExp = 10 * Level;
		GongJi += 4;
		FangYu += 2;
		Hp += 20;
		Mp += 15;


		cout << "恭喜你升到了" << Level << "级了，战斗力提升" << endl;
	}
}

void Bag_Show()
{
	bool type = true;
	while (1 == 1)
	{
		if (type == true)
		{
			cout << "装备：\n";
			cout << "1)" << endl;
			cout << "2)" << endl;
			cout << "3)" << endl;
			cout << "4)" << endl;
			cout << "5)" << endl;
			cout << "6)" << endl;
			cout << "7)" << endl;
			cout << "8)" << endl;
			cout << "9)" << endl;
			cout << endl << "钢镚子: " << Money / 10 << " 元 " << Money % 10 << " 角" << endl << endl;

			cout << "1~9）选择物品 11)装备 12）道具 0)返回" << endl;
			cin >> anjian;
			system("cls");

			if (anjian == 1)
			{
				cout << "该处没有物品" << endl;
				system("pause");
				system("cls");
			}
			else if (anjian == 2)
			{
				cout << "该处没有物品" << endl;
				system("pause");
				system("cls");
			}
			else if (anjian == 3)
			{
				cout << "该处没有物品" << endl;
				system("pause");
				system("cls");
			}
			else if (anjian == 4)
			{
				cout << "该处没有物品" << endl;
				system("pause");
				system("cls");
			}
			else if (anjian == 5)
			{
				cout << "该处没有物品" << endl;
				system("pause");
				system("cls");
			}
			else if (anjian == 6)
			{
				cout << "该处没有物品" << endl;
				system("pause");
				system("cls");
			}
			else if (anjian == 7)
			{
				cout << "该处没有物品" << endl;
				system("pause");
				system("cls");
			}
			else if (anjian == 8)
			{
				cout << "该处没有物品" << endl;
				system("pause");
				system("cls");
			}
			else if (anjian == 9)
			{
				cout << "该处没有物品" << endl;
				system("pause");
				system("cls");
			}
			else if (anjian == 11)
			{
				type = true;
			}
			else if (anjian == 12)
			{
				type = false;
			}
			else if (anjian == 0)
			{
				break;
			}
		}
		else
		{
			cout << "道具：\n";

			cout << "1)" << bag_1.getName() << endl;
			cout << "2)" << bag_2.getName() << endl;
			cout << "3)" << bag_3.getName() << endl;
			cout << "4)" << bag_4.getName() << endl;
			cout << "5)" << bag_5.getName() << endl;
			cout << "6)" << bag_6.getName() << endl;
			cout << "7)" << bag_7.getName() << endl;
			cout << "8)" << bag_8.getName() << endl;
			cout << "9)" << bag_9.getName() << endl;
			cout << endl << "钢镚子: " << Money / 10 << " 元 " << Money % 10 << " 角" << endl << endl;

			cout << "1~9）选择物品 11)装备 12）道具 0)返回" << endl;
			cin >> anjian;
			system("cls");

			if (anjian == 1)
				Bag_Show_dj(&bag_1);
			else if (anjian == 2)
				Bag_Show_dj(&bag_2);
			else if (anjian == 3)
				Bag_Show_dj(&bag_3);
			else if (anjian == 4)
				Bag_Show_dj(&bag_4);
			else if (anjian == 5)
				Bag_Show_dj(&bag_5);
			else if (anjian == 6)
				Bag_Show_dj(&bag_6);
			else if (anjian == 7)
				Bag_Show_dj(&bag_7);
			else if (anjian == 8)
				Bag_Show_dj(&bag_8);
			else if (anjian == 9)
				Bag_Show_dj(&bag_9);
			else if (anjian == 11)
			{
				type = true;
			}
			else if (anjian == 12)
			{
				type = false;
			}
			else if (anjian == 0)
			{
				break;
			}
		}

	}
}
void Bag_Get_dj(Object_dj *dj)
{

	//判断是否已有该物品，若已有，数量+1
	if (bag_1.getID() == dj->getID())
	{
		bag_1.setNumber(bag_1.getNumber() + 1);
	}
	else if (bag_2.getID() == dj->getID())
	{
		bag_2.setNumber(bag_2.getNumber() + 1);
	}
	else if (bag_3.getID() == dj->getID())
	{
		bag_3.setNumber(bag_3.getNumber() + 1);
	}
	else if (bag_4.getID() == dj->getID())
	{
		bag_4.setNumber(bag_4.getNumber() + 1);
	}
	else if (bag_5.getID() == dj->getID())
	{
		bag_5.setNumber(bag_5.getNumber() + 1);
	}
	else if (bag_6.getID() == dj->getID())
	{
		bag_6.setNumber(bag_6.getNumber() + 1);
	}
	else if (bag_7.getID() == dj->getID())
	{
		bag_7.setNumber(bag_7.getNumber() + 1);
	}
	else if (bag_8.getID() == dj->getID())
	{
		bag_8.setNumber(bag_8.getNumber() + 1);
	}
	else if (bag_9.getID() == dj->getID())
	{
		bag_9.setNumber(bag_9.getNumber() + 1);
	}
	//判断背包的哪个位置为空位，将物品添加至空位
	else if (bag_1.getNumber() == 0)
	{
		bag_1.setID(dj->getID());
		bag_1.setName(dj->getName());
		bag_1.setExplain(dj->getExplain());
		bag_1.setPrice(dj->getPrice());
		bag_1.setNumber(1);
	}


	else if (bag_2.getNumber() == 0)
	{
		bag_2.setID(dj->getID());
		bag_2.setName(dj->getName());
		bag_2.setExplain(dj->getExplain());
		bag_2.setPrice(dj->getPrice());
		bag_2.setNumber(1);
	}


	else if (bag_3.getNumber() == 0)
	{
		bag_3.setID(dj->getID());
		bag_3.setName(dj->getName());
		bag_3.setExplain(dj->getExplain());
		bag_3.setPrice(dj->getPrice());
		bag_3.setNumber(1);
	}

	else if (bag_4.getNumber() == 0)
	{
		bag_4.setID(dj->getID());
		bag_4.setName(dj->getName());
		bag_4.setExplain(dj->getExplain());
		bag_4.setPrice(dj->getPrice());
		bag_4.setNumber(1);
	}


	else if (bag_5.getNumber() == 0)
	{
		bag_5.setID(dj->getID());
		bag_5.setName(dj->getName());
		bag_5.setExplain(dj->getExplain());
		bag_5.setPrice(dj->getPrice());
		bag_5.setNumber(1);
	}

	else if (bag_6.getNumber() == 0)
	{
		bag_6.setID(dj->getID());
		bag_6.setName(dj->getName());
		bag_6.setExplain(dj->getExplain());
		bag_6.setPrice(dj->getPrice());
		bag_6.setNumber(1);
	}


	else if (bag_7.getNumber() == 0)
	{
		bag_7.setID(dj->getID());
		bag_7.setName(dj->getName());
		bag_7.setExplain(dj->getExplain());
		bag_7.setPrice(dj->getPrice());
		bag_7.setNumber(1);
	}


	else if (bag_8.getNumber() == 0)
	{
		bag_8.setID(dj->getID());
		bag_8.setName(dj->getName());
		bag_8.setExplain(dj->getExplain());
		bag_8.setPrice(dj->getPrice());
		bag_8.setNumber(1);
	}


	else if (bag_9.getNumber() == 0)
	{
		bag_9.setID(dj->getID());
		bag_9.setName(dj->getName());
		bag_9.setExplain(dj->getExplain());
		bag_9.setPrice(dj->getPrice());
		bag_9.setNumber(1);
	}






	else
		cout << "背包已满！";
}
void Bag_Show_dj(Object_dj *dj)
{
	if (dj->getNumber() != 0)
	{
		while (dj->getNumber() != 0)
		{
			cout << "名称：" << dj->getName() << endl;
			cout << "介绍：" << dj->getExplain() << endl;
			cout << "数量：" << dj->getNumber() << " 个" << endl;
			cout << "售价：" << dj->getPrice() << " 角/个" << endl;
			cout << "1)使用 2)出售 3)返回" << endl;
			cin >> anjian;
			system("cls");
			if (anjian == 1)
			{
				cout << "该物品不能使用";
				system("pause");
				system("cls");
			}
			else if (anjian == 2)
			{
				while (true)
				{
					cout << "名称：" << dj->getName() << endl;
					cout << "介绍：" << dj->getExplain() << endl;
					cout << "数量：" << dj->getNumber() << " 个" << endl;
					cout << "售价：" << dj->getPrice() << " 角/个" << endl;
					cout << "请输入您要删除的数量" << endl;
					cin >> anjian;
					system("cls");
					if (anjian > dj->getNumber() || anjian < 0)
					{
						cout << "哎哎,别着急，数字都打错了" << endl;
						system("pause");
						system("cls");
					}
					else
					{
						Money += anjian*dj->getPrice();
						dj->setNumber(dj->getNumber() - anjian);

						cout << "名称：" << dj->getName() << endl;
						cout << "介绍：" << dj->getExplain() << endl;
						cout << "数量：" << dj->getNumber() << " 个" << endl;
						cout << "售价：" << dj->getPrice() << " 角/个" << endl;
						cout << "你卖掉了" << anjian << "个" << xuantie.getName() << ",获得了" << anjian*xuantie.getPrice() << "毛。" << endl;
						if (dj->getNumber() == 0)
						{
							dj->setName("");
							dj->setExplain("");
							dj->setID(0);
							dj->setPrice(0);
						}
						system("pause");
						system("cls");
						break;
					}
				}
			}
			else if (anjian == 3)
			{
				break;
			}
		}
	}
	else
	{
		cout << "该处没有物品" << endl;
		system("pause");
		system("cls");
	}
}

void About_Show()
{
	cout << "关于：" << endl;
	cout << "版本：1.16" << endl;
	system("pause");
	system("cls");
}

void Skill_Show()
{
	if (Level < 0)
	{
		cout << "你的等级不足（5级开启）\n";
		system("pause");
		system("cls");
		
		return;
	}
	while (true)
	{
		cout << "1)" << skill_1.getName() << endl;
		cout << "2)" << skill_2.getName() << endl;
		cout << "3)" << skill_3.getName() << endl;
		cout << "4)" << skill_4.getName() << endl;
		cout << "1~4)选择技能 5)学习/升级技能 6)替换技能 0)返回\n";
		cin >> anjian;
		system("cls");
		if (anjian == 1)
			Skill_Show_skill(skill_1);
		else if (anjian == 2)
			Skill_Show_skill(skill_2);
		else if (anjian == 3)
			Skill_Show_skill(skill_3);
		else if (anjian == 4)
			Skill_Show_skill(skill_4);

		else if (anjian == 5)
		{
			Skill_Study();
		}
		else if (anjian == 6)
		{
			cout << "该功能未开启\n";
			system("pause");
			system("cls");
		}
		else if (anjian == 0)
		{
			system("cls");
			break;
		}
	}
	

}
void Skill_Show_skill(Skill _skill)
{
	cout << anjian << ")" << _skill.getName() << endl;
	cout << "威力：" << _skill.getHurt() << endl;
	cout << "耗蓝：" << _skill.getMp() << endl;
	system("pause");
	system("cls");
}
void Skill_Study_output(int _number,Skill _skill)
{
	cout << _number<<")" << _skill.getName() << "\t"; 
	if (_skill.getLevel() > 0)
	{
		cout <<"Lv:"<< _skill.getLevel();
	}
	cout << endl;
}
void Skill_Study()
{
	
	Skill_Study_output(1, zhuangji);
	cout << "1~9)选择技能 0)返回\n";
	cin >> anjian;
	system("cls");
	if (anjian == 1)
		Skill_Study_skill(zhuangji);
		

}
void Skill_Study_skill(Skill _skill)
{
	cout << anjian << ")" << _skill.getName() << endl;
	if (_skill.getLevel() > 0)
	{
		cout << "状态：已学习 Lv:" << _skill.getLevel() << endl;

		cout << "目前等级：\n";
		cout << "\t威力：" << _skill.getHurt() << endl;
		cout << "\t耗蓝：" << _skill.getMp() << endl;

		cout << "下一等级：\n";
		cout << "\t威力：" << _skill.getHurt() << endl;
		cout << "\t耗蓝：" << _skill.getMp() << endl;
	}
	else
	{
		cout << "状态：未学习 " << endl;

		cout << "下一等级：\n";
		cout << "\t威力：" << _skill.getHurt() << endl;
		cout << "\t耗蓝：" << _skill.getMp() << endl;
	}

	system("pause");
	system("cls");


}

void Save_Show()
{
	cout << "保存：" << endl;
	cout << "该功能未开启" << endl;
	system("pause");
	system("cls");
}
void Map_Show()
{
	while (1 == 1)
	{
		cout << "1)银河系 2）河外星系(未开启) 3)返回\n";
		cin >> anjian;
		system("cls");
		if (anjian == 1)									//银河系
		{
			while (1 == 1)
			{
				cout << "1)太阳系 2）其他星系 3)返回\n";
				cin >> anjian;
				system("cls");
				if (anjian == 1)							//太阳系
				{
					while (1 == 1)
					{
						cout << "1)地球 2)其他行星或恒星及陨石带等 3)返回\n";
						cin >> anjian;
						system("cls");
						if (anjian == 1)
						{
							while (1 == 1)
							{
								cout << "1)中国 2）外国 3）返回\n"; cin >> anjian;
								system("cls");
								if (anjian == 1)			//中国
								{
									while (1 == 1)
									{
										cout << "1)山东省 2)其他省份 3)返回\n";
										cin >> anjian;
										system("cls");
										if (anjian == 1)
										{
											while (1 == 1)
											{
												cout << "1)滨州市 2)其他市 3)返回\n";
												cin >> anjian;
												system("cls");
												if (anjian == 1)
												{
													while (1 == 1)
													{
														cout << "1)惠民县 2)其他县 3)返回\n";
														cin >> anjian;
														system("cls");
														if (anjian == 1)
														{
															while (1 == 1)
															{
																cout << "1)惠民县晨光实验学校 2)其他地方 3)返回\n";
																cin >> anjian;
																system("cls");
																if (anjian == 1)
																{
																	while (1 == 1)
																	{
																		a_a.get();
																		a_b.get();
																		a_c.get();
																		a_d.get();
																		a_e.get();
																		a_f.get();
																		a_g.get();
																		a_h.get();
																		a_i.get();
																		a_j.get();
																		cout << "0)\t返回\n";
																		cin >> anjian;
																		system("cls");
																		if (anjian == 1)
																		{
																			cout << "操场上什么都没有，你不费吹灰之力就占领了它\n";
																			system("pause");
																			system("cls");
																			a_a.set(1, 1);
																			a_b.set(0, 1);
																		}
																		else if (anjian == 2)
																		{
																			if (a_b.getKaiqi() == 1)
																			{
																				cout << "你已经到达了学校大门\n";
																				system("pause");
																				system("cls");
																				cout << "你发现了一个看门的\n";
																				system("pause");
																				system("cls");
																				cout << "是否迎战\n1)是 0)否\n";
																				cin >> anjian;
																				system("cls");
																				if (anjian == 1)
																				{
																					Fighting(kanmendashu);
																					if (anjian == 211)
																					{
																						a_b.set(1, 1);
																						a_c.set(0, 1);
																					}
																				}
																				else if (anjian == 0)
																				{
																					cout << "你失败了\n";
																					system("pause");
																					system("cls");
																				}
																			}
																			else 
																			{
																				cout << "该关卡未开启\n";
																				system("pause");
																				system("cls");
																			}
																		}
																		else if (anjian == 3)
																		{
																			cout << "该关卡未开启\n";
																			system("pause");
																			system("cls");
																		}
																		else if (anjian == 4)
																		{
																			cout << "该关卡未开启\n";
																			system("pause");
																			system("cls");
																		}
																		else if (anjian == 5)
																		{
																			cout << "该关卡未开启\n";
																			system("pause");
																			system("cls");
																		}
																		else if (anjian == 6)
																		{
																			cout << "该关卡未开启\n";
																			system("pause");
																			system("cls");
																		}
																		else if (anjian == 7)
																		{
																			cout << "该关卡未开启\n";
																			system("pause");
																			system("cls");
																		}
																		else if (anjian == 8)
																		{
																			cout << "该关卡未开启\n";
																			system("pause");
																			system("cls");
																		}
																		else if (anjian == 9)
																		{
																			cout << "该关卡未开启\n";
																			system("pause");
																			system("cls");
																		}
																		else if (anjian == 10)
																		{
																			cout << "该关卡未开启\n";
																			system("pause");
																			system("cls");
																		}
																		else
																		{
																			break;
																		}
																	}
																}
																else if (anjian == 2)
																{
																	cout << "该关卡未开启\n";
																	system("pause");
																	system("cls");
																}
																else
																{
																	break;
																}
															}
														}
														else if (anjian == 2)
														{
															cout << "该关卡未开启\n";
															system("pause");
															system("cls");
														}
														else
														{
															break;
														}
													}
												}
												else if (anjian == 2)
												{
													cout << "该关卡未开启\n";
													system("pause");
													system("cls");
												}
												else
												{
													break;
												}
											}
										}
										else if (anjian == 2)
										{
											cout << "该关卡未开启\n";
											system("pause");
											system("cls");
										}
										else
										{
											break;
										}
									}
								}
								else if (anjian == 2)
								{
									cout << "该关卡未开启\n";
									system("pause");
									system("cls");
								}
								else
								{
									break;
								}

							}
						}
						else if (anjian == 2)
						{
							cout << "该关卡未开启\n";
							system("pause");
							system("cls");
						}
						else
						{
							break;
						}
					}
				}
				else if (anjian == 2)
				{
					cout << "该关卡未开启\n";
					system("pause");
					system("cls");
				}
				else
				{
					break;
				}
			}
		}
		else if (anjian == 2)								//河外星系
		{
			cout << "该关卡未开启\n";
		}
		else												//返回
		{
			break;
		}
	}


}
void Exit_Show()
{
	cout << "1）正常退出 2）不正常退出" << endl;
	cin >> anjian;
	if (anjian == 2)
	{
		anjian = 0;
		cout << 0 / anjian;
	}
}
void Fighting(Boss boss)
{
	unsigned int fight_role_hp = Hp;
	unsigned int fight_boss_hp = boss.getHp();
	int fight_role_shield = 0;
	int fight_boss_shield = 0;
	cout << "状态：\n";
	for (bool i = true;; i = !i)
	{
		//输出你的生命
		cout << Name << "的生命为：\n";
		cout << " ——————————" << endl;
		if (fight_role_hp / Hp == 1)
		{
			cout << "|▉▉▉▉▉▉▉▉▉▉|";
		}
		else if (fight_role_hp * 10 / Hp >= 9)
		{
			cout << "|▉▉▉▉▉▉▉▉▉  |";
		}
		else if (fight_role_hp * 10 / Hp >= 8)
		{
			cout << "|▉▉▉▉▉▉▉▉    |";
		}
		else if (fight_role_hp * 10 / Hp >= 7)
		{
			cout << "|▉▉▉▉▉▉▉      |";
		}
		else if (fight_role_hp * 10 / Hp >= 6)
		{
			cout << "|▉▉▉▉▉▉        |";
		}
		else if (fight_role_hp * 10 / Hp >= 5)
		{
			cout << "|▉▉▉▉▉          |";
		}
		else if (fight_role_hp * 10 / Hp >= 4)
		{
			cout << "|▉▉▉▉            |";
		}
		else if (fight_role_hp * 10 / Hp >= 3)
		{
			cout << "|▉▉▉              |";
		}
		else if (fight_role_hp * 10 / Hp >= 0.2)
		{
			cout << "|▉▉                |";
		}
		else if (fight_role_hp * 10 / Hp >= 0.1)
		{
			cout << "|▉                  |";
		}
		else if (fight_role_hp / Hp <= 0)
		{
			cout << "|                    |";
		}
		cout << "\t" << fight_role_hp << "/" << Hp << endl;
		cout << " ——————————" << endl;
		cout << "\t" << "护盾：" << fight_role_shield << endl << endl;
		//输出敌人的生命
		cout << boss.getName() << "的生命为：\n";
		cout << " ——————————" << endl;
		if (fight_boss_hp / boss.getHp() == 1)
		{
			cout << "|▉▉▉▉▉▉▉▉▉▉|";
		}
		else if (fight_boss_hp * 10 / boss.getHp() >= 9)
		{
			cout << "|▉▉▉▉▉▉▉▉▉  |";
		}
		else if (fight_boss_hp * 10 / boss.getHp() >= 8)
		{
			cout << "|▉▉▉▉▉▉▉▉    |";
		}
		else if (fight_boss_hp * 10 / boss.getHp() >= 7)
		{
			cout << "|▉▉▉▉▉▉▉      |";
		}
		else if (fight_boss_hp * 10 / boss.getHp() >= 6)
		{
			cout << "|▉▉▉▉▉▉        |";
		}
		else if (fight_boss_hp * 10 / boss.getHp() >= 5)
		{
			cout << "|▉▉▉▉▉          |";
		}
		else if (fight_boss_hp * 10 / boss.getHp() >= 4)
		{
			cout << "|▉▉▉▉            |";
		}
		else if (fight_boss_hp * 10 / boss.getHp() >= 3)
		{
			cout << "|▉▉▉              |";
		}
		else if (fight_boss_hp * 10 / boss.getHp() >= 2)
		{
			cout << "|▉▉                |";
		}
		else if (fight_boss_hp * 10 / boss.getHp() >= 1)
		{
			cout << "|▉                  |";
		}
		else if (fight_boss_hp / boss.getHp() == 0)
		{
			cout << "|                    |";
		}
		cout << "\t" << fight_boss_hp << "/" << boss.getHp() << endl;
		cout << " ——————————" << endl;
		cout << "\t" << "护盾：" << fight_boss_shield << endl << endl;
		if (fight_role_hp == 0)
		{
			cout << "你失败了" << endl;
			system("pause");
			system("cls");
			break;
		}
		if (fight_boss_hp == 0)
		{
			cout << "你胜利了,获得了" << boss.getExp() << "点经验，而且还捡到了他掉落的" << boss.getMoney() << "毛钱" << endl;
			Role_LevelUp(boss.getExp());
			Money += 5;

			system("pause");
			system("cls");
			anjian = 211;
			break;
		}
		if (i == true)
		{
			cout << "请选择技能：\n";
			cout << "1)" << putonggongji.getName() << endl;
			cin >> anjian;
			if (anjian == 1)
			{
				system("cls");
				if (fight_boss_shield > 0)//当敌方有护盾时
				{
					fight_boss_hp = fight_boss_hp - (((putonggongji.getHurt() * GongJi / 100 - boss.getFangyu()) - fight_boss_shield));
					cout << "状态：你使用了" << "普通攻击" << "，对" << boss.getName() << "造成了" << putonggongji.getHurt() * GongJi / 100 - boss.getFangyu() << "点伤害，";
					cout << "由于对方拥有护盾，你实际造成了" << (putonggongji.getHurt() * GongJi / 100 - boss.getFangyu()) - fight_boss_shield << "点伤害" << endl;
					fight_boss_shield = 0;
				}
				else//当敌方无护盾时
				{
					fight_boss_hp -= putonggongji.getHurt() * GongJi / 100 - boss.getFangyu();
					cout << "状态：你使用了" << "普通攻击" << "，对" << boss.getName() << "造成了" << putonggongji.getHurt() * GongJi / 100 << "点伤害," << endl;
				}
			}
		}
		else
		{
			system("pause");
			system("cls");

			srand(time(0));
			int may = rand() % 100;
			if (may < 100 && may >= 75)
			{
				if (boss.skill1_type == 1)
				{
					fight_role_hp = fight_role_hp - (boss.skill1_hurt * boss.getGongji() / 100 - FangYu);
					cout << "状态：" << boss.getName() << "使用了" << boss.skill1_name << ",对你造成了" << boss.skill1_hurt * boss.getGongji() / 100 - FangYu << "点伤害" << endl;
				}
				if (boss.skill1_type == 2)
				{
					fight_boss_shield += boss.skill1_hurt * boss.getGongji() / 100;
					cout << "状态：" << boss.getName() << "使用了" << boss.skill1_name << ",为自己增加了" << boss.skill1_hurt * boss.getGongji() / 100 << "点护盾" << endl;
				}
				else
				{
					fight_boss_hp += boss.skill1_hurt * boss.getGongji() / 100;
					fight_boss_hp = (fight_boss_hp > boss.getHp()) ? boss.getHp() : fight_boss_hp;
					cout << "状态：" << boss.getName() << "使用了" << boss.skill1_name << ",为自己增加了" << boss.skill1_hurt * boss.getGongji() / 100 << "点生命" << endl;

				}
			}
			else if (may < 75 && may >= 50)
			{
				if (boss.skill2_type == 1)
				{
					fight_role_hp = fight_role_hp - (boss.skill2_hurt * boss.getGongji() / 100 - FangYu);
					cout << "状态：" << boss.getName() << "使用了" << boss.skill2_name << ",对你造成了" << boss.skill2_hurt * boss.getGongji() / 100 - FangYu << "点伤害" << endl;
				}
				if (boss.skill2_type == 2)
				{
					fight_boss_shield += boss.skill2_hurt * boss.getGongji() / 100;
					cout << "状态：" << boss.getName() << "使用了" << boss.skill2_name << ",为自己增加了" << boss.skill2_hurt * boss.getGongji() / 100 << "点护盾" << endl;
				}
				else
				{
					fight_boss_hp += boss.skill2_hurt * boss.getGongji() / 100;
					fight_boss_hp = (fight_boss_hp > boss.getHp()) ? boss.getHp() : fight_boss_hp;
					cout << "状态：" << boss.getName() << "使用了" << boss.skill2_name << ",为自己增加了" << boss.skill2_hurt * boss.getGongji() / 100 << "点生命" << endl;

				}
			}
			else if (may < 50 && may >= 25)
			{
				if (boss.skill3_type == 1)
				{
					fight_role_hp = fight_role_hp - (boss.skill3_hurt * boss.getGongji() / 100 - FangYu);
					cout << "状态：" << boss.getName() << "使用了" << boss.skill3_name << ",对你造成了" << boss.skill3_hurt * boss.getGongji() / 100 - FangYu << "点伤害" << endl;
				}
				if (boss.skill3_type == 2)
				{
					fight_boss_shield += boss.skill3_hurt * boss.getGongji() / 100;
					cout << "状态：" << boss.getName() << "使用了" << boss.skill3_name << ",为自己增加了" << boss.skill3_hurt * boss.getGongji() / 100 << "点护盾" << endl;
				}
				else
				{
					fight_boss_hp += boss.skill3_hurt * boss.getGongji() / 100;
					fight_boss_hp = (fight_boss_hp > boss.getHp()) ? boss.getHp() : fight_boss_hp;
					cout << "状态：" << boss.getName() << "使用了" << boss.skill3_name << ",为自己增加了" << boss.skill3_hurt * boss.getGongji() / 100 << "点生命" << endl;

				}
			}
			else if (may < 25 && may >= 0)
			{
				if (boss.skill4_type == 1)
				{
					fight_role_hp = fight_role_hp - (boss.skill4_hurt * boss.getGongji() / 100 - FangYu);
					cout << "状态：" << boss.getName() << "使用了" << boss.skill4_name << ",对你造成了" << boss.skill4_hurt * boss.getGongji() / 100 - FangYu << "点伤害" << endl;
				}
				if (boss.skill4_type == 2)
				{
					fight_boss_shield += boss.skill4_hurt * boss.getGongji() / 100;
					cout << "状态：" << boss.getName() << "使用了" << boss.skill4_name << ",为自己增加了" << boss.skill4_hurt * boss.getGongji() / 100 << "点护盾" << endl;
				}
				else
				{
					fight_boss_hp += boss.skill4_hurt * boss.getGongji() / 100;
					fight_boss_hp = (fight_boss_hp > boss.getHp()) ? boss.getHp() : fight_boss_hp;
					cout << "状态：" << boss.getName() << "使用了" << boss.skill4_name << ",为自己增加了" << boss.skill4_hurt * boss.getGongji() / 100 << "点生命" << endl;

				}
			}
		}
	}
}



