#include <iostream>
#include <string>
using namespace std;
//״̬ģʽ��״̬ģʽ����һ�����������ڲ�״̬�ı��ʱ��ı���Ϊ��
//���������ȥ���Ǹı���������һ����״̬ģʽ�����о��Ķ������
//Ϊ��װ�ڲ�ͬ��״̬�����ÿһ��״̬��������һ������״̬���
//һ�����ࡣ״̬ģʽ����ͼ����һ�����������ڲ�״̬�ı��ʱ��
//����ΪҲ��֮�ı䡣״̬ģʽ��Ҫ��ÿһ��ϵͳ����ȡ�õ�״̬����һ��״̬���
//���ࡣ��ϵͳ��״̬�仯ʱ��ϵͳ��ı���ѡ�����ࡣ
//
//��MM����ʱ��һ��Ҫע������״̬Ŷ���ڲ�ͬ��״̬ʱ������Ϊ���в�ͬ��
//������Լ����������ȥ����Ӱ������û��Ȥ��MM�ͻ�˵������������
//�����㲻���ᵫ��ûϲ���ϵ�MM�ͻ�˵���ð����������Դ�����ͬ��ô����
//���Ѿ�ϲ�������MM�ͻ�˵�������ӣ������Ӱ��ȥ�ݰ���ô��������
//��Ȼ�㿴��Ӱ�����б������õĻ���Ҳ���԰�MM��״̬�Ӳ����᲻ϲ�����ϲ��Ŷ��

class Work;
class State;
class ForenonnState;


class State
{
public:
	virtual void writeProgram(Work*) = 0;//׼��̨�Ļ��࣬������
};

class Work   //ʵʩ�������࣬����״ִ̬�в�ͬ�Ĳ���
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

class EveningState :public State  //����״̬
{
public:
	void writeProgram(Work *w)
	{
		cout << "��ǰʱ��: " << w->hour << "����ܺã��ڿ���������Щ�¶������ջ�ܴ�" << endl;
	}
};

class AfternoonState :public State  
{
public:
	void writeProgram(Work *w)
	{
		if (w->hour < 19)
		{
			cout << "��ǰʱ��: " << w->hour << "������˯�󣬹������Ǿ���ٱ�!" << endl;
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
			cout << "��ǰʱ��: " << w->hour << "���繤������ٱ�!" << endl;
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