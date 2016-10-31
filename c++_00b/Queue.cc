 ///
 /// @file    Queue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-24 14:57:56
 ///
 
#include <iostream>

using std::cout;
using std::endl;


class Queue
{
public:
	Queue(int size)
	: _front(0)
	, _rear(0)
	, _size(size)
	, _arr(new int[_size])
	{
	
	}

	~Queue()
	{
		delete [] _arr;
	}

	bool empty()
	{
		return _front == _rear;
	}
	bool full()
	{
		return _front == (_rear + 1) % _size;
	}
	void push(int num)
	{
		if(!full())
		{
			_arr[_rear] = num;
			++_rear;
			_rear %= _size;
		}
		else
		{
			cout << "queue is full" << endl;
		}
	}
	void pop()
	{
		if(!empty())
		{
			++_front;
			_front %= _size;
		}
		else
		{
			cout << "queue is empty" << endl;
		}
	}
	int front()
	{
		if(!empty())
		{
			return _arr[_front];
		}
		else
		{
			cout << "queue is emtpy" << endl;
			return -1;
		}
	}
	int back()
	{
		if(!empty())
		{
			return _arr[(_rear - 1 + _size) % _size];
		}
		else
		{
			cout << "queue is empty" << endl;
			return -1;
		}
	}
private:
	int _front;
	int _rear;
	int _size;
	int * _arr;
};

int main(void)
{
    Queue queue(4);

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);

    cout << "对头元素：" << queue.front() << endl;
    cout << "对头元素出队" << endl;
    queue.pop();
    queue.push(4);

    cout << "对尾元素:" << queue.back() << endl;
}
