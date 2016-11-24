 ///
 /// @file    testPC.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-15 15:09:07
 ///

#include "Thread.h" 
#include "Buffer.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;


class Producer : public wd::Thread
{
public:
	Producer(wd::Buffer & buffer)
	: _buffer(buffer)
	{}
private:
	void run(){
		::srand(time(NULL));
		while(1)
		{
			int number = ::rand() % 100;
			_buffer.push(number);
			cout << "ThreadId:" << pthread_self() << ":Produce a number: " << number << endl;
			sleep(2);
		}
	}
private:
	wd::Buffer & _buffer;
};


class Consumer : public wd::Thread
{
public:
	Consumer(wd::Buffer & buffer)
	: _buffer(buffer)
	{}
private:
	void run()
	{
		while(1)
		{
			int number = _buffer.pop();
		
			cout << "ThreadId:" << pthread_self() << ":Consume a nubmer: " << number << endl;
			sleep(1);
		}
	}
private:
	wd::Buffer & _buffer;
};

int main(void)
{
	wd::Buffer buffer(10);

	wd::Thread * pProduct = new Producer(buffer);
	wd::Thread * pConsume = new Consumer(buffer);

	pProduct->start();
	pConsume->start();
	pProduct->join();
	pConsume->join();

	return 0;
}
