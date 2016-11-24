 ///
 /// @file    testThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-15 11:05:08
 ///
 

#include "Thread.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::bind;


struct Foo
{
	void run()
	{
		::srand(time(NULL));
		while(1){
			int number = ::rand() % 100;
			cout << "number = " << number << endl;
			::sleep(1);
		}
	}
};


int main(void)
{
	wd::Thread * pThread = new wd::Thread(bind(&Foo::run, Foo()));
	pThread->start();
	pThread->join();
	return 0;
}
