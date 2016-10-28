 ///
 /// @file    Singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-26 11:11:57
 ///
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(NULL == _pInstance)
		{
			_pInstance = new Singleton;
			atexit(destroy);
		}
		return _pInstance;
	}
private:
	static void destroy()
	{
		cout<<"destroy"<<endl;
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

Singleton * Singleton::_pInstance = getInstance();

int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	//p1->destroy();
	//p2->destroy();
	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);

	return 0;
}
