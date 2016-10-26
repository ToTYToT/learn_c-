 ///
 /// @file    operator_arrow.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-25 11:09:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Data
{
public:
	int length()
	{	return 5;}
};

class DataPtr
{
public:
	DataPtr()
	: _pData(new Data)
	{
	
	}

	~DataPtr()
	{
		delete _pData;
	}

	Data * operator->()
	{
		return _pData;
	}
private:
	Data * _pData;
};


int main(void)
{
	DataPtr dp;
	cout << dp->length() << endl;
	cout << (dp.operator->())->length() << endl;
}
