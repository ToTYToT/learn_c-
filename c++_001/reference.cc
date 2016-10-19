 ///
 /// @file    reference.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-17 15:11:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;


#if 0
void swap(int x, int y) // 行参要进行初始化
{
	int temp = x;
	x = y;
	y = temp;
}
#endif

void swap(int * px, int * py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}



//引用作为函数的参数
//好处：在参数进行传递时，就是直接操作实参本身，不需要开辟额外的空间
//可以提升程序的执行效率
void swap(int & refx, int & refy)
{//行参与实参进行结合时， int & refx = a; int & refy = b;
	int temp = refx;
	refx = refy;
	refy = temp;
}


int test(void)
{
	int a = 100;
	int * pa = &a;
	*pa = 10;

	int & refa = a;//引用,就是一个变量的别名
	refa = 1000;
	cout << "a = " << a << endl;
	cout << "refa = " << refa << endl;

	//int & refb;//引用不能单独存在，它一定要绑定到一个实体上去
	//引用必须要进行初始化
	
	int b = 11;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	swap(a,b);
	//swap(&a, &b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}

int arr[5] = {1, 2, 3, 4, 5};

//引用作为函数的返回值, 返回的变量(对象)本身一定要存在的
int & func(int idx)
{
	return arr[idx];
}

int * fun()
{
	int temp = 100;
	return &temp;
}

//不要返回一个局部变量的引用
int & func2()
{
	int temp = 100;//temp是一个局部变量,
				   //当函数调用完成时，temp的生命周期已经结束
	return temp;
}


//不要轻易返回一个堆空间变量或对象的引用
int & func3()
{
	int *pa = new int(3);
	return *pa;
}

int main(void)
{
	func(0) = 10;
	cout << "arr[0] = " << arr[0] << endl;

	cout << func2() << endl;
	int & ref1 = func3();
	cout << "ref1 = " << ref1 << endl;

	//delete (&ref1);//释放不够直观

	int a = 1;
	int b = 2;

	int c = a + b + func3();//func3代表一个匿名变量，直接造成内存泄漏
	cout << "c = " << c << endl;

	return 0;
}
