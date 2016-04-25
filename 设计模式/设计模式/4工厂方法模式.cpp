#include <iostream>
#include <string>
using namespace std;


//��������ģʽ�����Ĺ����಻�ٸ������в�Ʒ�Ĵ�����
//���ǽ����崴���Ĺ�����������ȥ������Ϊһ�����󹤳���ɫ
//��������������幤�������ʵ�ֵĽӿڣ�
//�����Ӵ���һ����Ʒ��Ӧ����ʵ��������ϸ�ڡ�
//


//��MMȥ���ͳԺ�������ͬ��MM�в�ͬ�Ŀ�ζ��
//Ҫÿ������ס��һ�����˵����飬��һ�����Factory Methodģʽ��
//����MM������Ա�Ƕ���˵��Ҫһ��������������Ҫʲô���ĺ����أ�
//��MMֱ�Ӹ�����Ա˵�����ˡ�



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