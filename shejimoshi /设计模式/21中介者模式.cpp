#include<iostream>
#include <string>
using namespace std;
////MEDIATOR 调停者模式
//
////调停者模式：调停者模式包装了一系列对象相互作用的方式，
//使得这些对象不必相互明显作用。从而使他们可以松散偶合。
//当某些对象之间的作用发生改变时，不会立即影响其他的一些对象之间的作用。
//保证这些作用可以彼此独立的变化。调停者模式将多对多的相互作用转化
//为一对多的相互作用。调停者模式将对象的行为和协作抽象化
//，把对象在小尺度的行为上与其他对象的相互作用分开处理。
//
////四个MM打麻将，相互之间谁应该给谁多少钱算不清楚了，
//幸亏当时我在旁边，按照各自的筹码数算钱，赚了钱的从我这里拿，
//赔了钱的也付给我，一切就OK啦，俺得到了四个MM的电话。
//
////中介者模式，找不到老婆可以相亲靠婚介

class Country;

class UniteNations
{
public:
	virtual void declare(string message, Country *colleague) = 0;
};

class Country
{
protected:
	UniteNations *mediator;
public:
	Country(UniteNations *mediator)
	{
		this->mediator = mediator;
	}
};

class USA :public Country
{
public:
	USA(UniteNations *mediator) :Country(mediator)
	{}
	void declare(string message)
	{
		cout << "美发布信息: " << message << endl;
		mediator->declare(message, this);
	}
	void getMessage(string message)
	{
		cout << "美国获得对方信息: " << message << endl;
	}
};

class Iraq :public Country
{
public:
	Iraq(UniteNations *mediator) :Country(mediator)
	{}
	void declare(string message)
	{
		cout << "伊拉克发布信息: " << message << endl;
		mediator->declare(message, this);
	}
	void getMessage(string message)
	{
		cout << "伊拉克获得对方信息: " << message << endl;
	}
};

class UnitedNationsSecurityCouncil :public UniteNations
{
public:
	USA *usa;
	Iraq *iraq;
	void declare(string message, Country *colleague)
	{
		if (colleague == usa)
		{
			iraq->getMessage(message);
		}
		else
		{
			usa->getMessage(message);
		}
	}
};

int mainWERT()
{
	UnitedNationsSecurityCouncil *unsc = new UnitedNationsSecurityCouncil();

	USA *c1 = new USA(unsc);
	Iraq *c2 = new Iraq(unsc);

	unsc->usa = c1;
	unsc->iraq = c2;

	c1->declare("不准开发核武器，否则打你！");
	c2->declare("他妈的美国去死！");

	cin.get();
	return 0;
}
