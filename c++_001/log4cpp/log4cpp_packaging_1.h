/*************************************************************************
    > File Name: log4cpp_mylog.h
    > Author:ToTYToT
    > Mail: 240008250@QQ.COM
    > Created Time: Sun 23 Oct 2016 08:56:23 AM CST
 ************************************************************************/

 /// @file    log4cpp_mylog.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-23 08:56:23
 ///
 
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <iostream>
#include <string>
#include <sstream>


#define logWarn(msg)  (Mylogwarn(__FILE__,__func__,__LINE__,msg))

class Mylog;
int Mylogwarn(const char*filename,const char*function_name,unsigned line,const char *msg);
