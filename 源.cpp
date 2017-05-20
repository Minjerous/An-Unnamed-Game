#include <iostream>
#include <cstdlib> 
#include <string>
#include <ctime>
#include "Guanqia.h"
#include "Object_dj.h"
#include "Boss.h"

using namespace std;

int anjian; 
string Name;
int Hp = 50, Mp = 50, GongJi = 10, FangYu = 0,BaoJi=0;
int Level = 1, Exp = 0, MaxExp = 10;
int Money = 0;
//Skill 对象( _名称 = "", _伤害 = 0, _类型 = 0,_耗魔 = 0, _升级花费 = 0,_等级 = 0) :名称(_名称), 伤害(_伤害), 类型(_类型)，耗魔(_耗魔), 等级(_等级){}
//类型：1.攻击 2.护盾 3.加血
const Skill putonggongji("普通攻击", 80, 1, 0, 100, 1); 
const Skill zhuangji("撞击", 50, 1, 2, 10);
Skill skill_1(putonggongji);
Skill skill_2;
Skill skill_3;
Skill skill_4;
//Guanqia 对象( _序号,  _名称,  _是否开启 = 0,  _是否占领 = 0) :序号(_序号), 名称(_名称), 是否开启_是否开启), 是否占领(_是否占领){}
Guanqia a_a(1, "大操场  ",1); 
Guanqia a_b(2, "大门    ");
Guanqia a_c(3, "男生宿舍");
Guanqia a_d(4, "实验楼  ");
Guanqia a_e(5, "办公楼  ");
Guanqia a_f(6, "艺术楼  ");
Guanqia a_g(7, "小操场  ");
Guanqia a_h(8, "教学楼  ");
Guanqia a_i(9, "食堂    ");
Guanqia a_j(10, "女生宿舍");
//Boss 对象( 名称,  生命,  攻击,  防御,  获得经验,  掉落钢镚子,技能1名称,技能1伤害,技能1类型,技能2名称,技能2伤害,技能2类型,技能3名称,技能3伤害,技能3类型,技能4名称,技能4伤害,技能4类型,):名称(_名称), 生命(_生命), 攻击(_攻击), 防御(_防御), 获得经验(_获得经验), 掉落钢镚子(_掉落钢镚子){}
const Boss kanmendashu("看门大叔", 100, 10, 0, 5, 5, "呼叫120", 50, 3, "关门", 60, 2, "呼叫120", 50, 3, "关门", 60, 2);
//Object_dj 对象( _名称, _说明,  _售价, _ID号, _数量 = 0, _序号 = 0) :名称(_名称), 说明(_说明), 售价(_售价), 编号(_编号)，数量(_数量), 序号(_序号){}
Object_dj bag_1("", "", 0, 0, 0, 1);
Object_dj bag_2("", "", 0, 0, 0, 2);
Object_dj bag_3("", "", 0, 0, 0, 3);
Object_dj bag_4("", "", 0, 0, 0, 4);
Object_dj bag_5("", "", 0, 0, 0, 5);
Object_dj bag_6("", "", 0, 0, 0, 6);
Object_dj bag_7("", "", 0, 0, 0, 7);
Object_dj bag_8("", "", 0, 0, 0, 8);
Object_dj bag_9("", "", 0, 0, 0, 9);
const Object_dj xuantie("玄铁", "在炼丹炉内打造装备所需的材料", 2, 1);
const Object_dj sichou("丝绸", "在炼丹炉内打造装备所需的材料", 2, 2);
const Object_dj tanmu("檀木", "在炼丹炉内打造装备所需的材料", 2, 3);

void Role_Show(int GongJi_, int FangYu_, int HP_, int Money_, int Level_, int Exp_); 
void Role_CheckName();
void Role_LevelUp(int _exp);
void Bag_Show();
void Bag_Show_dj(Object_dj *dj);
void Bag_Get_dj(Object_dj *dj);
void Bag_Get_zb();
void Skill_Show();
void Skill_Showskill(Skill _skill);
void Skill_Study();
void Skill_Study_output(int _number,Skill _skill);
void Skill_Study_skill(Skill _skill);
void Map_Show();
void System_Show();
void System_Settings_Show();
void System_Save_Show();
void System_About_Show();
void System_Exit_Show();
void Fighting(Boss boss);
void FIghting_role_type1(unsigned int *boss_hp,unsigned int *boss_shield,unsigned int *role_mp,Boss boss,Skill skill);
void Fighting_role_type2(unsigned int *shield, Skill skill);
void Fighting_role_type3();
void Fighting_boss_type1();
void Fighting_boss_type2();
void Fighting_boss_type3();




