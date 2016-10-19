 ///
 /// @file    the_1th.c
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-17 14:37:51
 ///
 
#include <stdlib.h> 
#include <iostream>
using std::cout;
using std::endl;

#define MAX 100 //简单的字符串的替换，
                //发生在预编译、预处理
                //没有类型检查

int test_1(void)
{
    const int a=1;
    //a=10;
    const int b;//常量的值必须进行初始化
    // int *pa=&a; 非const指针不能指向const变量
    const int *pa=*pa;//指针所指向的变量是常量，常量指针
                      //pointer to const
    //*pa=10; //Error
    cout <<"*pa"<<*pa<<endl;
    int const *pb=&a;//与21行效果类似
    cout<< "*pb="<<*pb<<endl;
    //int * const pc=&a;//
    int b=2;
    int * const pc=&b;//指针不能改变其指向
                      //const pointer
    //函数指针 指针函数 数组指针 指针数组
    int * paa=(int*)malloc(sizeof(int));
    *paa=100;
    cout <<"*pa="<<*paa<<endl;

    //malloc,free,为库函数，malloc只负责开辟空间，不完成初始化
    //new,delete，为表达式，在开辟空间之后,可直接初始化
    //名字改编
    //根据函数类型，个数，顺序
    //编译时，进行名字改编
    //
    //

}
extern "C"//以C的方式进行调用
{
    int add(int a,int b)
    {
        return a+b;
    }
}

int n_1(void)
{
    int *pa=new int(3);
    cout<<"*pa="<<*pa<<endl;
    delete pa;
    return 0;
}

int n_2(void)
{
    int a=100;
    int *pa=&a;
    *pa=10;

    int & refa=a;//reference a , another name of a;
    refa=1000;
    int &refb;//don't exist alone, must reference a int;
    //引用必须初始化
    //引用作为函数的参数
    //better 在参数进行传递时，就是直接操作实参本身，不需要开辟额外的空间
    //可以提升程序的执行效率
}

int arr[5]={1,2,3,4,5};
//引用作为函数的返回值，返回的变量（对象）本身一定要存在的
int & func(int idx)
{
    return arr[idx];
}


//don't 返回一个局部变量的引用
int & func_oo(void)
{
    int temp=1000;//temp为局部变量
    return temp;//当函数调用完成时，temp生命周期已结束
}
//不要轻易返回一个对空间变量或对象的引用
int &func3()
{
    int *pa=new int(3);
    return *pa;
}
int func_4(void)
{
    double d1=5.5;
    int i=static_cast<int>(d1);//强制转换
    // const_cast, dynamic_cat, reinterpret_cast
    //
}
int add_d(int a,int b=2)//缺省参数的赋值必须按照从右到左的顺序
{
    return a+b;
}

int add_d(int a,int b,int z=1)
{
    return a+b+z;
}
int main(void)
{
    func(0)=10;
    cout<<"arr[0]="<<arr[0]<<endl;
    func(10)=12;
    add_d(1,2);
  return 0;
    
}

