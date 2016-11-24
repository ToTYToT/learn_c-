 ///
 /// @file    testThreadpool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-16 11:23:07
 ///
 
#include "Threadpool.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>
#include <functional>
using std::cout;
using std::endl;
using std::shared_ptr;

class Producer
{
public:
	void execute(){
		::srand(::time(NULL));
		int number = ::rand() % 100;
		cout << "produce a number: " << number << endl;
		sleep(1);
	}
};


int main(void)
{
	wd::Threadpool threadpool(4, 10);
	threadpool.start();
	int cnt = 20;
	std::function<void()> task = std::bind(&Producer::execute, Producer());
	while(cnt > 0)
	{
		threadpool.addTask(task);
		//sleep(1);
		cout << "-----cnt = " << cnt << endl;
		--cnt;
	}
	threadpool.stop();
	return 0;
}
