#include<iostream>
#include <string>
using namespace std;

//责任链模式：在责任链模式中，很多对象由每一个对象对其下家的引用而接起来形成
//一条链。请求在这个链上传递，直到链上的某一个对象决定处理此请求。
//客户并不知道链上的哪一个对象最终处理这个请求，系统可以在不影响客户端的
//情况下动态的重新组织链和分配责任。处理者有两个选择：承担责任或者把责任
//推给下家。一个请求可以最终不被任何接收端对象所接受。
//
//晚上去上英语课，为了好开溜坐到了最后一排，哇，前面坐了好几个漂亮的MM哎，
//找张纸条，写上“Hi, 可以做我的女朋友吗？如果不愿意请向前传”，
//纸条就一个接一个的传上去了，糟糕，传到第一排的MM把纸条传给老师了，
//听说是个老处女呀，快跑!

class Request  //请求
{
public:
	string requestType;
	string requestContent;
	int number;
};

class Manager  ///管理者
{
protected:
	string name;
	Manager *superior;
public:
	Manager(string name)
	{
		this->name = name;
	}
	void setSuperior(Manager *superior)
	{
		this->superior = superior;
	}
	virtual void requestApplications(Request *request) = 0;
};

class CommonManager :public Manager  //经理
{
public:
	CommonManager(string name) :Manager(name)
	{}
	void requestApplications(Request *request)
	{
		if (request->requestType == "请假" && request->number <= 2)
		{
			cout << name << " " << request->requestContent << " 数量: " << request->number << "被批准" << endl;
		}
		else
		{
			if (superior != NULL)
			{
				superior->requestApplications(request);
			}
		}
	}
};

class Majordomo :public Manager  //总监
{
public:
	Majordomo(string name) :Manager(name)
	{}
	void requestApplications(Request *request)
	{
		if (request->requestType == "请假" && request->number <= 5)
		{
			cout << name << " " << request->requestContent << " 数量: " << request->number << "被批准" << endl;
		}
		else
		{
			if (superior != NULL)
			{
				superior->requestApplications(request);
			}
		}
	}
};


class GeneralManager :public Manager //总经理
{
public:
	GeneralManager(string name) :Manager(name)
	{}
	void requestApplications(Request *request)
	{
		if (request->requestType == "请假")
		{
			cout << name << " " << request->requestContent << " 数量: " << request->number << "被批准" << endl;
		}
	}
};


int main123213123213()
{
	CommonManager *jinli = new CommonManager("经理");
	Majordomo *zongjian = new Majordomo("总监");
	GeneralManager *zhongjingli = new GeneralManager("总经理");

	jinli->setSuperior(zongjian);
	zongjian->setSuperior(zhongjingli);

	Request *request = new Request();

	request->requestType = "请假";
	request->requestContent = "李俊宏请假";
	request->number = 1;
	jinli->requestApplications(request);


	request->requestType = "请假";
	request->requestContent = "李俊宏请假";
	request->number = 4;
	jinli->requestApplications(request);


	request->requestType = "请假";
	request->requestContent = "李俊宏请假";
	request->number = 10;
	jinli->requestApplications(request);

	cin.get();
	return 0;
}