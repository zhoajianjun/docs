#include <string>
#include <iostream>
#include <vector>
using namespace std;
//建造模式：将产品的内部表象和产品的生成过程分割开来，
//从而使一个建造过程生成具有不同的内部表象的产品对象。
//建造模式使得产品内部表象可以独立的变化，
//客户不必知道产品内部组成的细节。
//建造模式可以强制实行一种分步骤进行的建造过程。
//

//MM最爱听的就是“我爱你”这句话了，见到不同地方的MM，
//要能够用她们的方言跟她说这句话哦，我有一个多种语言翻译机，
//上面每种语言都有一个按键，见到MM我只要按对应的键，
//它就能够用相应的语言说出“我爱你”这句话了，
//国外的MM也可以轻松搞掂，这就是我的“我爱你”builder。（
//这一定比美军在伊拉克用的翻译机好卖）


//

class Person  //抽象类，预留ule接口
{
public:
	virtual void createHead() = 0;
	virtual void createHand() = 0;
	virtual void createBody() = 0;
	virtual void createFoot() = 0;
};

class ThinPerson :public Person  ///实现抽象类瘦子，
{
	void createHead()
	{
		cout << "thin head" << endl;
	}
	void createHand()
	{
		cout << "thin hand" << endl;
	}
	void createBody()
	{
		cout << "thin body" << endl;
	}
	void createFoot()
	{
		cout << "thin foot" << endl;
	}
};

class FatPerson :public Person //胖子
{
	void createHead()
	{
		cout << "fat head" << endl;
	}
	void createHand()
	{
		cout << "fat hand" << endl;
	}
	void createBody()
	{
		cout << "fat body" << endl;
	}
	void createFoot()
	{
		cout << "fat foot" << endl;
	}
};


class Director
{
private:
	Person *p;//基类的指针
public:
	Director(Person *temp) //传递对象
	{
		p = temp;//虚函数实现多态
	}
	void create()
	{
		p->createHead();
		p->createHand();
		p->createBody();
		p->createFoot();
	}
};

//客户端代码：
int mainT()
{
	Person *p = new FatPerson();

	Director *d = new Director(p);
	d->create();
	delete d;
	delete p;



	cin.get();
	return 0;
}