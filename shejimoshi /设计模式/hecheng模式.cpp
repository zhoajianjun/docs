#include <iostream>
#include <vector>
#include <string>
using namespace std;
//合成模式：合成模式将对象组织到树结构中，可以用来描述整体与部分的关系。
//合成模式就是一个处理对象的树结构的模式。合成模式把部分与整体的关系用树结构表示出来。
//合成模式使得客户端把一个个单独的成分对象和由他们复合而成的合成对象同等看待。
//
//Mary今天过生日。“我过生日，你要送我一件礼物。”
//嗯，好吧，去商店，你自己挑。”
//“这件T恤挺漂亮，买，这条裙子好看，买，这个包也不错，买
//。”“喂，买了三件了呀，我只答应送一件礼物的哦。
//”“什么呀，T恤加裙子加包包，正好配成一套呀，小姐，麻烦你包起来。
//”“……”，MM都会用Composite模式了，你会了没有？

class Component
{
public:
	string name;
	Component(string name)
	{
		this->name = name;
	}
	virtual void add(Component *) = 0;
	virtual void remove(Component *) = 0;
	virtual void display(int) = 0;
};

class Leaf :public Component
{
public:
	Leaf(string name) :Component(name)
	{}
	void add(Component *c)
	{
		cout << "leaf cannot add" << endl;
	}
	void remove(Component *c)
	{
		cout << "leaf cannot remove" << endl;
	}
	void display(int depth)
	{
		string str(depth, '-');
		str += name;
		cout << str << endl;
	}
};

class Composite :public Component
{
private:
	vector<Component*> component;
public:
	Composite(string name) :Component(name)
	{}
	void add(Component *c)
	{
		component.push_back(c);
	}
	void remove(Component *c)
	{
		vector<Component*>::iterator iter = component.begin();
		while (iter != component.end())
		{
			if (*iter == c)
			{
				component.erase(iter);
			}
			iter++;
		}
	}
	void display(int depth)
	{
		string str(depth, '-');
		str += name;
		cout << str << endl;

		vector<Component*>::iterator iter = component.begin();
		while (iter != component.end())
		{
			(*iter)->display(depth + 2);
			iter++;
		}
	}
};


int main()
{
	Component *p = new Composite("小李");
	p->add(new Leaf("小王"));
	p->add(new Leaf("小强"));

	Component *sub = new Composite("小虎");
	sub->add(new Leaf("小王"));
	sub->add(new Leaf("小明"));
	sub->add(new Leaf("小柳"));

	p->add(sub);
	p->display(0);

	cout << "*******" << endl;
	sub->display(2);

	cin.get();

	return 0;
}