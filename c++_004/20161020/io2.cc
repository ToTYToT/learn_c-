 ///
 /// @file    io2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-20 15:08:14
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;


int test1(void)
{
	ifstream ifs("io1.cc");//打开文件流，要求文件必须能存在
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return -1;
	}

#if 0
	string s2;
	while(ifs >> s2)
	{
		cout << s2 << endl;
	}
#endif
	
	cout<< "000000000000000000000"<<endl;
	vector<string> vecStr;
	vecStr.reserve(100);

	string s1;
	while(getline(ifs, s1))
	{
		vecStr.push_back(s1);
		//cout << s1 << endl;
	}

	for(auto & elem : vecStr)
	{
		cout << elem << endl;
	}
	
	ifs.close();//关闭文件流
	return 0;
}

int test2(void)
{

	return 0;
}

int main(void)
{
	cout<<"test1"<<endl;
	test1();
	cout<<"hello"<<endl;
	ifstream ifs("io3.cc");
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return -1;
	}

	//持久化
	ofstream ofs("test.txt");//不管文件是否存在，都能正常输出
	if(!ofs.good())
	{
		cout << "ofstream open error!" << endl;
		ifs.close();
		return -1;
	}
	string s1;
	while(getline(ifs, s1))
	{
		ofs << s1 << endl;
	}

	ifs.close();
	ofs.close();

	return 0;
}
