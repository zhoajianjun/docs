#include <iostream>
#include <cmath>
#include <string>
using namespace std;
//����ģʽ������ģʽ���һ���㷨����ÿһ���㷨��װ�����й�ͬ�ӿڵĶ��������У�


//�Ӷ�ʹ�����ǿ����໥�滻������ģʽʹ���㷨�����ڲ�Ӱ�쵽�ͻ��˵������


//�����仯������ģ����Ϊ�ͻ����ֿ��������ฺ��ά�ֺͲ�ѯ��Ϊ�࣬


//�����㷨�ھ���Ĳ��������ṩ�������㷨�ͻ��������������㷨��������
//�޸Ķ�����Ӱ�쵽�����Ϳͻ��ˡ�
//
//����ͬ���͵�MMԼ�ᣬҪ�ò�ͬ�Ĳ��ԣ��е����Ӱ�ȽϺã�
//�е���ȥ��С��Ч�������е�ȥ������������ʣ���Ŀ�Ķ���Ϊ�˵õ�MM�ķ��ģ�
//�ҵ�׷MM�������кö�StrategyŶ��


//���Եĳ����࣬�ӿڣ��������ָ����Է�������������󣬣����麯����
//ʵ�ֵĸ��ֲ��ԣ����ֲ��Ե�ʵ���࣬������̳г�����
//���Ե����ýӿ��࣬���ò�ͬ����

class CashSuper
{
public:
	virtual double acceptMoney(double money) = 0;//�����࣬��Ǯ�Ĵ��麯��
};

class CashNormal :public CashSuper
{
public:
	double acceptMoney(double money)//������Ǯ
	{
		return money;
	}
};

class CashRebate :public CashSuper //����
{
private:
	double discount;
public:
	CashRebate(double dis) //�ۿ�
	{
		discount = dis;
	}
	double acceptMoney(double money)//��Ǯ
	{
		return money*discount;//�ۿ�
	}
};


class CashReturn :public CashSuper
{
private:
	double moneyCondition;
	double moneyReturn;
public:
	CashReturn(double mc, double mr)//������Ǯ�����ض���Ǯ
	{
		moneyCondition = mc;
		moneyReturn = mr;
	}
	double acceptMoney(double money)//��Ǯ������
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
	CashContext(string str)//���ò���
	{
		if (str == "�����շ�")
		{
			cs = new CashNormal();
		}
		else if (str == "��9��")
		{
			cs = new CashRebate(0.9);
		}
		else if (str == "��1000��200")
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
	CashContext *cc = new CashContext("�����շ�");
	cout << cc->getResult(money);
	cin.get();
	return 0;
}