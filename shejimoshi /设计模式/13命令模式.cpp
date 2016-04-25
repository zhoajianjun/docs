#include <iostream>
#include <string>
#include <list>
//����ģʽ������ģʽ��һ��������߲�����װ��һ�������С�
//����ģʽ�ѷ�����������κ�ִ����������ηָ��ί�ɸ���ͬ�Ķ���
//����ģʽ���������һ���ͷ��͵�һ������������
//ʹ�������һ������֪�����������һ���Ľӿڣ�
//������֪����������ô�����գ�
//�Լ������Ƿ�ִ�У���ʱ��ִ���Լ�����ô��ִ�еġ�
//ϵͳ֧������ĳ�����
//
//����һ��MM����ܵ��ر��ϣ�û�����棬ֻ�ý��������ܵ���������֮�䴫����Ϣ��
//��������ʲôָʾ����дһ��ֽ�������ܴܵ����ҡ��ⲻ��
//���ܵ��ִ��͹���һ��COMMAND��Ϊ�˸�л�����������������ӽ��棬
//��֪����˵������ͬʱ���ҽ��������������COMMAND����������С����
//�����ҳ��档��
//
using namespace std;

class Barbecuer  //������ִ������
{
public:
	void bakeMutton()
	{
		cout << "�����⴮" << endl;
	}
	void bakeChickenWing()
	{
		cout << "������" << endl;
	}
};

class Command   //�������
{
protected:
	Barbecuer *receiver;//��İ���
public:
	Command(Barbecuer *receiver)//�������
	{
		this->receiver = receiver;
	}
	virtual void executeCommand() = 0;
};

class BakeMuttonCommand :public Command  //�������
{
public:
	BakeMuttonCommand(Barbecuer *receiver) :Command(receiver)
	{}
	void executeCommand()
	{
		receiver->bakeMutton();
	}
};

class BakeChikenWingCommand :public Command  //�������
{
public:
	BakeChikenWingCommand(Barbecuer *receiver) :Command(receiver)
	{}
	void executeCommand()
	{
		receiver->bakeChickenWing();
	}
};

class Waiter        //����Ա
{
private:
	Command *command;
public:
	void setOrder(Command *command)
	{
		this->command = command;
	}
	void notify()
	{
		command->executeCommand();
	}
};

class Waiter2   //gei��������´�����
{
private:
	list<Command*> orders;
public:
	void setOrder(Command *command)
	{
		orders.push_back(command);
	}
	void cancelOrder(Command *command)
	{}
	void notify()
	{
		list<Command*>::iterator iter = orders.begin();
		while (iter != orders.end())
		{
			(*iter)->executeCommand();
			iter++;
		}
	}
};


int main1232131231()
{

	Barbecuer *boy = new Barbecuer();
	Command *bm1 = new BakeMuttonCommand(boy);
	Command *bm2 = new BakeMuttonCommand(boy);
	Command *bc1 = new BakeChikenWingCommand(boy);

	Waiter2 *girl = new Waiter2();

	girl->setOrder(bm1);
	girl->setOrder(bm2);
	girl->setOrder(bc1);

	girl->notify();


	cin.get();

	return 0;
}