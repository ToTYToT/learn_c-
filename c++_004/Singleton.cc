 ///
 /// @file    Singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-19 18:06:36
 ///

#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;


//单例模式 ===> 类似于C语言中的全局变量
//
//要求：通过该类在内存中只能产生一个对象

//1. 该对象不能是栈对象或者全局对象
//2. 该对象只能是以堆对象的形式存在


class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(NULL == _pInstance)
		{
			_pInstance = new Singleton;
		}
		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}
private:
	Singleton()
	{
		cout << "Singleton()" << endl;
	}

	~Singleton()
	{
		cout << "~Singleton()" << endl;
	}
private:
	static Singleton * _pInstance;
};

//Singleton s;
//Singleton s1;

//Singleton * Singleton::_pInstance = NULL;
//Singleton * Singleton::_pInstance =Singleton::getInstance();//first method
Singleton * Singleton::_pInstance =getInstance();//because Singleton have been here, so it could be omited
//for pthread safety, so when mang threadchild use the function getInstance, don't mutex.
int main(void)
{
	//Singleton s;//1.不希望该语句能够编译通过
// 将构造函数私有化	
//	Singleton * p1 = new Singleton;//2. 不希望该语句能够编译通过
//	继续构造函数私有化
	//Singleton * p2 = new Singleton;
	
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);

	Singleton::destroy();

	//delete p1;//3. 不希望该语句能够编译通过
	return 0;
}
