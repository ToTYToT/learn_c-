 ///
 /// @file    computer3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-18 11:04:59
 ///

#include <string.h> //把C的头文件全部放在C++头文件的上面

#include <iostream> 

using std::cout;
using std::endl;


class Computer
{
public:
	Computer(const char * brand, float price);

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

//Computer pc("Mac", 10000);

int main(void)
{
	Computer com("Lenovo", 4000);
	com.print();
//	com.~Computer();//析构函数是可以显示调用；但是不推荐这样使用
					//它的主要功能就是清理现场
	cout << endl;

	//pc.print();

	return 0;
}
