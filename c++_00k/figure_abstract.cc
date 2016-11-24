 ///
 /// @file    abstract.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-05-09 10:05:25
 ///
 
#include <math.h>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;
using std::bind;

const float PI = 3.14159f;

//基于对象的编程方式 -- 封装，组合
//代码复用时使用组合，不使用继承
class Figure
{
public:
	typedef function<float()> AreaCallback;
	typedef function<void()> DisplayCallback;
public:
	Figure(AreaCallback cb1, DisplayCallback cb2)
	: _areaCallback(cb1)
	, _printCallback(cb2)
	{}

	float runAreaCallback()
	{
		if(_areaCallback)
			return _areaCallback();
		else
			return 0;
	}

	void runDisplayCallback()
	{
		if(_printCallback)
			_printCallback();
	}

	void setAreaCallback(AreaCallback cb)
	{	_areaCallback = cb;	}
	void setDisplayCallback(DisplayCallback cb)
	{	_printCallback = cb;	}
private:
	//回调函数 -- 函数名本身也变成了变量
	AreaCallback _areaCallback;//函数的入口地址不确定,
	DisplayCallback _printCallback;//函数的调用时机也不确定
};


class Circle
{
public:
	Circle(float fRadius)
	: _fRadius(fRadius)
	{}

	float area()
	{
		return PI * _fRadius * _fRadius;
	}

	void print()
	{
		cout << "圆:";
	}
	
private:
	float _fRadius;
};

class Rectangle
{
public:
	Rectangle(int a, int b)
	: _ia(a)
	, _ib(b)
	{}

	float rectArea()
	{
		return _ia * _ib;
	}

	void rectPrint()
	{
		cout << "矩形:";
	}
	
private:
	int _ia;
	int _ib;
};

class Triangle
{
public:
	Triangle(float a, float b, float c)
	: _ia(a)
	, _ib(b)
	, _ic(c)
	{}

	float triangleArea()
	{
		float p = (_ia + _ib + _ic)/2;
		return sqrt(p *(p -_ia) * (p - _ib) * (p - _ic));
	}

	void trianglePrint()
	{
		cout << "三角形:";
	}
	
private:
	float _ia;
	float _ib;
	float _ic;
};

#if 0
void test(Figure * pFig)
{
	pFig->print();
	cout << pFig->area() << endl;
}
#endif


int test0(void)
{
	Circle circle(5);
#if 0
	Rectangle rectangle(3, 4);
	Triangle triangle(3,4,5);

	test(&circle);
	test(&rectangle);
	test(&triangle);
#endif

#if 0
	Figure * pFig = &circle;
	pFig->print();
	cout << pFig->area() << endl;

	pFig = &rectangle;
	pFig->print();
	cout << pFig->area() << endl;

	pFig = &triangle;
	pFig->print();
	cout << pFig->area() << endl;
#endif

	return 0;
}


int main(void)
{
	Circle circle(5);
	Figure fig(bind(&Circle::area, &circle), 
			   bind(&Circle::print, &circle));

	fig.runDisplayCallback();
	cout << fig.runAreaCallback() << endl;
	cout << endl;


	Rectangle rectangle(3, 4);
	Triangle triangle(3, 4, 5);

	//注册回调函数
	fig.setAreaCallback(bind(&Rectangle::rectArea, &rectangle));
	fig.setDisplayCallback(bind(&Rectangle::rectPrint, &rectangle));
	fig.runDisplayCallback();
	cout << fig.runAreaCallback() << endl;
	cout << endl;

	fig.setAreaCallback(bind(&Triangle::triangleArea, &triangle));
	fig.setDisplayCallback(bind(&Triangle::trianglePrint, &triangle));
	fig.runDisplayCallback();
	cout << fig.runAreaCallback() << endl;

	return 0;
}
