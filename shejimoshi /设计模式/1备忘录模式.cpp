#include <iostream>
#include <string>
#include <vector>
using namespace std;
//����¼ģʽ������¼������һ�������洢����һ�������ڲ�״̬�Ŀ��յĶ���
//����¼ģʽ���������ڲ��ƻ���װ�������£���һ�������״̬׽ס��
//���ⲿ�����洢�������Ӷ������ڽ������ʵ�ʱ����������ԭ���洢������״̬��

//ͬʱ������MM����ʱ��һ��Ҫ������ղŸ�MM˵��Щʲô��
//����ȻMM�����˻᲻���˵�Ŷ���ҿ����и�����¼��
//�ղ����ĸ�MM˵��ʲô���Ҷ�����һ�ݷŵ�����¼���汣�棬
//����������ʱ�쿴��ǰ�ļ�¼����

//�����Ҫ�طŵ��������¼һ�������״̬�����ݿⱸ�ݣ��ĵ��ı��룬�������ָ�



//��Ʊ���¼������
//1.��Ƽ�¼�Ľڵ㣬�洢��¼��//��¼��꣬���̵�״̬
//2.��Ƽ�¼�Ĵ洢��vector,list��map,set,����ͼ�����飬��
//3.������¼���࣬��¼�ڵ�״̬�����ýڵ�״̬����ʾ״̬��0.1���¼һ��




//����¼�Ľڵ㣬
class Memo
{
public:
	string state;
	Memo(string state) //��¼��ǰ��״̬��
	{
		this->state = state;
	}
};

class Originator//��İ�������¼�Ľڵ�
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


//����¼�ļ���
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
