#include <iostream>
#include <string>
using namespace std;
//����ģʽ������ģʽȷ��ĳһ����ֻ��һ��ʵ����
//��������ʵ������������ϵͳ�ṩ���ʵ������ģʽ
//������ģʽֻӦ���������ġ���һʵ����������ʱ�ſ�ʹ�á�
//
//����6��Ư�������ţ����ǵ��Ϲ������ң�
//�Ҿ������Ǽ�����Ϲ�Sigleton������ֻҪ˵�����Ϲ�����
//����ָ��ͬһ���ˣ��Ǿ�����(�ղ����˸�������������ô�õ���)��

//#define  public private 

class 
{
public:
protected:
private:
}a1;

class Singleton
{
private:
	int i;
	static Singleton *instance;
	Singleton(int i)
	{
		this->i = i;
	}
public:
	static Singleton *getInstance()
	{
		return instance;
	}
	void show()
	{
		cout << i << endl;
	}
};
Singleton* Singleton::instance = new Singleton(8899);

class A :public Singleton
{

};

int mainJ()
{
	Singleton *s = Singleton::getInstance();
	Singleton *s2 = A::getInstance();
	cout << (s == s2) << endl;
	cin.get();
	return 0;
}