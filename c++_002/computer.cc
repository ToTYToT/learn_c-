 ///
 /// @file    computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-18 11:04:59
 ///

//#include ""    // 自定义的头文件放在C头文件的上面
 
#include <string.h> //把C的头文件全部放在C++头文件的上面

#include <iostream> 

using std::cout;
using std::endl;


struct X
{
//public
int a;
int b;
};


float price = 1.1;
//把类的public部分的内容放在上面，
//private部分的内容放在下面
class Computer
{
public:// 与其他对象进行交互,接口
	void print()//成员函数
	{
		cout << "品牌:" << _brand << endl;	
		cout << "价格:" << _price << endl;
	}

	void setBrand(const char * brand)
	{
		strcpy(_brand, brand);
	}

	void setPrice(float price)
	{
		_price = price;
	}
private:// 封装
	char _brand[20];//成员数据
	float _price;//代码风格
};


int main(void)
{
	Computer com;
	//com._price = 4000;//Error，_price已经被封装了，不能直接访问
	com.setPrice(4000);
	com.setBrand("Lenovo");
	com.print();

	return 0;
}
