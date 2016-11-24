 ///
 /// @file    Task.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-16 10:58:24
 ///
 
#ifndef __WANGDAO_TASK_H__
#define __WANGDAO_TASK_H__

#include "THE_INFO_OF_RUN.h" 
#include <functional>

namespace wd
{
typedef std::function<void()> Task;
}// end of namespace wd



#endif
