 ///
 /// @file    Complex.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-25 10:28:09
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;


class Complex
{
	friend ostream & operator<<(ostream & os, const Complex & rhs);
	friend istream & operator>>(istream & is, Complex & rhs);
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
				cout << "0" << endl;//链式编程
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
	Complex operator ++(int)
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

	//ostream & operator<<() //要求是:左操作数必须是ostream流类型
						   //如果作为成员函数进行重载,左操作数
						   //是this指针,与要求相冲突
	
	double getReal()const
	{	return _dreal;	}

	double getImage() const
	{	return _dimag;	}
private:
	double _dreal;
	double _dimag;
};

//输入流运算符只能以友元函数形式进行重载
istream & operator>>(istream & is, Complex & rhs)
{
	is >> rhs._dreal;
	while(is.get() != '*');
	is >> rhs._dimag;
	return is;
}
//输出流运算符只能以友元函数形式进行重载
ostream & operator<<(ostream & os, const Complex & rhs)
{
	if(rhs._dreal == 0)
	{
		if(rhs._dimag == 0)
			os << "0" << endl;//链式编程
		else
			os << rhs._dimag << "i" << endl;
	}
	else
	{	
		if(rhs._dimag > 0)
			os << rhs._dreal << " + " << rhs._dimag << "i" << endl;
		else if(rhs._dimag == 0)
			os << rhs._dreal << endl;
		else 
			os << rhs._dreal << " - " << rhs._dimag * (-1) << "i" << endl;
	}
	return os;
}



Complex operator+(const Complex & lhs, const Complex & rhs)
{
	Complex tmp(lhs);
	tmp += rhs;
	return tmp;
}

int main(void)
{
	Complex c1(1, 2);
	cout << c1 << endl;

	cin >> c1;
	cout << c1 << endl;
	
	return 0;
}

