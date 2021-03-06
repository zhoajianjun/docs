#include <iostream>
#include <string>
using namespace std;
//原型模式允许动态的增加或减少产品类，
//产品类不需要非得有任何事先确定的等级结构，
//原始模型模式适用于任何的等级结构。
//缺点是每一个类都必须配备一个克隆方法。


//跟MM用QQ聊天，一定要说些深情的话语了，
//我搜集了好多肉麻的情话，需要时只要copy出来放到QQ里面就行了，
//这就是我的情话prototype了。
//原型模式：通过给出一个原型对象来指明所要创建的对象的类型，
//然后用复制这个原型对象的方法创建出更多同类型的对象。

class Resume
{
private:
	string name, sex, age, timeArea, company;
public:
	Resume(string s)
	{
		name = s;
	}
	void setPersonalInfo(string s, string a)
	{
		sex = s;
		age = a;
	}
	void setWorkExperience(string t, string c)
	{
		timeArea = t;
		company = c;
	}
	void display()
	{
		cout << name << "  " << sex << "  " << age << endl;
		cout << "工作经历:  " << timeArea << "  " << company << endl << endl;

	}
	Resume *clone()
	{
		Resume *b;
		b = new Resume(name);
		b->setPersonalInfo(sex, age);
		b->setWorkExperience(timeArea, company);
		return b;
	}
};


int main213123()
{
	Resume *r = new Resume("李彦宏");
	r->setPersonalInfo("男", "30");
	r->setWorkExperience("2007-2010", "读研究生");
	r->display();


	Resume *r2 = r->clone();
	r2->setWorkExperience("2003-2007", "读本科");

	r->display();
	r2->display();

	cin.get();
	return 0;
}