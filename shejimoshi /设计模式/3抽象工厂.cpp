#include <iostream>
#include <string>
using namespace std;



//����ģʽ���ͻ���͹�����ֿ���
//�������κ�ʱ����Ҫĳ�ֲ�Ʒ��ֻ���򹤳����󼴿ɡ�

//�����������޸ľͿ��Խ����²�Ʒ��ȱ���ǵ���Ʒ�޸�ʱ��

//������ҲҪ����Ӧ���޸ġ��磺��δ����������ͻ����ṩ��
//
//׷MM�ٲ�����Է��ˣ����͵ļ���Ϳϵ»��ļ��ᶼ��MM���ԵĶ�����
//��Ȼ��ζ������ͬ�����������MMȥ���ͻ�ϵ»���
//ֻ�������Ա˵�����ĸ����ᡱ�����ˡ����ͺͿϵ»��������������Factory��


//�����߲��̶��������߲��̶������������������߶�����

//ʵ�������߳�����࣬�������������ʵ�֣�ʵ��������������

//�����ĳ�����࣬ʵ����������ֲ�����ʵ�����Ĳ���

//�����ĳ����࣬���������������������Ľӿڣ������ߣ�������
//������ʵ���˹�����ĳ���ʵ�����������࣬ʵ�ֹ�����
//�����û������û������ݲ������ò���







class IUser
{
public:
	virtual void getUser() = 0;  //����ӿ��࣬������
	virtual void setUser() = 0;
};

class SqlUser :public IUser   //�̳г���ʵ��sql���ݿ�ʹ���ߵ�ʵ����
{
public:
	void getUser()
	{
		cout << "��sql�з���user" << endl;
	}
	void setUser()
	{
		cout << "��sql������user" << endl;
	}
};

class AccessUser :public IUser //�̳г���ʵ��access���ݿ�ʹ���ߵ�ʵ����
{
public:
	void getUser()
	{
		cout << "��Access�з���user" << endl;
	}
	void setUser()
	{
		cout << "��Access������user" << endl;
	}
};


class IDepartment  //�����࣬�ṩ�ӿ�
{
public:
	virtual void getDepartment() = 0;
	virtual void setDepartment() = 0;
};




class SqlDepartment :public IDepartment  //SQL������ʵ��
{
public:
	void getDepartment()
	{
		cout << "��sql�з���Department" << endl;
	}
	void setDepartment()
	{
		cout << "��sql������Department" << endl;
	}
};

class AccessDepartment :public IDepartment //access������ʵ��
{
public:
	void getDepartment()
	{
		cout << "��Access�з���Department" << endl;
	}
	void setDepartment()
	{
		cout << "��Access������Department" << endl;
	}
};

class IFactory     //���󹤳�
{
public:
	virtual IUser *createUser() = 0;
	virtual IDepartment *createDepartment() = 0;
};

class SqlFactory :public IFactory  //���󹤳�һ��ʵ��
{
public:
	IUser *createUser()
	{
		return new SqlUser();
	}
	IDepartment *createDepartment()
	{
		return new SqlDepartment();
	}
};

class AccessFactory :public IFactory // ���󹤳�һ��ʵ��
{
public:
	IUser *createUser()
	{
		return new AccessUser();
	}
	IDepartment *createDepartment()
	{
		return new AccessDepartment();
	}
};

/*************************************************************/
//�����ʵ���˾�̬��
class DataAccess
{
private:
	static string db;
	//string db="access";
public:
	static IUser *createUser()
	{
		if (db == "access")
		{
			return new AccessUser();
		}
		else if (db == "sql")
		{
			return new SqlUser();
		}
	}
	static IDepartment *createDepartment()
	{
		if (db == "access")
		{
			return new AccessDepartment();
		}
		else if (db == "sql")
		{
			return new SqlDepartment();
		}
	}
};
string DataAccess::db = "sql";

/*************************************************************/


int main12321312321()
{
	//IFactory *factory=new SqlFactory();
	IFactory *factory;//���󹤳�
	IUser *user;//����������
	IDepartment *department;//�ṩ�Ĳ���

	factory = new AccessFactory();//�����ָ��ָָ��������Ķ���
	user = factory->createUser();//�����ָ��ָ��������Ķ���
	department = factory->createDepartment();//�����ָ��ָ��������Ķ���

	user->getUser();
	user->setUser();//����acesss�ӿ�

	department->getDepartment();
	department->setDepartment();//�ӿ�


	user = DataAccess::createUser();
	department = DataAccess::createDepartment();

	user->getUser();
	user->setUser();
	department->getDepartment();
	department->setDepartment();


	cin.get();


	return 0;
}