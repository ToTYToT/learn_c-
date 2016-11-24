 ///
 /// @file    virtualtest.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-10 15:20:24
 ///
 
#define THE_INFO_OF_RUN (std::cout<<"                FILE:"<<__FILE__<<" LINE:"<<__LINE__<<endl)


#include <iostream>  

using namespace std;  

class ZooAnimal  
{  
	public:  
		virtual void print()  
		{  
			cout << "run: ZooAnimal::print()" <<endl;  
		}  
		int a;  
};  

class Bear: public ZooAnimal  
{  
	public:  
		void run(int whichTable, int whichFunc)  
		{  
			//whichTable是个偏移量，用来在对象内存中找到vfptr，即找虚函数表  
			void (***func)(void)=reinterpret_cast<void (***)(void)>(this);  
			(*(func+whichTable))[whichFunc]();//运行哪个表中的哪个函数  
		}  

		virtual void dis()  
		{  
			cout << "run: Bear::dis()" <<endl;  
		}  
		void dis(char)  
		{  
			cout << "run: Bear::dis(char)" <<endl;  
		}  
		virtual void dis(int)  
		{  
			cout << "run: Bear::dis(int)" <<endl;  
		}  
		int b;  
};  


int main()  
{  

	Bear b;  

	ZooAnimal& a=static_cast<ZooAnimal&>(b);  
	cout << "ZooAnimal:" <<endl;  
	cout << "&a=" << &a <<endl;  
	cout << "&a.a=" << &a.a <<endl;  
	cout<<endl;  

	//a.run(0,0);  
	//a.run(0,1);  
	//a.run(0,2);  
	cout<<endl;  

	cout << "Bear:" <<endl;  
	cout << "&b=" << &b <<endl;  
	cout << "&b.a=" << &b.a <<endl;  
	cout << "&b.b=" << &b.b <<endl;  
	cout<<endl;  

	b.run(0,0);  
	b.run(0,1);  
	b.run(0,2);  
	cout<<endl;  

	cout << "sizeof(ZooAnimal)=" << sizeof(ZooAnimal)  <<endl;  
	cout << "sizeof(Bear)=" << sizeof(Bear) << endl;  
} 




