 ///
 /// @file    nest.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-25 11:41:52
 ///


#include "nest.h" 
#include <iostream>

using std::cout;
using std::endl;

class Line::LineImpl
{
private:
	class Point
	{
	public:
		Point(int ix = 0, int iy = 0)
		: _ix(ix)
		, _iy(iy)
		{
			//cout << "Point(int,int)" << endl;
		}

		void printPoint();
	private:
		int _ix;
		int _iy;
	};
public:
	LineImpl(int x1, int y1, int x2, int y2)
	: _pt1(x1, y1)
	, _pt2(x2, y2)
	{
	}
	void printLine()
	{
		_pt1.printPoint();
		cout << "----->";
		_pt2.printPoint();
		cout << endl;
	}
private:
	Point _pt1;
	Point _pt2;
};


void Line::LineImpl::Point::printPoint()
{
	cout << "(" << _ix
		 << "," << _iy
		 << ")";
}

Line::Line(int x1, int y1, int x2, int y2)
: _pImpl(new LineImpl(x1, y1, x2, y2))
{
	cout << "Line(int,int,int,int)" << endl;
}

Line::~Line()
{
	cout << "~Line()" << endl;
	delete _pImpl;
}


void Line::printLine()
{
	_pImpl->printLine();
}
