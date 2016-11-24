 ///
 /// @file    Vector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-04 10:12:34
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::allocator;

class Point
{
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

private:
	int _ix;
	int _iy;
};

template <typename T>
class Vector
{
public:
	Vector();
	~Vector();

	void push_back(const T & value);
	void pop_back();

	size_t size()
	{	return _first_free - _elems;	}
	size_t capacity()
	{	return _end - _elems;	}

private:
	void reallocate();

private:
	static std::allocator<T> _alloc;
	T * _elems;
	T * _first_free;
	T * _end;
};

template <typename T>
allocator<T> Vector<T>::_alloc;

template <typename T>
Vector<T>::Vector()
: _elems(nullptr)
, _first_free(nullptr)
, _end(nullptr)
{}

template <typename T>
Vector<T>::~Vector()
{
	while(_first_free != _elems)
		_alloc.destroy(--_first_free);

	_alloc.deallocate(_elems, capacity());
}

template <typename T>
void Vector<T>::reallocate()
{
	size_t sz = size();//原来元素的大小
	size_t newCap = 2 * (sz > 1 ? sz : 1);

	T * ptmp = _alloc.allocate(newCap);//开辟空间
	if(_elems != nullptr)
	{
		std::uninitialized_copy(_elems, _first_free, ptmp);//先复制原来的元素

		while(_first_free != _elems)
			_alloc.destroy(--_first_free);
		_alloc.deallocate(_elems, sz);
	}

	_elems = ptmp;
	_first_free = _elems + sz;
	_end = _elems + newCap;
}


template <typename T>
void Vector<T>::push_back(const T & value)
{
	if(size() == capacity())
	{
		reallocate();
	}
	_alloc.construct(_first_free, value);
	++_first_free;
}

template <typename T>
void Vector<T>::pop_back()
{
	if(size())
	{
		_alloc.destroy(--_first_free);
	}
}


int test(void)
{
	Vector<int> vecInt;
	vecInt.push_back(1);
	cout << "size = " << vecInt.size() << endl;
	cout << "cap  = " << vecInt.capacity() << endl;

	vecInt.push_back(2);
	cout << "size = " << vecInt.size() << endl;
	cout << "cap  = " << vecInt.capacity() << endl;
	
	vecInt.push_back(3);
	cout << "size = " << vecInt.size() << endl;
	cout << "cap  = " << vecInt.capacity() << endl;
	return 0;
}

int main(void)
{
	Vector<Point> vecPoint;
	vecPoint.push_back(Point(1, 2));
	cout << "size = " << vecPoint.size() << endl;
	cout << "cap  = " << vecPoint.capacity() << endl;
	vecPoint.push_back(Point(1, 2));
	cout << "size = " << vecPoint.size() << endl;
	cout << "cap  = " << vecPoint.capacity() << endl;
	vecPoint.push_back(Point(1, 2));
	cout << "size = " << vecPoint.size() << endl;
	cout << "cap  = " << vecPoint.capacity() << endl;
	vecPoint.push_back(Point(1, 2));
	cout << "size = " << vecPoint.size() << endl;
	cout << "cap  = " << vecPoint.capacity() << endl;
	vecPoint.push_back(Point(1, 2));
	cout << "size = " << vecPoint.size() << endl;
	cout << "cap  = " << vecPoint.capacity() << endl;

	return 0;
}
