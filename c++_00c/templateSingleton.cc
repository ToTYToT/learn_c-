 ///
 /// @file    templateSingleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-31 10:03:34
 ///
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;


template <typename T>
class Singleton
{
	class AutoRelease
	{
	public:
		AutoRelease()
		{
			cout << "AutoRelease()" << endl;
		}

		~AutoRelease()
		{
			if(_pInstance)
			{
				cout << "~AutoRelease()" << endl;
				delete _pInstance;
			}
		}
	};
public:
	static T * getInstance()
	{
		if(NULL == _pInstance)
		{	
			_autoRelease;//在实际调用的时候,必须去使用
			_pInstance = new T;
		}
		return _pInstance; 
	}

#if 0
	static void destroy()
	{
		if(_pInstance)
		{
			delete _pInstance;
		}
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
	static T * _pInstance;
	static AutoRelease _autoRelease;
};

template <typename T>
T * Singleton<T>::_pInstance = getInstance();

template <typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_autoRelease;

class A
{
public:
	A(){	cout << "A()" << endl;	}
	~A(){	cout << "~A()" << endl;	}
};

int main(void)
{
#if 1
	int * p1 = Singleton<int>::getInstance();
	int * p2 = Singleton<int>::getInstance();
	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);
#endif

	A * p3 = Singleton<A>::getInstance();
	A * p4 = Singleton<A>::getInstance();
	printf("p3 = %p\n", p3);
	printf("p4 = %p\n", p4);

	return 0;
}
