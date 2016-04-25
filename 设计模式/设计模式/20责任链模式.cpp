#include<iostream>
#include <string>
using namespace std;

//������ģʽ����������ģʽ�У��ܶ������ÿһ����������¼ҵ����ö��������γ�
//һ������������������ϴ��ݣ�ֱ�����ϵ�ĳһ������������������
//�ͻ�����֪�����ϵ���һ���������մ����������ϵͳ�����ڲ�Ӱ��ͻ��˵�
//����¶�̬��������֯���ͷ������Ρ�������������ѡ�񣺳е����λ��߰�����
//�Ƹ��¼ҡ�һ������������ղ����κν��ն˶��������ܡ�
//
//����ȥ��Ӣ��Σ�Ϊ�˺ÿ������������һ�ţ��ۣ�ǰ�����˺ü���Ư����MM����
//����ֽ����д�ϡ�Hi, �������ҵ�Ů�����������Ը������ǰ������
//ֽ����һ����һ���Ĵ���ȥ�ˣ���⣬������һ�ŵ�MM��ֽ��������ʦ�ˣ�
//��˵�Ǹ��ϴ�Ůѽ������!

class Request  //����
{
public:
	string requestType;
	string requestContent;
	int number;
};

class Manager  ///������
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

class CommonManager :public Manager  //����
{
public:
	CommonManager(string name) :Manager(name)
	{}
	void requestApplications(Request *request)
	{
		if (request->requestType == "���" && request->number <= 2)
		{
			cout << name << " " << request->requestContent << " ����: " << request->number << "����׼" << endl;
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

class Majordomo :public Manager  //�ܼ�
{
public:
	Majordomo(string name) :Manager(name)
	{}
	void requestApplications(Request *request)
	{
		if (request->requestType == "���" && request->number <= 5)
		{
			cout << name << " " << request->requestContent << " ����: " << request->number << "����׼" << endl;
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


class GeneralManager :public Manager //�ܾ���
{
public:
	GeneralManager(string name) :Manager(name)
	{}
	void requestApplications(Request *request)
	{
		if (request->requestType == "���")
		{
			cout << name << " " << request->requestContent << " ����: " << request->number << "����׼" << endl;
		}
	}
};


int main123213123213()
{
	CommonManager *jinli = new CommonManager("����");
	Majordomo *zongjian = new Majordomo("�ܼ�");
	GeneralManager *zhongjingli = new GeneralManager("�ܾ���");

	jinli->setSuperior(zongjian);
	zongjian->setSuperior(zhongjingli);

	Request *request = new Request();

	request->requestType = "���";
	request->requestContent = "������";
	request->number = 1;
	jinli->requestApplications(request);


	request->requestType = "���";
	request->requestContent = "������";
	request->number = 4;
	jinli->requestApplications(request);


	request->requestType = "���";
	request->requestContent = "������";
	request->number = 10;
	jinli->requestApplications(request);

	cin.get();
	return 0;
}