int main()
{
	//初始化随机数种子
	srand(time(0));
	//初始化技能
	skill_1 = putonggongji;

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
		cout << "1)角色\n2)背包\n3)技能\n4)地图\n5)系统\n";
		cin >> anjian;
		system("cls");
		switch (anjian)
		{
		case 1:Role_Show(GongJi, FangYu, Hp, Money, Level, Exp);  break;
		case 2:Bag_Show(); break;
		case 3:Skill_Show(); break;
		case 4:Map_Show(); break;
		case 5:System_Show(); if (anjian == 1)return 0; break;
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
	cout << "暴击率:" << BaoJi << "%；\n\n";
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
		cout << "希涛，别忘了欠我三包馍馍干\n\n";
	}
	else if (Name == "孔龙" || Name == "恐龙" || Name == " konglong" || Name == "KONGLONG")
	{
		cout << "这是一个彩蛋，不是恐龙蛋。。。\n\n";
	}
	else if (Name == "齐伟" || Name == "qiwei" || Name == " QIWEI" || Name == "QiWei" || Name == "Qi Wei" || Name == "qi wei" || Name == "QI WEI")
	{
		cout << "君所欲之网已毕，址者，http://211tzbd.tk/qiwei.html 也。\n\n";
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
		bag_1.setNumber(bag_1.getNumber() + 1);
	else if (bag_2.getID() == dj->getID())
		bag_2.setNumber(bag_2.getNumber() + 1);
	else if (bag_3.getID() == dj->getID())
		bag_3.setNumber(bag_3.getNumber() + 1);
	else if (bag_4.getID() == dj->getID())
		bag_4.setNumber(bag_4.getNumber() + 1);
	else if (bag_5.getID() == dj->getID())
		bag_5.setNumber(bag_5.getNumber() + 1);
	else if (bag_6.getID() == dj->getID())
		bag_6.setNumber(bag_6.getNumber() + 1);
	else if (bag_7.getID() == dj->getID())
		bag_7.setNumber(bag_7.getNumber() + 1);
	else if (bag_8.getID() == dj->getID())
		bag_8.setNumber(bag_8.getNumber() + 1);
	else if (bag_9.getID() == dj->getID())
		bag_9.setNumber(bag_9.getNumber() + 1);
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
			Skill_Showskill(skill_1);
		else if (anjian == 2)
			Skill_Showskill(skill_2);
		else if (anjian == 3)
			Skill_Showskill(skill_3);
		else if (anjian == 4)
			Skill_Showskill(skill_4);
		else if (anjian == 5)
			Skill_Study();
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
void Skill_Showskill(Skill _skill)
{
	cout << anjian << ")" << _skill.getName() << endl;
	cout << "等级：" << _skill.getLevel() << endl;
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
		cout << "状态：已学习\n升级条件：" << _skill.getLevelupmoney() << "角\n";
	else
		cout << "状态：未学习\n学习条件：" << _skill.getLevelupmoney() << "角\n";
		cout << "目前等级：\n";
		cout << "\t等级：" << _skill.getLevel() << endl;
		cout << "\t威力：" << _skill.getHurt() << endl;
		cout << "\t耗蓝：" << _skill.getMp() << endl;

		cout << "下一等级：\n";
		cout << "\t等级：" << _skill.getLevel() +1<< endl;
		cout << "\t威力：" << _skill.getHurt() << endl;
		cout << "\t耗蓝：" << _skill.getMp() << endl;
	
	

	system("pause");
	system("cls");


}

void System_Show()
{
	while (true)
	{
		cout << "系统：\n1)游戏设置\n2)保存游戏\n3)关于游戏\n4)退出游戏\n5)返回\n";
		cin >> anjian;
		system("cls");
		if (anjian == 1)
			System_Settings_Show();
		else if (anjian == 2)
			System_Save_Show();
		else if (anjian == 3)
			System_About_Show();
		else if (anjian == 4)
		{
			System_Exit_Show();
			return;
		}
		else if (anjian == 5)
			break;
	}
}
void System_Settings_Show()
{
	while (true)
	{
		cout << "设置：\n" << "1)修改游戏颜色\n2)返回\n";
		cin >> anjian;
		system("cls");
		if (anjian == 1)
		{
			cout << "0=黑色\t\t8=灰色\n1=蓝色\t\t9=淡蓝色\n2=绿色\t\tA=淡绿色\n3=浅绿色\tB=淡浅绿色\n4=红色\t\tC=淡红色\n5=紫色\t\tD=淡紫色\n6=黄色\t\tE=淡黄色\n7=白色\t\tF=亮白色\n\n";
			char color[9] = "color ";
			cout << "你想把背景改为什么颜色（填数字或字母）\n";
			cin >> color[6];
			cout << "你想把文字改为什么颜色（填数字或字母）\n";
			cin >> color[7];
			system(color); 
			system("cls");
			cout << "设置成功！\n";
			system("pause");
			system("cls");
		}
		else if (anjian == 2)
			break;
	}
}
void System_Save_Show()
{
	cout << "保存：" << endl;
	cout << "该功能未开启" << endl;
	system("pause");
	system("cls");
}
void System_About_Show()
{
	cout << "关于：" << endl;
	cout << "版本：1.23" << endl;
	cout << "官网：http://www.211tzbd.tk" << endl;
	system("pause");
	system("cls");
}
void System_Exit_Show()
{
	cout << "退出：\n1）正常退出 2）不正常退出" << endl;
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
	unsigned int fight_role_mp = Mp;
	unsigned int fight_role_shield = 0;
	unsigned int fight_boss_hp = boss.getHp();
	unsigned int fight_boss_shield = 0;
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
		//判断胜负
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
		if (i == true)//玩家战斗
		{
			cout << "请选择技能：\n";
			cout << "1)" << skill_1.getName() << endl;
			cout << "2)" << skill_2.getName() << endl;
			cout << "3)" << skill_3.getName() << endl;
			cout << "4)" << skill_4.getName() << endl;
			cin >> anjian;
			system("cls");
			if (anjian == 1)
			{
				if (skill_1.getType() == 1)
					FIghting_role_type1(&fight_boss_hp, &fight_boss_shield, &fight_role_mp, boss, skill_1);
				else
					cout << "状态：该技能位为空，I am very happy that you wasted an opportunity." << endl;
			}
			else if (anjian == 2)
			{
				if (skill_2.getType() == 1)
					FIghting_role_type1(&fight_boss_hp, &fight_boss_shield, &fight_role_mp, boss, skill_2);
				else
					cout << "状态：该技能位为空，I am very happy that you wasted an opportunity." << endl;
			}
			else if (anjian == 3)
			{
				if (skill_3.getType() == 1)
					FIghting_role_type1(&fight_boss_hp, &fight_boss_shield, &fight_role_mp, boss, skill_3);
				else
					cout << "状态：该技能位为空，I am very happy that you wasted an opportunity." << endl;
			}
			else if (anjian == 4)
			{
				if (skill_4.getType() == 1)
					FIghting_role_type1(&fight_boss_hp, &fight_boss_shield, &fight_role_mp, boss, skill_4);
				else
					cout << "状态：该技能位为空，I am very happy that you wasted an opportunity." << endl;
			}
			else
				cout << "状态：没有该技能位，I am very happy that you wasted an opportunity." << endl;
		}
		else//Boss战斗
		{
			system("pause");
			system("cls");

			//srand(time(0));
			int may = rand() % 100;
			if (may < 100 && may >= 75)
			{
				if (boss.skill1.getType() == 1)
				{
					fight_role_hp = fight_role_hp - (boss.skill1.getHurt() * boss.getGongji() / 100 - FangYu);
					cout << "状态：" << boss.getName() << "使用了" << boss.skill1.getName() << ",对你造成了" << boss.skill1.getHurt() * boss.getGongji() / 100 - FangYu << "点伤害" << endl;
				}
				if (boss.skill1.getType() == 2)
				{
					fight_boss_shield += boss.skill1.getHurt() * boss.getGongji() / 100;
					cout << "状态：" << boss.getName() << "使用了" << boss.skill1.getName() << ",为自己增加了" << boss.skill1.getHurt() * boss.getGongji() / 100 << "点护盾" << endl;
				}
				else
				{
					fight_boss_hp += boss.skill1.getHurt() * boss.getGongji() / 100;
					fight_boss_hp = (fight_boss_hp > boss.getHp()) ? boss.getHp() : fight_boss_hp;
					cout << "状态：" << boss.getName() << "使用了" << boss.skill1.getName() << ",为自己增加了" << boss.skill1.getHurt() * boss.getGongji() / 100 << "点生命" << endl;
				}
			}
			else if (may < 75 && may >= 50)
			{
				if (boss.skill2.getType() == 1)
				{
					fight_role_hp = fight_role_hp - (boss.skill2.getHurt() * boss.getGongji() / 100 - FangYu);
					cout << "状态：" << boss.getName() << "使用了" << boss.skill2.getName() << ",对你造成了" << boss.skill2.getHurt() * boss.getGongji() / 100 - FangYu << "点伤害" << endl;
				}
				if (boss.skill2.getType() == 2)
				{
					fight_boss_shield += boss.skill2.getHurt() * boss.getGongji() / 100;
					cout << "状态：" << boss.getName() << "使用了" << boss.skill2.getName() << ",为自己增加了" << boss.skill2.getHurt() * boss.getGongji() / 100 << "点护盾" << endl;
				}
				else
				{
					fight_boss_hp += boss.skill2.getHurt() * boss.getGongji() / 100;
					fight_boss_hp = (fight_boss_hp > boss.getHp()) ? boss.getHp() : fight_boss_hp;
					cout << "状态：" << boss.getName() << "使用了" << boss.skill2.getName() << ",为自己增加了" << boss.skill2.getHurt() * boss.getGongji() / 100 << "点生命" << endl;
				}
			}
			else if (may < 50 && may >= 25)
			{
				if (boss.skill3.getType() == 1)
				{
					fight_role_hp = fight_role_hp - (boss.skill3.getHurt() * boss.getGongji() / 100 - FangYu);
					cout << "状态：" << boss.getName() << "使用了" << boss.skill3.getName() << ",对你造成了" << boss.skill3.getHurt() * boss.getGongji() / 100 - FangYu << "点伤害" << endl;
				}
				if (boss.skill3.getType() == 2)
				{
					fight_boss_shield += boss.skill3.getHurt() * boss.getGongji() / 100;
					cout << "状态：" << boss.getName() << "使用了" << boss.skill3.getName() << ",为自己增加了" << boss.skill3.getHurt() * boss.getGongji() / 100 << "点护盾" << endl;
				}
				else
				{
					fight_boss_hp += boss.skill3.getHurt() * boss.getGongji() / 100;
					fight_boss_hp = (fight_boss_hp > boss.getHp()) ? boss.getHp() : fight_boss_hp;
					cout << "状态：" << boss.getName() << "使用了" << boss.skill3.getName() << ",为自己增加了" << boss.skill3.getHurt() * boss.getGongji() / 100 << "点生命" << endl;
				}
			}
			else if (may < 25 && may >= 0)
			{
				if (boss.skill4.getType() == 1)
				{
					fight_role_hp = fight_role_hp - (boss.skill4.getHurt() * boss.getGongji() / 100 - FangYu);
					cout << "状态：" << boss.getName() << "使用了" << boss.skill4.getName() << ",对你造成了" << boss.skill4.getHurt() * boss.getGongji() / 100 - FangYu << "点伤害" << endl;
				}
				if (boss.skill4.getType() == 2)
				{
					fight_boss_shield += boss.skill4.getHurt() * boss.getGongji() / 100;
					cout << "状态：" << boss.getName() << "使用了" << boss.skill4.getName() << ",为自己增加了" << boss.skill4.getHurt() * boss.getGongji() / 100 << "点护盾" << endl;
				}
				else
				{
					fight_boss_hp += boss.skill4.getHurt() * boss.getGongji() / 100;
					fight_boss_hp = (fight_boss_hp > boss.getHp()) ? boss.getHp() : fight_boss_hp;
					cout << "状态：" << boss.getName() << "使用了" << boss.skill4.getName() << ",为自己增加了" << boss.skill4.getHurt() * boss.getGongji() / 100 << "点生命" << endl;
				}
			}
		}
	}
}
void FIghting_role_type1(unsigned int *hp, unsigned int *shield, unsigned int *role_mp,Boss boss,Skill skill)
{
	if (*role_mp>skill.getMp())
	{
		if (*shield > 0)//当敌方有护盾时
		{
			if (rand() % 100 < BaoJi)//如果暴击
			{
				if ((skill.getHurt() * GongJi / 50 - boss.getFangyu() < *shield))//如果伤害小于护盾
				{
					*shield -= skill.getHurt() * GongJi / 50 - boss.getFangyu();
					cout << "状态：你使用了" << "普通攻击" << "触发了暴击，对" << boss.getName() << "造成了" << skill.getHurt() * GongJi / 50 - boss.getFangyu() << "点伤害，";
					cout << "由于对方拥有护盾，你实际造成了0点伤害" << endl;
				}
				else//如果伤害大于护盾
				{
					*hp -= (skill.getHurt() * GongJi / 50 - boss.getFangyu() - *shield) > *hp ? *hp : (skill.getHurt() * GongJi / 50 - boss.getFangyu() - *shield);
					cout << "状态：你使用了" << "普通攻击" << "，触发了暴击，对" << boss.getName() << "造成了" << skill.getHurt() * GongJi / 50 - boss.getFangyu() << "点伤害，";
					cout << "由于对方拥有护盾，你实际造成了" << (skill.getHurt() * GongJi / 50 - boss.getFangyu()) - *shield << "点伤害" << endl;
					*shield = 0;
				}
			}
			else//如果没暴击
			{
				if ((skill.getHurt() * GongJi / 100 - boss.getFangyu() < *shield))//如果伤害小于护盾
				{
					*shield -= skill.getHurt() * GongJi / 100 - boss.getFangyu();
					cout << "状态：你使用了" << "普通攻击" << "，对" << boss.getName() << "造成了" << skill.getHurt() * GongJi / 100 - boss.getFangyu() << "点伤害，";
					cout << "由于对方拥有护盾，你实际造成了0点伤害" << endl;
				}
				else//如果伤害大于护盾
				{
					*hp -= (skill.getHurt() * GongJi / 100 - boss.getFangyu() - *shield) > *hp ? *hp : (skill.getHurt() * GongJi / 100 - boss.getFangyu() - *shield);
					cout << "状态：你使用了" << "普通攻击" << "，对" << boss.getName() << "造成了" << skill.getHurt() * GongJi / 100 - boss.getFangyu() << "点伤害，";
					cout << "由于对方拥有护盾，你实际造成了" << (skill.getHurt() * GongJi / 100 - boss.getFangyu()) - *shield << "点伤害" << endl;
					*shield = 0;
				}
			}
		}
		else//当敌方无护盾时
		{
			if (rand() % 100 < BaoJi)//如果暴击
			{
				*hp -= (skill.getHurt() * GongJi / 50 - boss.getFangyu()) > *hp ? *hp : (skill.getHurt() * GongJi / 50 - boss.getFangyu());
				cout << "状态：你使用了" << "普通攻击" << "，触发了暴击，对" << boss.getName() << "造成了" << skill.getHurt() * GongJi / 50 << "点伤害," << endl;
			}
			else//如果没暴击
			{
				*hp -= (skill.getHurt() * GongJi / 100 - boss.getFangyu()) > *hp ? *hp : (skill.getHurt() * GongJi / 100 - boss.getFangyu());
				cout << "状态：你使用了" << "普通攻击" << "，对" << boss.getName() << "造成了" << skill.getHurt() * GongJi / 100 - boss.getFangyu() << "点伤害," << endl;
			}
		}
	}
	else
		cout << "你的MP不足以释放此技能";
}
void Fighting_role_type2(unsigned int *shield, Skill skill)
{
	*shield += skill.getHurt() * GongJi / 100;
}
void Fighting_role_type3()
{
}
void Fighting_boss_type1()
{
}
void Fighting_boss_type2()
{
}
void Fighting_boss_type3()
{
}
