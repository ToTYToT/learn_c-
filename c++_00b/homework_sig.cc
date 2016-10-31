 ///
 /// @file    homework_sig.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-29 17:39:18
 ///
 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class Singleton
{
public:
	static T* getInstance()
	{
        cout<<"getInstance"<<endl;
		pthread_once(&_once, init);
		return _pInstance;
	}
private:
	static void init()
	{
        cout<<"init"<<endl;
		_pInstance = new T;
		atexit(destroy);
	}

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
	static T* _pInstance;
	static pthread_once_t _once;
};
template <typename T>
T * Singleton<T>::_pInstance = NULL;
template <typename T>
pthread_once_t Singleton<T>::_once = PTHREAD_ONCE_INIT;

class M
{
public:
    void print()
    {
        cout<<"M"<<endl;
    }
};
class N
{
public:
    void print()
    {
        cout<<"N"<<endl;
    }
};

int main(void)
{
	M* p1 = Singleton<M>::getInstance();
	M* p2 = Singleton<M>::getInstance();
	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);
    p1->print();
    p2->print();
	N* p3 = Singleton<N>::getInstance();
	N* p4 = Singleton<N>::getInstance();
	printf("p3 = %p\n", p3);
	printf("p4 = %p\n", p4);
    p3->print();
    p4->print();
	return 0;
}
#if 0
int main(void)
{
	* p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();

	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);

	return 0;
}
#endif
