#include <iostream>
#include <string>
#include <list>
using namespace std;

//�۲���ģʽ���۲���ģʽ������һ��һ�Ӷ��������ϵ��
//�ö���۲��߶���ͬʱ����ĳһ���������
//������������״̬�Ϸ����仯ʱ����֪ͨ���й۲��߶���
//ʹ�����ܹ��Զ������Լ���
//
//��֪�����ǹ�˾����MM�鱨�𣿼��빫˾��MM�鱨�ʼ�������ˣ�
//tom�����Ѽ��鱨�������ֵ����鱨����һ��һ��֪ͨ���ǣ�
//ֱ�ӷ������ʼ��飬������Ϊ�����ߣ��۲��ߣ��Ϳ��Լ�ʱ�յ��鱨����

// ���ӣ��۲��ߣ�����һ�����࣬������ʵ�ֲ�ͬ��Ч��
//�����ߵ��࣬�������еĹ۲��ߣ����ӻ���ɾ����������Ϣ���ù۲��ߴ���
//�۲��ߵ�����Ҫ������Ϣ������


class Subject; //����ʹ��subject

class Observer
{
protected:
	string name;
	Subject *sub;
public:
	Observer(string name, Subject *sub)//�۲��ߵ����֣� ������֪ͨ����
	{
		this->name = name;//��������
		this->sub = sub;//����˭��֪ͨ��
	}
	virtual void update() = 0;//���麯��
};

class StockObserver :public Observer //�̳У��Լ�ʵ��ˢ�º���
{
public:
	StockObserver(string name, Subject *sub) :Observer(name, sub)
	{
	}
	void update();
};

class NBAObserver :public Observer
{
public:
	NBAObserver(string name, Subject *sub) :Observer(name, sub)
	{
	}
	void update();
};

class Subject  //
{
protected:
	list<Observer*> observers;///�洢�۲��ߵ�ָ�룬����
public:
	string action;
	virtual void attach(Observer*) = 0;
	virtual void detach(Observer*) = 0;
	virtual void notify() = 0;//ʵ�ּ����Ļ���
};




class Secretary :public Subject   
{
	void attach(Observer *observer)  //����֪ͨ���б�
	{
		observers.push_back(observer);
	}
	void detach(Observer *observer)//ɾ��
	{
		list<Observer *>::iterator iter = observers.begin();
		while (iter != observers.end())
		{
			if ((*iter) == observer)
			{
				observers.erase(iter);
			}
			++iter;
		}
	}
	void notify()  ///֪ͨ����
	{
		list<Observer *>::iterator iter = observers.begin();
		while (iter != observers.end())
		{
			(*iter)->update();
			++iter;
		}
	}
};

void StockObserver::update()
{
	cout << name << " �յ���Ϣ��" << sub->action << endl;
	if (sub->action == "����������!")
	{
		cout << "�����Ϲرչ�Ʊ��װ�������湤�������ӣ�" << endl;
	}
	if (sub->action == "ȥ�Ⱦƣ�")
	{
		cout << "��������" << endl;
	}
}

void NBAObserver::update()
{
	cout << name << " �յ���Ϣ��" << sub->action << endl;
	if (sub->action == "����������!")
	{
		cout << "�����Ϲر�NBA��װ�������湤�������ӣ�" << endl;
	}

   if (sub->action == "ȥ�Ⱦƣ�")
   {
	cout << "��������" << endl;
    }
}

int main123123()
{
	Subject *dwq = new Secretary();//��Ϣ���ӣ�����

	Observer *xs = new NBAObserver("xiaoshuai", dwq);//������Ϣ
	Observer *zy = new NBAObserver("zouyue", dwq);
	Observer *lm = new StockObserver("limin", dwq);

	dwq->attach(xs);
	dwq->attach(zy);
	dwq->attach(lm);//���ӵ�����

	dwq->action = "ȥ�Է��ˣ�";
	dwq->notify();
	dwq->action = "ȥ�Ⱦƣ�";
	dwq->notify();
	cout << endl;
	dwq->action = "����������!";
	dwq->notify();
	cin.get();
	return 0;
}