 ///
 /// @file    push_pop.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-23 10:15:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class push_pop
{
public:
    void push(int member);
    void pop();
    int  top();
    bool empty();
    bool full();
private:
	int _the_heap_arr[10]={0};
	int _top=0;
};

void push_pop::push(int member)
{
	cout<<__func__<<" "<<__LINE__<<endl;
	if(full())//full() is full return 1
		return;
	_the_heap_arr[++_top]=member;//top=0 is empty,top=9 is full
}
void push_pop::pop()
{
	cout<<__func__<<" "<<__LINE__<<endl;
	if(empty())//empty() is empty return 1
		return;
	cout<<"num="<<_the_heap_arr[_top--]<<endl;
}
int push_pop::top()
{
	cout<<__func__<<" "<<__LINE__<<endl;
	if(full())//full() is full return 1
	if(!empty())
	return  _the_heap_arr[_top];
}
bool push_pop:: empty()
{
	cout<<__func__<<" "<<__LINE__<<endl;
	if(0==_top)
		return 1;
	return 0;
}
bool push_pop::full()
{
	cout<<__func__<<" "<<__LINE__<<endl;
	if(9==_top)
		return 1;
	return 0;
}
int main(void)
{
	cout<<__func__<<" "<<__LINE__<<endl;
	push_pop ppp;
	ppp.push(10);
	ppp.push(11);
	ppp.push(12);
	ppp.push(13);
	int num;
	num=ppp.top();
	cout<<num<<endl;
	ppp.pop();
	num=ppp.top();
	cout<<num<<endl;
	ppp.pop();
	num=ppp.top();
	cout<<num<<endl;
	ppp.pop();
	num=ppp.top();
	cout<<num<<endl;
	ppp.pop();
	num=ppp.top();
	cout<<num<<endl;
	ppp.pop();
	ppp.pop();
}
