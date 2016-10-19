 ///
 /// @file    computer4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-18 11:04:59
 ///

#include <string.h>
#include <iostream> 

using std::cout;
using std::endl;


class Computer
{
public:
	Computer(const char * brand, float price);

#if 0
	//系统默认的复制构造函数
	Computer(const Computer & rhs)
	: _brand(rhs._brand)  //浅拷贝
	, _price(rhs._price)
	{
		
	}
#endif

	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1]) 
	, _price(rhs._price)
	{
		cout << "Computer(const Computer &)" << endl;
		strcpy(_brand, rhs._brand);// 深拷贝
	}


	~Computer();

	void print();//成员函数

	void setBrand(const char * brand);

	void setPrice(float price);
private:
	char * _brand;//成员数据
	float _price;//代码风格
};

Computer::Computer(const char * brand, float price)
: _brand(new char[strlen(brand) + 1])
, _price(price)
{
	cout << "Computer(const char *, float)" << endl;
	strcpy(_brand, brand);
}


Computer::~Computer()
{
	cout << "~Computer()" << endl;
	delete [] _brand;
}

void Computer::print()
{
	cout << "品牌:" << _brand << endl;	
	cout << "价格:" << _price << endl;
}

void Computer::setPrice(float price)
{
	_price = price;
}

void Computer::setBrand(const char * brand)
{
	strcpy(_brand, brand);
}

int main(void)
{
	Computer com("Lenovo", 4000);
	com.print();
	cout << endl;

	Computer pc(com);//调用的复制构造函数
	pc.print();

	return 0;
}
