 ///
 /// @file    testThreadpool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-16 11:23:07
 ///
 
#include "Threadpool.h"
#include "Task.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

class Mytask : public wd::Task
{
public:
	void execute(){
		::srand(::time(NULL));
		int number = ::rand() % 100;
		cout << "produce a number: " << number << endl;
	}
};


int main(void)
{
	shared_ptr<wd::Task> sp(new Mytask);
	wd::Threadpool threadpool(4, 10);
	threadpool.start();
	int cnt = 20;
	while(cnt > 0)
	{
		threadpool.addTask(sp.get());
		sleep(1);
		cout << "-----cnt = " << cnt << endl;
		--cnt;
	}
	threadpool.stop();
	return 0;
}
