 ///
 /// @file    testPc.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-15 16:00:28
 ///
 
#include "Thread.h"
#include "Buffer.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::bind;


struct Producer
{
	void produce(wd::Buffer & buffer)
	{
		::srand(time(NULL));
		while(1)
		{
			int number = ::rand() % 100;
			buffer.push(number);
			cout << "produce a number: " << number << endl;
			::sleep(1);
		}
	}
};


struct Consumer
{
	void consume(wd::Buffer & buffer)
	{
		while(1)
		{
			int number = buffer.pop();
			cout << "----consume a number: " << number << endl;
			sleep(2);
		}
	}
};


int main(void)
{
	wd::Buffer buffer(10);
	Producer producer;
	Consumer consumer;
	//bind是值传递,如果直接传递buffer对象，是会进行复制的；
	//但是Buffer类对象是不能进行复制的
	//wd::Thread producerThread(
	//		bind(&Producer::produce, &producer, std::ref(buffer)));
	//wd::Thread consumerThread(
	//		bind(&Consumer::consume, &consumer, std::ref(buffer)));
	wd::Thread producerThread(
			bind(&Producer::produce, &producer, &buffer));
	wd::Thread consumerThread(
			bind(&Consumer::consume, &consumer, &buffer));
	producerThread.start();
	consumerThread.start();
	
	producerThread.join();
	consumerThread.join();
	return 0;
}

