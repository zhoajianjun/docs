#include <string>
#include <iostream>
#include <vector>
using namespace std;
//����ģʽ������Ʒ���ڲ�����Ͳ�Ʒ�����ɹ��̷ָ����
//�Ӷ�ʹһ������������ɾ��в�ͬ���ڲ�����Ĳ�Ʒ����
//����ģʽʹ�ò�Ʒ�ڲ�������Զ����ı仯��
//�ͻ�����֪����Ʒ�ڲ���ɵ�ϸ�ڡ�
//����ģʽ����ǿ��ʵ��һ�ֲַ�����еĽ�����̡�
//

//MM����ľ��ǡ��Ұ��㡱��仰�ˣ�������ͬ�ط���MM��
//Ҫ�ܹ������ǵķ��Ը���˵��仰Ŷ������һ���������Է������
//����ÿ�����Զ���һ������������MM��ֻҪ����Ӧ�ļ���
//�����ܹ�����Ӧ������˵�����Ұ��㡱��仰�ˣ�
//�����MMҲ�������ɸ�࣬������ҵġ��Ұ��㡱builder����
//��һ�����������������õķ����������


//

class Person  //�����࣬Ԥ��ule�ӿ�
{
public:
	virtual void createHead() = 0;
	virtual void createHand() = 0;
	virtual void createBody() = 0;
	virtual void createFoot() = 0;
};

class ThinPerson :public Person  ///ʵ�ֳ��������ӣ�
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

class FatPerson :public Person //����
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
	Person *p;//�����ָ��
public:
	Director(Person *temp) //���ݶ���
	{
		p = temp;//�麯��ʵ�ֶ�̬
	}
	void create()
	{
		p->createHead();
		p->createHand();
		p->createBody();
		p->createFoot();
	}
};

//�ͻ��˴��룺
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