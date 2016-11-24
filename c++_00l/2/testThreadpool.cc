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
#include <functional>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::bind;

#define THE_INFO_OF_RUN (std::cout<<"    FILE:"<<__FILE__<<"    function:"<<__func__<<"    LINE:"<<__LINE__<<endl)

//class Mytask : public wd::Task
//{
//public:
//	void execute(){
//        THE_INFO_OF_RUN;
//		::srand(::time(NULL));
//		int number = ::rand() % 100;
//		cout << "produce a number: " << number << endl;
//	}
//};

struct Mytask
{
	public:
		void execute(){
			THE_INFO_OF_RUN;
			::srand(::time(NULL));
		while(1)
		{
			int number = ::rand() % 100;
//			buffer.push(number);
			cout << "produce a number: " << number << endl;
			::sleep(1);
		}
	}
};

int main(void)
{
	Mytask t;
	wd::Task sp(bind(&Mytask::execute,&t));
	//shared_ptr<wd::Task> sp(new Mytask);
	wd::Threadpool threadpool(2, 4);
	threadpool.start();
	int cnt = 2;
	while(cnt > 0)
	{
		//threadpool.addTask(sp.get());
		threadpool.addTask(&sp);
		sleep(1);
		cout << "-----cnt = " << cnt << endl;
		--cnt;
	}
	threadpool.stop();
	return 0;
}
