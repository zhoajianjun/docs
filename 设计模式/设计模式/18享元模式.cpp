#include <iostream>
#include <list>
#include <string>
#include <map>
using namespace std;

//��Ԫģʽ��FLYWEIGHT��ȭ��������ָ����������
//��Ԫģʽ�Թ���ķ�ʽ��Ч��֧�ִ�����ϸ���ȶ���
//��Ԫģʽ����������Ĺؼ�����������״̬������״̬��
//����״̬�洢����Ԫ�ڲ��������滷���ĸı��������ͬ��
//����״̬���滷���ĸı���ı�ġ�����״̬����Ӱ������״̬��
//�������໥�����ġ������Թ����״̬�Ͳ����Թ����״̬�ӳ����������ֿ�����
//�������Թ����״̬�������޳���ȥ���ͻ��˲�����ֱ�Ӵ���������Ķ���
//��Ӧ��ʹ��һ�����������𴴽�������Ķ���
//��Ԫģʽ����ȵĽ����ڴ��ж����������
//
//ÿ���MM�����ţ���ָ�������ˣ�������˸����ֻ���
//���԰�һЩ���õľ��Ӵ����ֻ��Ҫ�õ�ʱ��ֱ���ó���
//����ǰ�����MM�����־Ϳ��Է����ˣ��ٲ���һ����һ�������ˡ�
//����ľ��Ӿ���Flyweight��MM�����־�����ȡ�������ⲿ������
//�������������ʹ�á�



class WebSite
{
public:
	virtual void use() = 0;//Ԥ���ӿ�ʵ�ֹ���
};

class ConcreteWebSite :public WebSite
{
private:
	string name;
public:
	ConcreteWebSite(string name)//ʵ����
	{
		this->name = name;
	}
	void use()
	{
		cout << "��վ����: " << name << endl;
	}
};

class WebSiteFactory
{
private:
	map<string, WebSite*> wf;
public:

	WebSite *getWebSiteCategory(string key)
	{

		if (wf.find(key) == wf.end())
		{
			wf[key] = new ConcreteWebSite(key);
		}

		return wf[key];
	}

	int getWebSiteCount()
	{
		return wf.size();
	}
};

int main123qweqe()
{
	WebSiteFactory *wf = new WebSiteFactory();

	WebSite *fx = wf->getWebSiteCategory("good");
	fx->use();

	WebSite *fy = wf->getWebSiteCategory("��Ʒչʾ");
	fy->use();

	WebSite *fz = wf->getWebSiteCategory("��Ʒչʾ");
	fz->use();


	WebSite *f1 = wf->getWebSiteCategory("����");
	f1->use();

	WebSite *f2 = wf->getWebSiteCategory("����");
	f2->use();

	cout << wf->getWebSiteCount() << endl;

	cin.get();
	return 0;
}