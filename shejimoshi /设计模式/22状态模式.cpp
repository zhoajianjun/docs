#include <iostream>
#include <string>
using namespace std;
//状态模式：状态模式允许一个对象在其内部状态改变的时候改变行为。
//这个对象看上去象是改变了它的类一样。状态模式把所研究的对象的行
//为包装在不同的状态对象里，每一个状态对象都属于一个抽象状态类的
//一个子类。状态模式的意图是让一个对象在其内部状态改变的时候，
//其行为也随之改变。状态模式需要对每一个系统可能取得的状态创立一个状态类的
//子类。当系统的状态变化时，系统便改变所选的子类。
//
//跟MM交往时，一定要注意她的状态哦，在不同的状态时她的行为会有不同，
//比如你约她今天晚上去看电影，对你没兴趣的MM就会说“有事情啦”
//，对你不讨厌但还没喜欢上的MM就会说“好啊，不过可以带上我同事么？”
//，已经喜欢上你的MM就会说“几点钟？看完电影再去泡吧怎么样？”，
//当然你看电影过程中表现良好的话，也可以把MM的状态从不讨厌不喜欢变成喜欢哦。

class Work;
class State;
class ForenonnState;


class State
{
public:
	virtual void writeProgram(Work*) = 0;//准柜台的基类，抽象类
};

class Work   //实施工作的类，根据状态执行不同的操作
{
public:
	int hour;
	State *current;
	Work();
	
	
	void writeProgram()
	{
		current->writeProgram(this);
	}
};

class EveningState :public State  //晚上状态
{
public:
	void writeProgram(Work *w)
	{
		cout << "当前时间: " << w->hour << "心情很好，在看《明朝那些事儿》，收获很大！" << endl;
	}
};

class AfternoonState :public State  
{
public:
	void writeProgram(Work *w)
	{
		if (w->hour < 19)
		{
			cout << "当前时间: " << w->hour << "下午午睡后，工作还是精神百倍!" << endl;
		}
		else
		{
			w->current = new EveningState();
			w->writeProgram();
		}
	}
};

class ForenonnState :public State
{
public:
	void writeProgram(Work *w)
	{
		if (w->hour < 12)
		{
			cout << "当前时间: " << w->hour << "上午工作精神百倍!" << endl;
		}
		else
		{
			w->current = new AfternoonState();
			w->writeProgram();
		}
	}
};

Work::Work()
{
	current = new ForenonnState();
}


int mainD()
{
	Work *w = new Work();
	w->hour = 21;
	w->writeProgram();
	cin.get();
	return 0;
}