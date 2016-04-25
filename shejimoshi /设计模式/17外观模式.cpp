#include <iostream>
#include <string>
using namespace std;
//����ģʽ���ⲿ��һ����ϵͳ��ͨ�ű���ͨ��һ��ͳһ�����������С�
//����ģʽ�ṩһ���߲�εĽӿڣ�ʹ����ϵͳ������ʹ�á�
//ÿһ����ϵͳֻ��һ�������࣬���Ҵ�������ֻ��һ��ʵ����
//Ҳ����˵����һ������ģʽ��������ϵͳ�����ж�������ࡣ
//
//����һ��רҵ��Nikon������Ҿ�ϲ���Լ��ֶ�����Ȧ�����ţ�
//�����ճ�������Ƭ��רҵ����MM�ɲ�����Щ�����˰���Ҳ���ᡣ
//�Һ������Facade���ģʽ��������������Զ�����
//ֻҪ��׼Ŀ�갴���ž����ˣ�һ��������Զ�������
//����MMҲ����������������������Ƭ�ˡ�

class Sub1
{
public:
	void f1()
	{
		cout << "��ϵͳ�ķ��� 1" << endl;
	}
};

class Sub2
{
public:
	void f2()
	{
		cout << "��ϵͳ�ķ��� 2" << endl;
	}
};

class Sub3
{
public:
	void f3()
	{
		cout << "��ϵͳ�ķ��� 3" << endl;
	}
};

class Facade
{
private:
	Sub1 *s1;
	Sub2 *s2;
	Sub3 *s3;
public:
	Facade()
	{
		s1 = new Sub1();
		s2 = new Sub2();
		s3 = new Sub3();
	}
	void method()
	{
		s1->f1();
		s2->f2();
		s3->f3();
	}
};

int mainB ()
{
	Facade *f = new Facade();
	f->method(); 
	cin.get();
	return 0;
}