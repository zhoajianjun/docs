#include <iostream>
#include <string>
using namespace std;


//工厂模式：客户类和工厂类分开。
//消费者任何时候需要某种产品，只需向工厂请求即可。
//消费者无须修改就可以接纳新产品。缺点是当产品修改时，
//工厂类也要做相应的修改。如：如何创建及如何向客户端提供。
//
//追MM少不了请吃饭了，麦当劳的鸡翅和肯德基的鸡翅都是MM爱吃的东西，
//虽然口味有所不同，但不管你带MM去麦当劳或肯德基，
//只管向服务员说“来四个鸡翅”就行了。麦当劳和肯德基就是生产鸡翅的Factory。


//第一，基类存放数据
//第二，派生类有很多，派生类存放数据的操作
//第三实现接口类，用静态函数实现调用各种派生类

class Operation    //基类存放数据
{
public:
	double numberA, numberB;//两个数
	virtual double  getResult()//获取结果
	{
		return 0;
	}
};

class addOperation :public Operation//派生类存放操作
{
	double getResult()
	{
		return numberA + numberB;
	}
};


class subOperation :public Operation
{
	double getResult()
	{
		return numberA - numberB;
	}
};

class mulOperation :public Operation
{
	double getResult()
	{
		return numberA*numberB;
	}
};

class divOperation :public Operation
{
	double getResult()
	{
		return numberA / numberB;
	}
};

class operFactory //实现调用改革吃哦啊做
{
public:
	static Operation *createOperation(char c)
	{
		switch (c)
		{
		case '+':
			return new addOperation;
			break;

		case '-':
			return new subOperation;
			break;

		case '*':
			return new mulOperation;
			break;

		case '/':
			return new divOperation;
			break;
		}
	}
};

int mainV()
{
	Operation *oper = operFactory::createOperation('-');
	oper->numberA = 9;
	oper->numberB = 99;
	cout << oper->getResult() << endl;

	cin.get();
	return 0;
}