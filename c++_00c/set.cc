 ///
 /// @file    set.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-31 14:54:25
 ///
 
#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::ostream;
using std::set;


void display(set<int, std::greater<int> > & setInt)
{
	set<int>::iterator it = setInt.begin();
	for(; it != setInt.end();
		++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

class Point
{
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{}

	friend ostream & operator<<(ostream & os, const Point & rhs);
	friend bool operator<(const Point & lhs, const Point & rhs);
private:
	int _ix;
	int _iy;
};
ostream & operator<<(ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

//重载小于符号
#if 1
bool operator<(const Point & lhs, const Point & rhs)
{
	if(lhs._ix < rhs._ix)
		return true;
	else
		return false;
}
#endif

void display(set<Point> & setInt)
{
	set<Point>::iterator it = setInt.begin();
	for(; it != setInt.end();
		++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}


#if 0
struct less
{
public:
	bool operator()(const Point & lhs, const Point & rhs) const
	{
		if(lhs < rhs)
			return true;
		else 
			return false;
	}
};
#endif

int main(void)
{
	//set里面不能存放相同的关键字
	//默认情况下以升序对元素进行排列
	int arr[9] = {2, 1, 3, 5, 4, 6, 3, 5, 6};
	set<int, std::greater<int> > setInt(arr, arr + 9);

	cout << "setInt's size = " << setInt.size() << endl;
	display(setInt);
	//setInt[0];//Error,不支持下标运算符

	Point arrpoint[4] = {
		Point(1, 2),
		Point(5, 6),
		Point(3, 4),
		Point(7, 8)};

	//当自定义的类类型添加到关联容器中时,要定义排序函数
	set<Point> setPoint(arrpoint, arrpoint + 4);
	display(setPoint);
	
	
	return 0;

}
