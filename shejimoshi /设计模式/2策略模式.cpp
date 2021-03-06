#include <iostream>
#include <cmath>
#include <string>
using namespace std;
//策略模式：策略模式针对一组算法，将每一个算法封装到具有共同接口的独立的类中，


//从而使得它们可以相互替换。策略模式使得算法可以在不影响到客户端的情况下


//发生变化。策略模把行为和环境分开。环境类负责维持和查询行为类，


//各种算法在具体的策略类中提供。由于算法和环境独立开来，算法的增减，
//修改都不会影响到环境和客户端。
//
//跟不同类型的MM约会，要用不同的策略，有的请电影比较好，
//有的则去吃小吃效果不错，有的去海边浪漫最合适，单目的都是为了得到MM的芳心，
//我的追MM锦囊中有好多Strategy哦。


//策略的抽象类，接口，抽象类的指针可以访问所有子类对象，（纯虚函数）
//实现的各种策略，各种策略的实现类，都必须继承抽象类
//策略的设置接口类，设置不同策略

class CashSuper
{
public:
	virtual double acceptMoney(double money) = 0;//抽象类，收钱的纯虚函数
};

class CashNormal :public CashSuper
{
public:
	double acceptMoney(double money)//正常收钱
	{
		return money;
	}
};

class CashRebate :public CashSuper //打折
{
private:
	double discount;
public:
	CashRebate(double dis) //折扣
	{
		discount = dis;
	}
	double acceptMoney(double money)//收钱
	{
		return money*discount;//折扣
	}
};


class CashReturn :public CashSuper
{
private:
	double moneyCondition;
	double moneyReturn;
public:
	CashReturn(double mc, double mr)//花多少钱，返回多少钱
	{
		moneyCondition = mc;
		moneyReturn = mr;
	}
	double acceptMoney(double money)//收钱，返款
	{
		double result = money;
		if (money >= moneyCondition)
		{
			result = money - floor(money / moneyCondition)*moneyReturn;
		}
		return result;
	}
};

class  CashContext
{
private:
	CashSuper *cs;
public:
	CashContext(string str)//设置策略
	{
		if (str == "正常收费")
		{
			cs = new CashNormal();
		}
		else if (str == "打9折")
		{
			cs = new CashRebate(0.9);
		}
		else if (str == "满1000送200")
		{
			cs = new CashReturn(1000, 200);
		}
	}
	double getResult(double money)
	{
		return cs->acceptMoney(money);
	}
};


int main123 ()
{
	double money = 1000;
	CashContext *cc = new CashContext("正常收费");
	cout << cc->getResult(money);
	cin.get();
	return 0;
}