 ///
 /// @file    Complex3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-24 16:28:09
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Complex
{
public:
	explicit
	Complex(double dreal, double dimag = 0)
	: _dreal(dreal)
	, _dimag(dimag)
	{
	
	}
	
	void display() const
	{
		if(_dreal == 0)
		{
			if(_dimag == 0)
				cout << "0" << endl;
			else
				cout << _dimag << "i" << endl;
		}
		else
		{	
			if(_dimag > 0)
				cout << _dreal << " + " << _dimag << "i" << endl;
			else if(_dimag == 0)
				cout << _dreal << endl;
			else 
				cout << _dreal << " - " << _dimag * (-1) << "i" << endl;
		}
	}

	//前置++,其运行效率高于后置++
	Complex & operator ++()
	{ 
		++_dreal;
		++_dimag;
		return *this;
	}
	//int仅仅是作为区分前置的标识,并不代表参数
	Complex  operator ++(int)
	{
		Complex tmp(*this);
		++_dreal;
		++_dimag;
		return tmp;
	}

	//复合赋值运算符推荐以成员函数形式重载
	Complex & operator+=(const Complex & rhs)
	{
		_dreal += rhs._dreal;
		_dimag += rhs._dimag;
		return *this;
	}

#if 0
	//不推荐
	Complex operator +(const Complex & rhs)
	{
		return Complex(_dreal + rhs._dreal,
					   _dimag + rhs._dimag);
	
	}
#endif

	double getReal()const
	{	return _dreal;	}

	double getImage() const
	{	return _dimag;	}
private:
	double _dreal;
	double _dimag;
};


//以自由函数形式进行重载

#if 0
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	return Complex(lhs.getReal() + rhs.getReal(), 
				   lhs.getImage() + rhs.getImage());
}
#endif

Complex operator+(const Complex & lhs, const Complex & rhs)
{
	Complex tmp(lhs);
	tmp += rhs;
	return tmp;
}
//不推荐使用自由函数形式进行重载
#if 0
Complex & operator +=(Complex & lhs, const Complex & rhs)
{
	
}
#endif

#if 0
//内置类型的云算符不能进行重载
//只能针对于自定义类类型或者枚举类型
int operator + (int a, int b)
{
	retuan a - b;
}
#endif

int test(void)
{
	Complex c1(3, 4);
	Complex c2(-3, -4);
	Complex c3(0, -4);

	c1.display();
	c2.display();
	c3.display();

	c3 = c1 + c2;
	c3.display();

	cout << sizeof(int) << endl;
	cout << sizeof c1 << endl;//sizeof不是函数，是关键字

	return 0;
}

int test1(void)
{
	int a = 1;
	++a;// 2
	a++;// 2  , a 3

	Complex c1(1,1);
	c1.display();
	cout << "前置++ 的值:";
	(++c1).display();
	c1.display();

	cout << "后置++ 的值:";
	(c1++).display();
	c1.display();

	return 0;
}


int main(void)
{
	test();
	test1();
	int a = 1;
	int b = 2;
	a += b;//a = a + b;

	Complex c1(1,2);
	//Complex c2 = c1 + 5;//隐式转换
	//c1.operator+(5);
	//c2.display();
	//Complex c3 = 5 + c1;//当成员函数的形式进行重载时，不能正常运行
	//5.operator+(c1);
	//c3.display();

}

