#include<iostream>
#include <vector>
#include <string>
using namespace std;
/*模板方法模式：模板方法模式准备一个抽象类，
将部分逻辑以具体方法以及具体构造子的形式实现，
然后声明一些抽象方法来迫使子类实现剩余的逻辑。
不同的子类可以以不同的方式实现这些抽象方法，
从而对剩余的逻辑有不同的实现。先制定一个顶级逻辑框架，
而将逻辑的细节留给具体的子类去实现。

女生从认识到得手的不变的步骤分为巧遇、打破僵局、展开追求、接吻、得手
但每个步骤针对不同的情况，都有不一样的做法，这就要看你随机应变啦(具体实现)*/

class AbstractClass
{
public:
	void Show()
	{
		cout << "我是" << GetName() << endl;
	}
protected:
	virtual string GetName() = 0;
};

class Naruto : public AbstractClass
{
protected:
	virtual string GetName()
	{
		return "火影史上最帅的六代目---一鸣惊人naruto";
	}
};

class OnePice : public AbstractClass
{
protected:
	virtual string GetName()
	{
		return "我是无恶不做的大海贼---路飞";
	}
};

//客户端
int mainP13()
{
	Naruto* man = new Naruto();
	man->Show();

	OnePice* man2 = new OnePice();
	man2->Show();

	cin.get();
	return 0;
}
