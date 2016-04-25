#include <iostream>
#include <list>
#include <string>
using namespace std;
//������ģʽ������һ�����Ժ󣬽�����ģʽ���Զ�������ķ���һ�ֱ�ʾ��
//��ͬʱ�ṩһ�����������ͻ��˿���ʹ�������������������������еľ��ӡ�
//������ģʽ����������������һ���򵥵��ķ���ʹ��ģʽ��ƽ�����Щ��䡣
//�ڽ�����ģʽ�����ᵽ��������ָ�κν����������ܹ����͵��κ���ϡ�
//�ڽ�����ģʽ����Ҫ����һ�������ķ���������ĵȼ��ṹ��
//Ҳ����һϵ�е���Ϲ���ÿһ�����������һ�����ͷ�����
//������������Ľ��͡��������ĵȼ��ṹ�еĶ�����κ�������϶���һ�����ԡ�
//
//����һ������MM�澭���������и�����MM�Ĺ��ԣ�����˵ȥ�����͵Ĳ��衢
//ȥ����Ӱ�ķ����ȵȣ���MMԼ��ʱ��ֻҪ��һ��Interpreter��
//��������Ľű�ִ�оͿ����ˡ�

class Context;

class AbstractExpression
{
public:
	virtual void interpret(Context *) = 0;
};

class TerminalExpression :public AbstractExpression
{
public:
	void interpret(Context *context)
	{
		cout << "�ն˽�����" << endl;
	}
};

class NonterminalExpression :public AbstractExpression
{
public:
	void interpret(Context *context)
	{
		cout << "���ն˽�����" << endl;
	}
};

class Context
{
public:
	string input, output;
};

int mainK()
{
	Context *context = new Context();
	list<AbstractExpression*>  lt;
	lt.push_back(new TerminalExpression());
	lt.push_back(new NonterminalExpression());
	lt.push_back(new TerminalExpression());
	lt.push_back(new TerminalExpression());

	for (list<AbstractExpression*>::iterator iter = lt.begin(); iter != lt.end(); iter++)
	{
		(*iter)->interpret(context);
	}

	cin.get();
	return 0;
}