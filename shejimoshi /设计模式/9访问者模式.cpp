#include <iostream>
#include <list>
#include <string>
using namespace std;
//访问者模式：访问者模式的目的是封装一些施加于某种数据结构元素之上的操作。
//一旦这些操作需要修改的话，接受这个操作的数据结构可以保持不变。
//访问者模式适用于数据结构相对未定的系统，
//它把数据结构和作用于结构上的操作之间的耦合解脱开，
//使得操作集合可以相对自由的演化。访问者模式使得增加新的操作变的很容易，
//就是增加一个新的访问者类。
//访问者模式将有关的行为集中到一个访问者对象中，
//而不是分散到一个个的节点类中。当使用访问者模式时，
//要将尽可能多的对象浏览逻辑放在访问者类中，而不是放到它的子类中。
//访问者模式可以跨过几个类的等级结构访问属于不同的等级结构的成员类。
//


//情人节到了，要给每个MM送一束鲜花和一张卡片，
//可是每个MM送的花都要针对她个人的特点，每张卡片也要根据个人的特点来挑，
//我一个人哪搞得清楚，还是找花店老板和礼品店老板做一下Visitor，
//让花店老板根据MM的特点选一束花，让礼品店老板也根据每个人特点选一张卡，
//这样就轻松多了。


//访问者模式不需要改变基类，不依赖虚函数，


class Person
{
public:
	char * action;
	virtual void getConclusion()
	{

	};
};


class Man :public Person
{
public:

	void getConclusion()
	{
		if (action == "成功")
		{
			cout << "男人成功时，背后多半有一个伟大的女人。" << endl;
		}
		else if (action == "恋爱")
		{
			cout << "男人恋爱时，凡事不懂装懂。" << endl;
		}
	}
};

class Woman :public Person
{
public:

	void getConclusion()
	{
		if (action == "成功")
		{
			cout << "女人成功时，背后多半有失败的男人。" << endl;
		}
		else if (action == "恋爱")
		{
			cout << "女人恋爱时，遇到事懂也装不懂。" << endl;
		}
	}
};

int main132123()
{
	list<Person*> persons;

	Person *man1 = new Man();
	man1->action = "成功";
	persons.push_back(man1);

	Person *woman1 = new Woman();
	woman1->action = "成功";
	persons.push_back(woman1);

	Person *man2 = new Man();
	man2->action = "恋爱";
	persons.push_back(man2);

	Person *woman2 = new Woman();
	woman2->action = "恋爱";
	persons.push_back(woman2);

	list<Person*>::iterator iter = persons.begin();
	while (iter != persons.end())
	{
		(*iter)->getConclusion();
		++iter;
	}

	cin.get();
	return 0;
}

