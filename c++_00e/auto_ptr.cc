 ///
 /// @file    auto_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-04 17:19:06
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::auto_ptr;


int main(void)
{
	double *pd = new double(6.66);
	auto_ptr<double> ap(pd);

	cout << "*ap = " << *ap << endl;
	cout << "*pd = " << *pd << endl;
	cout << "pd = " << pd << endl;
	cout << "ap.get() = " << ap.get() << endl;
	cout << endl;


	auto_ptr<int> api(new int(5));
	auto_ptr<int> api2(api);//auto_ptr能够进行复制，发生了所有权的转移
							//auto_ptr存在缺陷
	cout << "*api2 = " << *api2 << endl;
	cout << "*api = " << *api << endl;

	return 0;
}
