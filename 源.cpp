#include <iostream>
#include <cstdlib> 
#include <string>
#include <ctime>
#include "关卡.h"
#include "技能.h"
#include "Boss.h"
using namespace std;

string Name;
int anjian;
int Hp = 50, GongJi = 10, FangYu = 0;
int Level = 1, Exp = 0; int MaxExp = 10;
int Money = 0;

Skill putonggongji ("普通攻击", 80, 1 );
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


Boss kanmendashu ( "看门大叔", 100, 10, 0 ,5);

void Role(int GongJi_, int FangYu_, int HP_, int Money_, int Level_, int Exp_); 
void Bag();
void Map();
void Save();
void About();
void Fighting(Boss boss);

void LevelUp(int _exp);
void CheckName();


int main()
{
	//开始定义Boss技能	1:攻击 2:护盾 3:加血
	kanmendashu.setSkill1("呼叫120", 50,3);
	kanmendashu.setSkill2("关门", 60,2);
	kanmendashu.setSkill3("呼叫120", 50, 3);
	kanmendashu.setSkill4("关门", 60, 2);
	//开启第一关
	a_a.set(0, 1);

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

	CheckName();
	system("pause");
	system("cls");
	cout << "你现在的状态为：\n";
	Role(GongJi, FangYu, Hp, Money, Level, Exp);
	

	while (true)
	{
		cout << "请选择你要做什么：\n";
		cout << "1)角色\n2)背包\n3)地图\n4)保存\n5)关于\n";
		cin >> anjian;
		system("cls");
		switch (anjian)
		{
		case 1:Role(GongJi, FangYu, Hp, Money, Level, Exp);  break; 
		case 2:Bag(); break;
		case 3:Map(); break;
		case 4:Save(); break;
		case 5:About(); break;
		default:cout << "输入错误\n\n";
		}
	}
	return 0;
}


void Role(int GongJi_, int FangYu_, int HP_, int Money_, int Level_, int Exp_)
{
	cout << "昵称：" << Name << "；\n\n";
	int ZhanDouLi = GongJi * 2 + FangYu * 2 + Hp;
	cout << "战斗力:" << ZhanDouLi << "；\n\n";
	cout << "生命值:" << Hp << "；\n\n";
	cout << "攻击力:" << GongJi << "；\n";
	cout << "防御力:" << FangYu << "；\n\n";
	cout << "等级:" << Level << "级；\n";
	cout << "经验值:" << Exp << "/" << MaxExp << "；\n\n";
	cout << "钢镚子:" << Money << "角；\n";
	cout << endl;
	system("pause");
	system("cls");
}
void Fighting(Boss boss)
{
	int fight_role_hp = Hp;
	int fight_boss_hp = boss.getHp();
	int fight_role_shield = 0;
	int fight_boss_shield = 0;
	cout << "状态：\n";
	for (bool i = true;; i = !i)
	{
		//将负血改为零血
		if (fight_boss_hp <= 0)
		{
			fight_boss_hp = 0;
		}
		if (fight_role_hp <= 0)
		{
			fight_role_hp = 0;
		}
		
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
			cout << "你胜利了,获得了"<<boss.getExp()<<"点经验" << endl;
			LevelUp(boss.getExp());
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
					cout << "由于对方拥有护盾，你实际造成了" << (putonggongji.getHurt() * GongJi / 100 - boss.getFangyu()) - fight_boss_shield << "点伤害"<<endl;
					fight_boss_shield = 0;
				}
				else//当敌方无护盾时
				{
					fight_boss_hp -= putonggongji.getHurt() * GongJi / 100 - boss.getFangyu();
					cout << "状态：你使用了" << "普通攻击" << "，对" << boss.getName() << "造成了" << putonggongji.getHurt() * GongJi / 100 << "点伤害,"<<endl;
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
void About()
{
	cout << "关于：" << endl;
	cout << "版本：1.13" << endl;
	system("pause");
	system("cls");
}
void Bag()
{
	while (1 == 1)
	{
		cout << "1)" << endl;
		cout << "2)" << endl;
		cout << "3)" << endl;
		cout << "4)" << endl;
		cout << "5)" << endl;
		cout << "6)" << endl;
		cout << "7)" << endl;
		cout << "8)" << endl;
		cout << "9)" << endl;
		cout << endl << "钢崩子: " << Money << " 角" << endl << endl;

		cout << "1~9）选择物品 0)返回" << endl;
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
		else if (anjian == 0)
		{
			break;
		}

	}
}
void Save()
{
	cout << "保存：" << endl;
	cout << "该功能未开启" << endl;
	system("pause");
	system("cls");
}
void Map()
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
void LevelUp(int _exp)
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

		
		cout << "恭喜你升到了"<<Level<<"级了，同时获得了10毛~"<<endl;
		Money += 10;
	}
	

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