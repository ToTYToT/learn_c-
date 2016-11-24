 ///
 /// @file    THE_RUN_OF_INFO.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-22 14:33:40
 ///
#ifndef __THE_INFO_OF_RUN_H__
#define _THE_INFO_OF_RUN_H__
#if 0
#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                "<<__func__<<"    "<<__FILE__<<"-->"<<__LINE__<<std::endl)
#endif 
#if 0
#include <stdio.h>
#define THE_INFO_OF_RUN (printf("%-10s(%-3d)-<%-10s>:\n ",__FILE__, __LINE__, __func__)) 
#endif
#if 1
#include <stdio.h>
#define THE_INFO_OF_RUN (printf("\t%-30s  %s(%d)\n ",__func__, __FILE__,__LINE__)) 
#endif
#endif
