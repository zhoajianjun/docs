#include <iostream>
#include <string>
using namespace std;
//单例模式：单例模式确保某一个类只有一个实例，
//而且自行实例化并向整个系统提供这个实例单例模式
//。单例模式只应在有真正的“单一实例”的需求时才可使用。
//
//俺有6个漂亮的老婆，她们的老公都是我，
//我就是我们家里的老公Sigleton，她们只要说道“老公”，
//都是指的同一个人，那就是我(刚才做了个梦啦，哪有这么好的事)。

//#define  public private 

class 
{
public:
protected:
private:
}a1;

class Singleton
{
private:
	int i;
	static Singleton *instance;
	Singleton(int i)
	{
		this->i = i;
	}
public:
	static Singleton *getInstance()
	{
		return instance;
	}
	void show()
	{
		cout << i << endl;
	}
};
Singleton* Singleton::instance = new Singleton(8899);

class A :public Singleton
{

};

int mainJ()
{
	Singleton *s = Singleton::getInstance();
	Singleton *s2 = A::getInstance();
	cout << (s == s2) << endl;
	cin.get();
	return 0;
}