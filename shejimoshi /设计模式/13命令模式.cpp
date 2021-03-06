#include <iostream>
#include <string>
#include <list>
//命令模式：命令模式把一个请求或者操作封装到一个对象中。
//命令模式把发出命令的责任和执行命令的责任分割开，委派给不同的对象。
//命令模式允许请求的一方和发送的一方独立开来，
//使得请求的一方不必知道接收请求的一方的接口，
//更不必知道请求是怎么被接收，
//以及操作是否执行，何时被执行以及是怎么被执行的。
//系统支持命令的撤消。
//
//俺有一个MM家里管得特别严，没法见面，只好借助于她弟弟在我们俩之间传送信息，
//她对我有什么指示，就写一张纸条让她弟弟带给我。这不，
//她弟弟又传送过来一个COMMAND，为了感谢他，我请他吃了碗杂酱面，
//哪知道他说：“我同时给我姐姐三个男朋友送COMMAND，就数你最小气，
//才请我吃面。”
//
using namespace std;

class Barbecuer  //接收者执行命令
{
public:
	void bakeMutton()
	{
		cout << "烤羊肉串" << endl;
	}
	void bakeChickenWing()
	{
		cout << "烤鸡翅" << endl;
	}
};

class Command   //命令基类
{
protected:
	Barbecuer *receiver;//类的包含
public:
	Command(Barbecuer *receiver)//命令接受
	{
		this->receiver = receiver;
	}
	virtual void executeCommand() = 0;
};

class BakeMuttonCommand :public Command  //命令传送着
{
public:
	BakeMuttonCommand(Barbecuer *receiver) :Command(receiver)
	{}
	void executeCommand()
	{
		receiver->bakeMutton();
	}
};

class BakeChikenWingCommand :public Command  //命令传送着
{
public:
	BakeChikenWingCommand(Barbecuer *receiver) :Command(receiver)
	{}
	void executeCommand()
	{
		receiver->bakeChickenWing();
	}
};

class Waiter        //服务员
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

class Waiter2   //gei多个对象下达命令
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