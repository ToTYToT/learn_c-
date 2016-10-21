 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-19 16:29:35
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class Computer
{
public:
	Computer(const char * brand, float price)
	: _brand(new char[strlen(brand) + 1])
	, _price(price)
	{
		_totalPrice += _price;
		strcpy(_brand, brand);
	}

	~Computer()
	{
		delete [] _brand;
		_totalPrice -= _price;
	}

	//静态成员函数里面只能访问静态数据成员，
	//不能访问非静态的数据成员和成员函数
	static void printTotalprice()
	{
		cout << "总价：" << _totalPrice << endl;
	}

	//静态成员函数的参数之中不包含隐式的this指针
	static void print(Computer & com)
	{
		cout << "品牌:" << com._brand << endl;
		cout << "价格:" << com._price << endl;
	}

private:
	char * _brand;
	float _price;
	static float _totalPrice;
};

//静态数据成员只能在类之外进行初始化
//它会由类生成的所有对象共享
float Computer::_totalPrice = 0.0;

int main(void)
{
	Computer pc1("iBM", 5000);
	//pc1.print(pc1);
	Computer::print(pc1);
	Computer::printTotalprice();//静态成员函数更一般的用法是通过类名进行调用
	cout << endl;

	Computer pc2("ASUS", 4000);
	Computer::print(pc2);
	Computer::printTotalprice();

	return 0;
}
