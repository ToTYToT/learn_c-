 ///
 /// @file    new.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-17 15:03:16
 ///
 
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

//  malloc/free是库函数， malloc只负责开辟空间，并不完成初始化  
//	
//  new/delete是表达式，在开辟空间之后，就可以进行初始化

int test(void)
{
	int * pa = (int *)malloc(sizeof(int));
	*pa = 100;
	cout << "*pa = " << *pa << endl;

	free(pa);
	return 0;
}


int main(void)
{
	int * pa = new int(3);
	cout << "*pa = " << *pa << endl;
	delete pa;


	int * pb = new int[10]();//开辟的是一个数组
	for(int i = 0; i != 10; ++i)
	{
		cout << pb[i] << endl;
	}

	delete [] pb;
	return 0;
}
