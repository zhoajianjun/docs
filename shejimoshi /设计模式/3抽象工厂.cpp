#include <iostream>
#include <string>
using namespace std;



//工厂模式：客户类和工厂类分开。
//消费者任何时候需要某种产品，只需向工厂请求即可。

//消费者无须修改就可以接纳新产品。缺点是当产品修改时，

//工厂类也要做相应的修改。如：如何创建及如何向客户端提供。
//
//追MM少不了请吃饭了，麦当劳的鸡翅和肯德基的鸡翅都是MM爱吃的东西，
//虽然口味有所不同，但不管你带MM去麦当劳或肯德基，
//只管向服务员说“来四个鸡翅”就行了。麦当劳和肯德基就是生产鸡翅的Factory。


//消费者不固定，工厂者不固定，（工厂根据消费者动作）

//实现消费者抽象基类，消费者派生类的实现，实例化就是消费者

//操作的抽象基类，实现派生类各种操作，实例化的操作

//工厂的抽象类，抽象类包含了两个抽象类的接口（消费者，操作）
//抽象类实现了工厂类的抽象，实例化的派生类，实现工厂，
//根据用户设置用户，根据操作设置操作







class IUser
{
public:
	virtual void getUser() = 0;  //纯虚接口类，抽象类
	virtual void setUser() = 0;
};

class SqlUser :public IUser   //继承抽象实现sql数据库使用者的实例化
{
public:
	void getUser()
	{
		cout << "在sql中返回user" << endl;
	}
	void setUser()
	{
		cout << "在sql中设置user" << endl;
	}
};

class AccessUser :public IUser //继承抽象实现access数据库使用者的实例化
{
public:
	void getUser()
	{
		cout << "在Access中返回user" << endl;
	}
	void setUser()
	{
		cout << "在Access中设置user" << endl;
	}
};


class IDepartment  //抽象类，提供接口
{
public:
	virtual void getDepartment() = 0;
	virtual void setDepartment() = 0;
};




class SqlDepartment :public IDepartment  //SQL操作的实现
{
public:
	void getDepartment()
	{
		cout << "在sql中返回Department" << endl;
	}
	void setDepartment()
	{
		cout << "在sql中设置Department" << endl;
	}
};

class AccessDepartment :public IDepartment //access操作的实现
{
public:
	void getDepartment()
	{
		cout << "在Access中返回Department" << endl;
	}
	void setDepartment()
	{
		cout << "在Access中设置Department" << endl;
	}
};

class IFactory     //抽象工厂
{
public:
	virtual IUser *createUser() = 0;
	virtual IDepartment *createDepartment() = 0;
};

class SqlFactory :public IFactory  //抽象工厂一个实现
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

class AccessFactory :public IFactory // 抽象工厂一个实现
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
//变相的实现了静态类
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
	IFactory *factory;//抽象工厂
	IUser *user;//抽象消费者
	IDepartment *department;//提供的操作

	factory = new AccessFactory();//基类的指针指指向派生类的对象
	user = factory->createUser();//基类的指针指向派生类的对象
	department = factory->createDepartment();//基类的指针指向派生类的对象

	user->getUser();
	user->setUser();//访问acesss接口

	department->getDepartment();
	department->setDepartment();//接口


	user = DataAccess::createUser();
	department = DataAccess::createDepartment();

	user->getUser();
	user->setUser();
	department->getDepartment();
	department->setDepartment();


	cin.get();


	return 0;
}