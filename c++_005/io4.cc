 ///
 /// @file    io4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-21 10:16:37
 ///
 
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::stringstream;
using std::ostringstream;
using std::istringstream;
using std::string;
using std::ifstream;
using std::vector;


int test1(void)
{
	int ival = 512;
	int ival2 = 1024;
	stringstream ss;
	ss << "ival= " << ival << " ival2= " << ival2;

	//char buff[128];
	//sprintf(buff, "ival= %d ival2= %d\n", ival, ival2);

	string str = ss.str();//把缓冲区中的内容直接转换成字符串

	cout << str << endl;
	//cout << buff << endl;
	
	int num;
	while(!ss.eof())
	{
		ss >> str;
		ss >> num;
		cout << str << " "
			 << num << endl;
		cout << "ss.eof() = " << ss.eof() << endl;
	}
	return 0;
}


string int2str(int num)
{
	ostringstream oss;
	oss << num;
	return oss.str();
}

void test()
{
	ifstream ifs("io4.cc");
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return;
	}

	vector<string> vecStr;

	string line;
	int cnt = 10;
	while(cnt--)
	{
		getline(ifs, line);
		istringstream iss(line);
		string word;
		while(iss >> word)
		{
			vecStr.push_back(word);
		}
	}

	for(auto & elem : vecStr)
	{
		cout << elem << endl;
	}

	ifs.close();
}


int main(void)
{
	int num = 100;
	string s = int2str(num);
	cout << "s = " << s << endl;

	test();
	return 0;
}


