 ///
 /// @file    test.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-13 17:29:38
 ///
#include <iostream> 
#include <string>
#include "node.h"
#include "parser.h"
#include "scanner.h"

int main()
{
    std::string c;
    while(1){
        std::cin>>c;
        Scanner a(c);
    Parser b(a);
	b.Parse();
    std::cout<<b.Calculate();
    }
}
