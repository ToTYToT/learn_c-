 ///
 /// @file    homework_sig.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-29 17:10:23
 ///

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class Singleton
{
	private:
		class AutoRelease
		{
			public:
				AutoRelease()
				{
                    cout<<"AutoRelease"<<endl;
                }

				~AutoRelease()
				{
                    cout<<"~AutoRelease"<<endl;
					if(_pInstance)
						delete _pInstance;
				}
		};
	public:
		static T * getInstance()
		{
            _autoRelease;
			if(NULL == _pInstance)
				_pInstance = new T;
			return _pInstance;
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
		static T * _pInstance;
		static AutoRelease _autoRelease;
};
template <typename T>
T * Singleton<T>::_pInstance = getInstance();
template <typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_autoRelease;

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
