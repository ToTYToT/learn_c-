#include <iostream>
using std::cout;
using std::endl;


class Stack
{
	public:
	Stack(int size)
	: _size(size)
	, _top(-1)
	, _arr(new int[_size])
	{
	}
	~Stack()
	{
		delete [] _arr;_arr;
	}

	bool empty()
	{
		return _top == -1;
	}
	bool full()
	{
		return _top == _size - 1;
	}
	void push(int num)
	{
		if(!full())
		{
			_arr[++_top] = num;
		}
		else
		{
			cout << "stack is full" << endl;
		}
	}
	void pop()
	{
		if(!empty())
		{
			--_top;
		}
		else
		{
			cout << "stack is empty" << endl;
		}
	}

	int top()
	{
		if(!empty())
		{
			return _arr[_top];
		}
		else
		{
			cout << "stack is empty" << endl;
			return -1;
		}
	}

private:
	int _size;
	int _top;
	int * _arr;
};


int main(void)
{
	Stack stack(10);
	stack.push(10);
	stack.push(11);
	stack.push(12);
	stack.push(13);
	stack.push(14);
	stack.push(15);
	stack.push(16);
	stack.push(17);
	stack.push(18);
	stack.push(19);
	stack.push(20);

	cout << "栈顶元素是" << stack.top() << endl;
	stack.pop();

	while(!stack.empty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}

	return 0;
}

