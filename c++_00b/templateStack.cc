 ///
 /// @file    templateStack.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-29 11:00:37
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//类模板参数可以给默认值(缺省值)
//但是函数模板不可以
template <typename T, int SIZE = 10>
class Stack
{
public:
	Stack()
	: _top(0)
	{
	}

	bool empty()const ;
	bool full()const;
	bool push(const T & t);
	bool pop(T & t);
	
	T top() const;

private:
	int _top;
	T _arr[SIZE];
};

//如果成员函数要在类模板之外进行定义,
//必须要加上模板参数列表
template <typename T, int SIZE>
bool Stack<T, SIZE>::empty() const
{
	return _top == 0;
}

template <typename T, int SIZE>
bool Stack<T, SIZE>::full() const
{
	return _top == SIZE;
}

template <typename T, int SIZE>
bool Stack<T, SIZE>::push(const T & t)
{
	if(!full())
	{
		_arr[_top++] = t;
		return true;
	}
	else
		return false;
}

template <typename T, int SIZE>
bool Stack<T, SIZE>::pop(T & t)
{
	if(!empty())
	{
		--_top;
		t = _arr[_top];
		return true;
	}
	else 
		return false;
}

template <typename T, int SIZE>
T Stack<T, SIZE>::top() const
{
	return _arr[_top - 1];
}


int main(void)
{
	//vector<int> vecInt;
	Stack<int> stack;
	cout << "开始时stack是否为空?" << stack.empty() << endl;
	stack.push(5);
	cout << "此时stack是否为空?" << stack.empty() << endl;

	for(int idx = 1; idx != 10; ++idx)
	{
		stack.push(idx);
	}
	cout << "此是stack是否已满?" << stack.full() << endl;

	int value;
	while(stack.pop(value))
	{
		cout << value << " ";
	}
	cout << endl;
	cout << "此时stack是否为空?" << stack.empty() << endl;

	return 0;

}
