#include <iostream>
#include <string>
using namespace std;


//工厂方法模式：核心工厂类不再负责所有产品的创建，
//而是将具体创建的工作交给子类去做，成为一个抽象工厂角色
//，仅负责给出具体工厂类必须实现的接口，
//而不接触哪一个产品类应当被实例化这种细节。
//


//请MM去麦当劳吃汉堡，不同的MM有不同的口味，
//要每个都记住是一件烦人的事情，我一般采用Factory Method模式，
//带着MM到服务员那儿，说“要一个汉堡”，具体要什么样的汉堡呢，
//让MM直接跟服务员说就行了。



class Operation
{
public:
	double numberA, numberB;
	virtual double  getResult()//
	{
		return 0;
	}
};

class addOperation :public Operation
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

class IFactory
{
public:
	virtual Operation *createOperation() = 0;
};


class AddFactory :public IFactory
{
public:
	static Operation *createOperation()
	{
		return new addOperation();
	}
};


class SubFactory :public IFactory
{
public:
	static Operation *createOperation()
	{
		return new subOperation();
	}
};

class MulFactory :public IFactory
{
public:
	static Operation *createOperation()
	{
		return new mulOperation();
	}
};

class DivFactory :public IFactory
{
public:
	static Operation *createOperation()
	{
		return new divOperation();
	}
};

int mainw()
{
	Operation *oper = MulFactory::createOperation();
	oper->numberA = 9;
	oper->numberB = 99;
	cout << oper->getResult() << endl;
	cin.get();
	return 0;
}