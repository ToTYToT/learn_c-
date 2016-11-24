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

#define THE_INFO_OF_RUN (std::cout<<"    FILE:"<<__FILE__<<"    function:"<<__func__<<"    LINE:"<<__LINE__<<endl)

class Mytask : public wd::Task
{
public:
	void execute(){
        THE_INFO_OF_RUN;
		::srand(::time(NULL));
		int number = ::rand() % 100;
		cout << "produce a number: " << number << endl;
	}
};

class ytask : public wd::Task
{
public:
	void execute(){
        THE_INFO_OF_RUN;
		::srand(::time(NULL));
		int number = ::rand() % 100;
		cout << "produce  number: " << number << endl;
	}
};

int main(void)
{
	shared_ptr<wd::Task> sp(new Mytask);
	shared_ptr<wd::Task> s(new ytask);
	//wd::Threadpool threadpool(2, 2);
	wd::Threadpool threadpool(2, 2);
	threadpool.start();
	int cnt = 4;
	while(cnt > 0)
	{
		threadpool.addTask(sp.get());
//		threadpool.addTask(s.get());
		sleep(1);
		cout << "-----cnt = " << cnt << endl;
		--cnt;
	}
	threadpool.stop();
	return 0;
}
