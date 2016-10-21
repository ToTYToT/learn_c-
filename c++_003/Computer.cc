 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-19 16:29:35
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Computer
{
public:
	Computer(float price)
	: _price(price)
	{
		_totalPrice += _price;
	}

	~Computer()
	{
		_totalPrice -= _price;
		//cout << "总价：" << _totalPrice << endl;
	}

	void printTotalprice()
	{
		cout << "总价：" << _totalPrice << endl;
	}
private:
	float _price;
	static float _totalPrice;
};

//静态数据成员只能在类之外进行初始化
//它会由类生成的所有对象共享
float Computer::_totalPrice = 0.0;

int main(void)
{
	Computer pc1(5000);
	pc1.printTotalprice();
	Computer pc2(4000);
	pc2.printTotalprice();

	return 0;
}
