 ///
 /// @file    test.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-08 22:57:10
 ///
 
#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                FILE:"<<__FILE__<<" LINE:"<<__LINE__<<endl)
using std::cout;
using std::endl;
class A
{};
class B: public A
{};

int main(void)
{
    A &a=new B();
}
