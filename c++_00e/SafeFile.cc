 ///
 /// @file    SafeFile.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-04 16:18:49
 ///
 
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ofstream;


class SafeFile
{
public:
	SafeFile(const char * filename)
	: _pfileHandler(fopen(filename, "w+"))
	{
		cout << "SafeFile(const char *)" << endl;
		if(nullptr == _pfileHandler)
		{
			cout << "open file " << filename << " error!" << endl;
		}
	}

	void write(const char * str)
	{
		if(fputs(str, _pfileHandler) == EOF)
		{
			cout << "write error!" << endl;
		}
	}

	void write(const char * buff, int size)
	{
		if(fwrite(buff, 1, size, _pfileHandler) == 0)
		{
			cout << "write error!" << endl;
		}
	}


	~SafeFile()
	{
		if(_pfileHandler)
			fclose(_pfileHandler);
		cout << "~SafeFile()" << endl;
	}

private://禁止复制: 通过语法规则表达语义
	SafeFile(const SafeFile &);
	SafeFile & operator=(const SafeFile &);

private:
	FILE * _pfileHandler;
};


int test(void)
{
	SafeFile sf("test.txt");

	//SafeFile sf1(sf);//Error，要求：该语句不能编译通过

	SafeFile sf2("test2.txt");
	//sf2 = sf;//Error

	sf.write("hello,world");

	return 0;
}

int main(void)
{	//能够进行复制的语义　--> 值语义
	//C++输入输出流对象都不能进行复制 --> 对象语义
	//C++天生支持值语义  --  Java语言天生支持对象语义
    test();	
    ofstream ofs1("test.txt");
	ofstream ofs2("test2.txt");
	//ofs2 = ofs1;

	//ofstream ofs3(ofs1);
}

