 ///
 /// @file    deleter.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-05 11:52:21
 ///
 
#include <stdio.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;
using std::string;
using std::vector;


struct Fpcloser
{
	void operator()(FILE * fp)
	{
		if(fp)
		{
			fclose(fp);
			cout << "close FILE pointer " << endl;
		}
	}
};


class X
{
public:
	X()
	{	cout << "X()" << endl;}
	~X()
	{	cout << "~X()" << endl;	}
};

int test1(void)
{
	shared_ptr<FILE> sp(fopen("test.txt", "w+"), Fpcloser());
	string msg = "message";
	fwrite(msg.c_str(), 1, msg.size(), sp.get());

	return 0;
}

int test2(void)
{
	unique_ptr<FILE, Fpcloser> up(fopen("test2.txt", "w+"), Fpcloser()); 
	string msg = "message";
	fwrite(msg.c_str(), 1, msg.size(), up.get());

	return 0;
}

int main(void)
{
    test1();
    test2();
	//vector<int *> vec;
	//vec.push_back(new int(66));
	vector<shared_ptr<X> > vec;
	vec.push_back(shared_ptr<X>(new X));

	return 0;
}
