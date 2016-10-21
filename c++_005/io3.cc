 ///
 /// @file    io3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-20 15:30:32
 ///
 
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;


int test1()
{
	//ofstream ofs("test.txt", std::ios::ate);
	ofstream ofs("test.txt", std::ios::app);//app模式能在文件末尾添加新内容
	if(!ofs.good())
	{
		cout << "ofstream open error!" << endl;
		return -1;
	}

	cout << ofs.tellp() << endl;
	ofs << "that's new!" << endl;

	ofs.close();

	return 0;
}

int test2()
{
	//ate模式只能用在文件输入流上
	ifstream ifs("test.txt", std::ios::ate);
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return -1;
	}

	cout << ifs.tellg() << endl;

	ifs.close();
	return 0;
}

int test3()
{
	fstream fs("f1.dat");//打开的文件必须存在
	if(!fs.good())
	{
		cout << "fstream open error!" << endl;
		return -1;
	}

	int ival;
	for(int idx = 0; idx != 10; ++idx)
	{
		cin >> ival;
		fs << ival << " ";//将数据写入文件
	}

	cout << fs.tellp() << endl;

	fs.seekp(0, std::ios::beg);
	cout << fs.tellp() << endl;

	for(int idx = 0; idx != 10; ++idx)
	{
		fs >> ival;//从文件中读取数据
		cout << ival << " ";
	}
	cout << endl;

	return 0;
}


int main(void)
{
	test3();

	return 0;
}
