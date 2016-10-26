 ///
 /// @file    Singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-26 11:11:57
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

//Singleton自动释放: 内部类 + 静态对象
class Singleton
{
private:// AutoRelease是专为Singleton服务的
		// 不需要去单独的创建一个AutoRelease对象
	class AutoRelease
	{
	public:
		AutoRelease()
		{}

		~AutoRelease()
		{
			if(_pInstance)
				delete _pInstance;
		}
	};
public:
	static Singleton * getInstance()
	{
		if(NULL == _pInstance)
			_pInstance = new Singleton;
		return _pInstance;
	}

#if 0
	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}
#endif

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
	static AutoRelease _autoRelease;
};

Singleton * Singleton::_pInstance = getInstance();

Singleton::AutoRelease Singleton::_autoRelease;

int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();

	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);

	return 0;
}
