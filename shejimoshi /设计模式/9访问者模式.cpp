#include <iostream>
#include <list>
#include <string>
using namespace std;
//������ģʽ��������ģʽ��Ŀ���Ƿ�װһЩʩ����ĳ�����ݽṹԪ��֮�ϵĲ�����
//һ����Щ������Ҫ�޸ĵĻ�������������������ݽṹ���Ա��ֲ��䡣
//������ģʽ���������ݽṹ���δ����ϵͳ��
//�������ݽṹ�������ڽṹ�ϵĲ���֮�����Ͻ��ѿ���
//ʹ�ò������Ͽ���������ɵ��ݻ���������ģʽʹ�������µĲ�����ĺ����ף�
//��������һ���µķ������ࡣ
//������ģʽ���йص���Ϊ���е�һ�������߶����У�
//�����Ƿ�ɢ��һ�����Ľڵ����С���ʹ�÷�����ģʽʱ��
//Ҫ�������ܶ�Ķ�������߼����ڷ��������У������Ƿŵ����������С�
//������ģʽ���Կ��������ĵȼ��ṹ�������ڲ�ͬ�ĵȼ��ṹ�ĳ�Ա�ࡣ
//


//���˽ڵ��ˣ�Ҫ��ÿ��MM��һ���ʻ���һ�ſ�Ƭ��
//����ÿ��MM�͵Ļ���Ҫ��������˵��ص㣬ÿ�ſ�ƬҲҪ���ݸ��˵��ص�������
//��һ�����ĸ������������һ����ϰ����Ʒ���ϰ���һ��Visitor��
//�û����ϰ����MM���ص�ѡһ����������Ʒ���ϰ�Ҳ����ÿ�����ص�ѡһ�ſ���
//���������ɶ��ˡ�


//������ģʽ����Ҫ�ı���࣬�������麯����


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
		if (action == "�ɹ�")
		{
			cout << "���˳ɹ�ʱ����������һ��ΰ���Ů�ˡ�" << endl;
		}
		else if (action == "����")
		{
			cout << "��������ʱ�����²���װ����" << endl;
		}
	}
};

class Woman :public Person
{
public:

	void getConclusion()
	{
		if (action == "�ɹ�")
		{
			cout << "Ů�˳ɹ�ʱ����������ʧ�ܵ����ˡ�" << endl;
		}
		else if (action == "����")
		{
			cout << "Ů������ʱ�������¶�Ҳװ������" << endl;
		}
	}
};

int main132123()
{
	list<Person*> persons;

	Person *man1 = new Man();
	man1->action = "�ɹ�";
	persons.push_back(man1);

	Person *woman1 = new Woman();
	woman1->action = "�ɹ�";
	persons.push_back(woman1);

	Person *man2 = new Man();
	man2->action = "����";
	persons.push_back(man2);

	Person *woman2 = new Woman();
	woman2->action = "����";
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

