#include <iostream>
#include <string>
using namespace std;
//门面模式：外部与一个子系统的通信必须通过一个统一的门面对象进行。
//门面模式提供一个高层次的接口，使得子系统更易于使用。
//每一个子系统只有一个门面类，而且此门面类只有一个实例，
//也就是说它是一个单例模式。但整个系统可以有多个门面类。
//
//我有一个专业的Nikon相机，我就喜欢自己手动调光圈、快门，
//这样照出来的照片才专业，但MM可不懂这些，教了半天也不会。
//幸好相机有Facade设计模式，把相机调整到自动档，
//只要对准目标按快门就行了，一切由相机自动调整，
//这样MM也可以用这个相机给我拍张照片了。

class Sub1
{
public:
	void f1()
	{
		cout << "子系统的方法 1" << endl;
	}
};

class Sub2
{
public:
	void f2()
	{
		cout << "子系统的方法 2" << endl;
	}
};

class Sub3
{
public:
	void f3()
	{
		cout << "子系统的方法 3" << endl;
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