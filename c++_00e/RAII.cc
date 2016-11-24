 ///
 /// @file    RAII.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-04 16:47:41
 ///
 
#include <iostream>
using std::cout;
using std::endl;


template <typename T>
class RAII
{
public:
	explicit
	RAII(T * p) : _p(p)
	{
		cout << "RAII(T*)" << endl;
	}

	~RAII()
	{
		cout << "~RAII()" << endl;
		delete _p;
	}

	T * get() const
	{
		return _p;
	}

	T & operator*() const
	{
		return *_p;
	}

	T * operator->()
	{
		return _p;
	}

	void reset(T * p)
	{
		delete _p;
		_p = p;
	}

private:
	RAII(const RAII &);
	RAII & operator=(const RAII &);

private:
	T * _p;
};

class SomeResource
{
public:
	SomeResource()
	{
		cout << "SomeResource()" << endl;
	}

	~SomeResource()
	{
		cout << "~SomeResource()" << endl;
	}
private:
    //SomeResource (const SomeResource& rth);
};

class Example
{
public:
	Example()
	: _p1(new SomeResource())
	, _p2(new SomeResource())
	{
		cout << "Example()" << endl;
	}

	Example(const Example & rhs)
	: _p1(new SomeResource(*rhs._p1))
	, _p2(new SomeResource(*rhs._p2))
	{
		
	}

	Example & operator=(const Example & rhs)
	{
		if(this != & rhs)
		{
			*_p1 = *rhs._p1;
			*_p2 = *rhs._p2;
		}
		return *this;
	}

	~Example()
	{
		cout << "~Example()" << endl;
	}
private:
	RAII<SomeResource> _p1;
	RAII<SomeResource> _p2;
};

int main(void)
{
	Example e1;
	return 0;
}
