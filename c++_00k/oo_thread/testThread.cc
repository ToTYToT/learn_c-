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
using std::cout;
using std::endl;


class DerivedThread : public wd::Thread
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
	wd::Thread * pThread = new DerivedThread;
	pThread->start();
	pThread->join();
	return 0;
}
