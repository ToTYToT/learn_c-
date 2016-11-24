 ///
 /// @file    tesc.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-23 23:37:17
 ///
#include "log4cpp_mylog.h" 
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    Mylog * p=Mylog::getInstance();
    logInfo("hello_world_I_love_you!");
    p->destroy();
}
