#include <iostream>
#include <string>
using namespace std;
//������ģʽ��������ģʽ����˳�����һ���ۼ��е�Ԫ�ض����ر�¶�ۼ����ڲ�����
//����������һ���γɵ������֮Ϊ�ۼ����ۼ��������ܹ�����һ��������������


//������ģʽ�������߼���װ��һ���������Ӷ����У��Ӷ���ۼ����������
//������ģʽ���˾ۼ��Ľ��档
//ÿһ���ۼ����󶼿�����һ����һ�����ϵĵ����Ӷ���
//ÿһ�������ӵĵ���״̬�����Ǳ˴˶����ġ�
//�����㷨���Զ����ھۼ���ɫ�仯��
//
//�Ұ�����Mary������һ�е�������顣Mary��
//����Ҫ�Ҹ����飬�ô�Ӧ�ҵ������� �ң���ʲô�����Ҷ���Ӧ����˵�ɡ�
//Mary�����ҿ������Ǹ�һ��������ʯ�� �ң����������򣬻����𣿡�
//Mary�����ҿ����˺��ߵ��Ƕ������� �ң����������򣬻����𣿡�
//Mary�����ҿ��������������ܳ��� ���Դ��˵�һ�������������ϣ�һҧ����
//���������򣬻����𣿡� ����


class Iterator;

class Aggregate
{
public:
	virtual Iterator *createIterator() = 0;
};

class Iterator
{
public:
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone() = 0;
	virtual bool isDoneA() = 0;
	//virtual bool isDoneA() = 0;
};

class ConcreteAggregate :public Iterator
{
public:
	void first()
	{
	
	}
	void next()
	{
	}
	bool isDone()
	{
	
	}	
	virtual bool isDoneA()
	{

	}
};


int main12323I()
{

	cin.get();
	return 0;
}