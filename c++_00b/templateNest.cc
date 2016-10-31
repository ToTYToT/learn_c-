 ///
 /// @file    templateNest.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-29 11:21:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#if 0
template <typename T1, typename T2>
class Convert
{
public:
	T2 f(T1 data)
	{
		return T2(data);
	}
};
#endif

template <typename T1>
class Convert
{
public:
	//成员函数本身是一个函数模板
	template <typename T2>
	T2 f(T1 data);
#if 0
	{
		return T2(data);
	}
#endif
};

template <typename T1>
template <typename T2>
T2 Convert<T1>::f(T1 data)
{
	return T2(data);
}

int main(void)
{
	//Convert<double, int> convert;
	//cout << convert.f(3.3) << endl;
	Convert<double> convert;
	cout << convert.f<int>(3.3) << endl;

	return 0;
}
