#include <iostream>
#include <string>
using namespace std;
//����������ѹ����ģʽ����һ����Ľӿڱ任�ɿͻ������ڴ�����һ�ֽӿ�
//���Ӷ�ʹԭ����ӿ�ԭ��ƥ����޷�һ�������������ܹ�һ������
//��������Ը��ݲ�������һ�����ʵ�ʵ�����ͻ��ˡ�
//
//�����Ѿۻ���������һ����ŮSarah����������ģ�
//���Ҳ���˵���������˵��ͨ����ֻ���������ҵ�����kent�ˣ�
//����Ϊ�Һ�Sarah֮���Adapter�����Һ�Sarah�����໥��̸��
//(Ҳ��֪�����᲻��ˣ��)��

class Player
{
public:
	string name;
	Player(string name)
	{
		this->name = name;
	}
	virtual void attack() = 0;
	virtual void defence() = 0;
};

class Forwards :public Player
{
public:
	Forwards(string name) :Player(name){}
	void attack()
	{
		cout << name << " ǰ�����" << endl;
	}
	void defence()
	{
		cout << name << " ǰ�����" << endl;
	}
};

class Center :public Player
{
public:
	Center(string name) :Player(name){}
	void attack()
	{
		cout << name << " �з����" << endl;
	}
	void defence()
	{
		cout << name << " �з����" << endl;
	}
};

class Backwards :public Player
{
public:
	Backwards(string name) :Player(name){}
	void attack()
	{
		cout << name << " ��������" << endl;
	}
	void defence()
	{
		cout << name << " ��������" << endl;
	}
};
/*****************************************************************/
class ForeignCenter
{
public:
	string name;
	ForeignCenter(string name)
	{
		this->name = name;
	}
	void myAttack()
	{
		cout << name << " �⼮�з����" << endl;
	}
	void myDefence()
	{
		cout << name << " �⼮��������" << endl;
	}
};
/*****************************************************************/
class Translator :public Player
{
private:
	ForeignCenter *fc;
public:
	Translator(string name) :Player(name)
	{
		fc = new ForeignCenter(name);
	}
	void attack()
	{
		fc->myAttack();
	}
	void defence()
	{
		fc->myDefence();
	}
};
/*****************************************************************/
int mainM()
{
	Player *p1 = new Center("���");
	p1->attack();
	p1->defence();

	Translator *tl = new Translator("Ҧ��");
	tl->attack();
	tl->defence();
	cin.get();
	return 0;
}