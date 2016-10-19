 ///
 /// @file    computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-18 11:04:59
 ///

#include <string.h> //把C的头文件全部放在C++头文件的上面

#include <iostream> 

using std::cout;
using std::endl;


struct X
{
//默认情况下是public
//public

void setA(int ia)
{
	a = ia;
}

void setB(int ib)
{
	b = ib;
}

int a;
int b;
};


class Computer
{//默认情况下的访问修饰符是private
public:// 与其他对象进行交互,接口

	void print();//成员函数

	void setBrand(const char * brand);

	void setPrice(float price);
private:// 封装
	char _brand[20];//成员数据
	float _price;//代码风格
};

//在类之外实现成员函数
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
	Computer com;
	//com._price = 4000;//Error，_price已经被封装了，不能直接访问
	com.setPrice(4000);
	com.setBrand("Lenovo");
	com.print();

	X x;
	x.setA(3);
	x.setB(4);

	return 0;
}
