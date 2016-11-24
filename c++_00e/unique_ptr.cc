 ///
 /// @file    unique_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-04 17:25:20
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

unique_ptr<int> getValue()
{
    cout<<"unique_ptr"<<endl;
	unique_ptr<int> up(new int(88));
	return up;
}

int main(void)
{
    int * ppppppppppp=getValue();
	double *pd = new double(6.66);
	unique_ptr<double> ap(pd);
	cout << "*ap = " << *ap << endl;
	cout << "*pd = " << *pd << endl;
	cout << "pd = " << pd << endl;
	cout << "ap.get() = " << ap.get() << endl;
	cout << endl;

	unique_ptr<int> up(new int(5));
    cout<<"up.get()="<<up.get()<<endl;
	//unique_ptr<int> up2(up);//不能进行复制,独享所有权的智能指针
	
	unique_ptr<int> up2 = getValue();//执行了unique_ptr的移动构造函数
	cout << "*up2 = " << *up2 << endl;


	vector<unique_ptr<int> > vec;
	//vec.push_back(up2);//Error
	vec.push_back(std::move(up2));//将unique_ptr对象转换成右值,再去使用

	return 0;
}
