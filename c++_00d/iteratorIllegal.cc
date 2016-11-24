 ///
 /// @file    iteratorIllegal.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-01 11:29:16
 ///
 
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;


int main(void)
{
	vector<string> vecStr;
	vecStr.push_back("this is A");
	auto it = vecStr.begin();
	bool flag = true;
	for(; it != vecStr.end(); ++it)
	{   //当执行完第二次push_back操作之后,it已经失效了
		cout << "vecStr's size = " << vecStr.size() << endl;
		cout << *it << endl;//第二次进行访问时,会发生段错误
		if(flag)
		{
			//执行push_back操作之后,vecStr进行扩容
			vecStr.push_back("this is B");
			cout << "vecStr.push " << endl;
			flag = false;
		}
	}
	return 0;
}
