 ///
 /// @file    shared_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-04 17:25:20
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::vector;


int main(void)
{
	double *pd = new double(6.66);
	shared_ptr<double> ap(pd);

	cout << "*ap = " << *ap << endl;
	cout << "*pd = " << *pd << endl;
	cout << "pd = " << pd << endl;
	cout << "ap.get() = " << ap.get() << endl;
	cout << endl;

	shared_ptr<int> up(new int(5));
	cout << "up's use_count = " << up.use_count() << endl;
	cout << endl;

	vector<shared_ptr<int> > vec;
	vec.push_back(up);
	cout << "up's use_count = " << up.use_count() << endl;

	shared_ptr<int> up0(up);
	cout << "up0's use_count = " << up0.use_count() << endl;
	return 0;
}
