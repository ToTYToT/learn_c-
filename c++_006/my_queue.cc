 ///
 /// @file    my_queue.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-23 10:47:58
 ///
 
#include <iostream>
using std::cout;
using std::endl;

#if 0
5. 编写一个类，实现简单的队列。队列中有以下操作：
> 元素入队             void push(int);
> 元素出队             void pop();
> 读取队头元素         int front();
> 读取队尾元素         int back();
> 判断队列是否为空     bool emty();
> 判断队列是否已满     bool full();

#endif

class my_queue
{
public:
    my_queue();
	void push(int member);
    void pop();
    int front();
    int back();
    bool empty();
    bool full();
private:
	int _head=0;
	int _tail=0;
	int _the_queue_arr[10]={0};
};
my_queue::my_queue()
:_head(1)
{
    cout<<_head<<endl;
}
void my_queue::push(int member)
{
	cout<<__func__<<" "<<__LINE__<<endl;
	if(full())//full() is full return 1
		return;
	_the_queue_arr[(_tail+10)%10]=member;//top=0 is empty,top=9 is full
    _tail=((++_tail)+10)%10;
}
void my_queue::pop()
{
	cout<<__func__<<" "<<__LINE__<<endl;
	if(empty())//empty() is empty return 1
		return;
	cout<<"num="<<_the_queue_arr[(_head+10)%10]<<endl;
	_head=((_head--)+10)%10;
}
int my_queue::front()
{
	cout<<__func__<<" "<<__LINE__<<endl;
	//if(full())//full() is full return 1
	if(!empty())
	return  _the_queue_arr[_head];
}
int my_queue::back()
{
	cout<<__func__<<" "<<__LINE__<<endl;
	//if(full())//full() is full return 1
	if(!empty())
	return  _the_queue_arr[_tail];
}
bool my_queue::full()
{
	cout<<__func__<<" "<<__LINE__<<endl;
	if((++_tail)==_head)
	{
		--_tail;
		return 1;
	}
	return 0;
}
bool my_queue::empty()
{
	cout<<__func__<<" "<<__LINE__<<endl;
	if((++_head)==_tail)
	{
		--_head;
		return 1;
	}
	return 0;
}

int main(void)
{
	cout<<__func__<<" "<<__LINE__<<endl;
	my_queue ppp;
    int i=10;
    while(i--)
    {
    	ppp.push(i);
        cout<<ppp.back()<<endl;
       // cout<<ppp,front()<<endl;
    }

	ppp.pop();
}
