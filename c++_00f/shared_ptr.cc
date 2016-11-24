 ///
 /// @file    shared_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-05 10:35:32
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

class Parent;

class Child
{
public:
	Child()
	{
		cout << "Child()" << endl;
	}

	~Child()
	{
		cout << "~Child()" << endl;
	}

	shared_ptr<Parent> _parentPtr;
};


class Parent
{
public:
	Parent()
	{
		cout << "Parent()" << endl;
	}

	~Parent()
	{
		cout << "~Parent()" << endl;
	}
	shared_ptr<Child> _childPtr;
};

int main(void)
{
	shared_ptr<Parent>  pParent(new Parent);
	shared_ptr<Child>  pChild(new Child);
	cout << "pParent's use_count = " << pParent.use_count() << endl;
	cout << "pChild's use_count = " << pChild.use_count() << endl;

	pParent->_childPtr = pChild;
	pChild->_parentPtr = pParent;
	cout << "pParent's use_count = " << pParent.use_count() << endl;
	cout << "pChild's use_count = " << pChild.use_count() << endl;

	return 0;
}
