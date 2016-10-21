 ///
 /// @file    io5.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-20 15:08:28
 ///
 
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
#if 0
int main(void)
{
	ifstream ifs("io1.cc");
	if(!ifs.good())
	{
		cout<<"no good"<<endl;
		return -1;
	}
#if 1
	string s1;
	while(ifs>>s1)
	{
		cout<<s1<<endl;
	}
#endif
	cout<<endl;

#if 1
	string s2;
	while(getline(ifs,s2))
	{
		cout<<s2<<endl;
	}
#endif

	ifs.close();
	return 0;
}
#endif
#if 0
int main()
{
	//持久化?
	ifstream ifs("io2.cc");//app模式能够在文件末尾添加新内容

	if(!ifs.good())
	{
		return -1;
	}
	ofstream ofs("test.txt");//不管文件是否存在都能正常输出
	if(!ofs.good())
	{
		ifs.close();
		return -1;
	}
	string s1;
	while(getline(ifs,s1))
	{
		ofs<<s1<<endl;
	}
}
#endif

int main()
{
	ifsteam fis("test.tst",std::ios::ate);
	if(!ifs.good())
	{
		cout<<endl;
		return -1;
	}
