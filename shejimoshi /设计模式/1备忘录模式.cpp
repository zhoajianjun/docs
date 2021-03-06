#include <iostream>
#include <string>
#include <vector>
using namespace std;
//备忘录模式：备忘录对象是一个用来存储另外一个对象内部状态的快照的对象。
//备忘录模式的用意是在不破坏封装的条件下，将一个对象的状态捉住，
//并外部化，存储起来，从而可以在将来合适的时候把这个对象还原到存储起来的状态。

//同时跟几个MM聊天时，一定要记清楚刚才跟MM说了些什么话
//，不然MM发现了会不高兴的哦，幸亏我有个备忘录，
//刚才与哪个MM说了什么话我都拷贝一份放到备忘录里面保存，
//这样可以随时察看以前的记录啦。

//设计需要回放的软件，记录一下事物的状态。数据库备份，文档的编译，撤销，恢复



//设计备忘录三大步骤
//1.设计记录的节点，存储记录，//记录鼠标，键盘的状态
//2.设计记录的存储，vector,list，map,set,链表，图，数组，树
//3.操作记录的类，记录节点状态，设置节点状态，显示状态，0.1秒记录一下




//备忘录的节点，
class Memo
{
public:
	string state;
	Memo(string state) //记录当前的状态，
	{
		this->state = state;
	}
};

class Originator//类的包含备忘录的节点
{
public:
	string state;
	void setMemo(Memo *memo)
	{
		state = memo->state;
	}
	Memo *createMemo()
	{
		return new Memo(state);
	}
	void show()
	{
		cout << state << endl;
	}
};


//备忘录的集合
class Caretaker
{
public:
	vector<Memo *> memo;
	void save(Memo *memo)
	{
		(this->memo).push_back(memo);
	}
	Memo *getState(int i)
	{

		return memo[i];
	}
};

int main1()
{
	Originator *og = new Originator();
	Caretaker *ct = new Caretaker();

	og->state = "on";
	og->show();
	ct->save(og->createMemo());

	og->state = "off";
	og->show();
	ct->save(og->createMemo());

	og->state = "middle";
	og->show();
	ct->save(og->createMemo());

	og->setMemo(ct->getState(1));
	og->show();

	og->setMemo(ct->getState(2));
	og->show();
	cin.get();
	return 0;
}
