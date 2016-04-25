#include <iostream>
#include <string>
using namespace std;
//����ģʽ������ģʽ��ĳһ�������ṩһ���������
//���ɴ��������ƶ�Դ��������á�
//�������һ���˻�һ������������һ���˻���һ��������ȡ�ж���
//ĳЩ����£��ͻ�������߲��ܹ�ֱ������һ������
//�����������ڿͻ���Ŀ�����ֱ�����н�����á�
//�ͻ��˷ֱ治�����������������ʵ�������
//����ģʽ���Բ���֪�������ı��������
//����������һ�����������Ľӿڣ���ʱ���������ܹ��������������
//��������������ϵͳ��������ɫ��Ϊ���������롣
//
//��MM���������죬һ��ͷ���ǡ�hi, ��á�, 
//������Ķ���ѽ�����������ˣ�������߶���ѽ����
//��Щ�����淳�ˣ�д��������Ϊ�ҵ�Proxy�ɣ�
//���ǽ��յ���Щ�������ú����Լ��Ļش�
//���յ������Ļ�ʱ��֪ͨ�һش���ô������ɡ�


class SchoolGirl
{
public:
	string name;
};


class IGiveGift
{
public:
	virtual void giveDolls() = 0;
	virtual void giveFlowers() = 0;
};

class Pursuit :public IGiveGift
{
private:
	SchoolGirl mm;
public:
	Pursuit(SchoolGirl m)
	{
		mm = m;
	}
	void giveDolls()
	{
		cout << mm.name << " ��������" << endl;
	}
	void giveFlowers()
	{
		cout << mm.name << " �����ʻ�" << endl;
	}
};

class Proxy :public IGiveGift
{
private:
	Pursuit gg;
public:
	Proxy(SchoolGirl mm) :gg(mm)
	{
		//gg=g;
	}
	void giveDolls()
	{
		gg.giveDolls();
	}
	void giveFlowers()
	{
		gg.giveFlowers();
	}
};

int mai12312321n()
{
	SchoolGirl lijiaojiao;
	lijiaojiao.name = "���";
	Pursuit zhuojiayi(lijiaojiao);
	Proxy daili(lijiaojiao);

	daili.giveDolls();
	cin.get();
	return 0;
}