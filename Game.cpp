#include <iostream>
#include <string>
using namespace std;

string Name; 
int anjian;
int HP = 100, GongJi = 20, FangYu = 20;
int Level = 1, Exp = 0; int MaxExp;
int Money = 0;

void bag();
void map();
void zhuangtai(int GongJi_, int FangYu_, int HP_,int Money_,int Level_,int Exp_); 
void LevelUp(int GongJi_, int FangYu_, int HP_, int Level_, int Exp_);
void Version(float version);
void CheckName();

class Guanqia
{
	private:
		int number;
		string name;
		bool zhanling;
		bool kaiqi; 
	public:
		void init(int _number,string _name)
		{
			name = _name;
			number = _number;
			zhanling = false;
			kaiqi = false;
		}
		void get()
		{
			cout<<number<<")\t"<<name<<"\t";
			if(kaiqi == true)
			{
				if(zhanling == true)
				{
					cout<<"已占领\n";	
				}
				else
				{
					cout<<"已开启\n";
				}
			}
			else
			{
				cout<<"未开启\n";
			}
		}
		void set(int _zhanling,int _kaiqi)
		{
			zhanling = _zhanling;
			kaiqi = _kaiqi;
		}
};
Guanqia a_a;Guanqia a_b;Guanqia a_c;Guanqia a_d;Guanqia a_e;Guanqia a_f;Guanqia a_g;Guanqia a_h;Guanqia a_i;Guanqia a_j;
int main()
{
	Version(1.08f);
	CheckName();
	zhuangtai(GongJi, FangYu, HP, Money, Level, Exp);
	a_a.init(1,"大操场  ") ;a_a.set(0,1);
	a_b.init(2,"大门    ") ;
	a_c.init(3,"男生宿舍") ;
	a_d.init(4,"实验楼  ") ;
	a_e.init(5,"办公楼  ") ;
	a_f.init(6,"艺术楼  ") ;
	a_g.init(7,"小操场  ") ;
	a_h.init(8,"教学楼  ") ;
	a_i.init(9,"食堂    ") ;
	a_j.init(10,"女生宿舍") ;
	system("pause"); 

	while (1 == 1)
	{
		cout << "请选择你要做什么：\n";
		cout << "1)背包(开发中)\n2)地图\n3)状态\n";
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
	return 0;
}




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
void Version(float version)
{
	cout << "版本：" << version << endl;
}
void bag()
{
	int zero = 0;
	cout << 0 / zero;
}
void map()
{
	while (1 == 1)
	{
		cout << "1)银河系 2）河外星系(未开启) 3)返回\n";
		cin >> anjian;
		cout << "\n\n\n\n\n\n\n\n\n\n";
		if (anjian == 1)									//银河系
		{
			while (1 == 1)
			{
				cout << "1)太阳系 2）其他星系 3)返回\n";
				cin >> anjian;
				cout << "\n\n\n\n\n\n\n\n\n\n";
				if ( anjian == 1)							//太阳系
				{
					while (1 == 1)
					{
						cout << "1)地球 2)其他行星或恒星及陨石带等 3)返回\n";
						cin >> anjian;
						cout << "\n\n\n\n\n\n\n\n\n\n";
						if (anjian == 1)
						{
							while (1 == 1)
							{
								cout << "1中国 2）外国 3）返回\n"; cin >> anjian;
								cout << "\n\n\n\n\n\n\n\n\n\n";
								if (anjian == 1)			//中国
								{
									while (1 == 1)
									{
										cout << "1)山东省 2)其他省份 3)返回\n";
										cin >> anjian;
										cout << "\n\n\n\n\n\n\n\n\n\n"; 
										if (anjian == 1)
										{
											while (1 == 1)
											{
												cout << "1)滨州市 2)其他市 3)返回\n";
												cin >> anjian;
												cout << "\n\n\n\n\n\n\n\n\n\n";
												if (anjian == 1)
												{
													while (1 == 1)
													{
														cout << "1)惠民县 2)其他县 3)返回\n";
														cin >> anjian;
														cout << "\n\n\n\n\n\n\n\n\n\n";
														if (anjian == 1)
														{
															while (1 == 1)
															{
																cout << "1)惠民县晨光实验学校 2)其他地方 3)返回\n";
																cin >> anjian;
																cout << "\n\n\n\n\n\n\n\n\n\n";
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
																		cout<<"11)\t返回\n";	
																		cin >> anjian;
																		cout << "\n\n\n\n\n\n\n\n\n\n";
																		if (anjian == 1)
																		{
																			cout<<"操场上什么都没有，你不会吹灰之力就占领了他\n";
																			a_a.set(1,1);
																			a_b.set(0,1);
																		}
																		else if (anjian == 2)
																		{
																			cout << "该关卡未开启\n";
																		}
																		else if (anjian == 3)
																		{
																			cout << "该关卡未开启\n";
																		}
																		else if (anjian == 4)
																		{
																			cout << "该关卡未开启\n";
																		}
																		else if (anjian == 5)
																		{
																			cout << "该关卡未开启\n";
																		}
																		else if (anjian == 6)
																		{
																			cout << "该关卡未开启\n";
																		}
																		else if (anjian == 7)
																		{
																			cout << "该关卡未开启\n";
																		}
																		else if (anjian == 8)
																		{
																			cout << "该关卡未开启\n";
																		}
																		else if (anjian == 9)
																		{
																			cout << "该关卡未开启\n";
																		}
																		else if (anjian == 10)
																		{
																			cout << "该关卡未开启\n";
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
						}
						else
						{
							break;
						}
					}
				}
				else if (anjian == 2)
				{
					cout << "该关卡未开启\n";					//其他星系
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
	else if (Name == "刘希涛" || Name == "希涛" || Name == "liuxitao" || Name == "LIUXITAO" || Name == "xitao" || Name == "XITAO" )
	{
		cout << "希涛，看见我物理配套来没？？？\n\n";
	}
	else if (Name == "孔龙" || Name == "恐龙" || Name == " konglong" || Name == "KONGLONG" )
	{
		cout << "这是一个彩蛋，不是恐龙蛋。。。\n\n";
	}
	else
	{
		cout << "你好，" << Name << "，欢迎进入这个逗比的游戏。" << endl << endl;
	}
}
