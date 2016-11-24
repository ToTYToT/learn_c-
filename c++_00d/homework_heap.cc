 ///
 /// @file    homework_heap.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-02 09:10:52
//堆排序
//整理节点time:O(lgn)
#if 0
#include <iostream>
using std::cout;
using std::endl;
template<typename T>
void swap(T &a, T &b)
{
    T tmp;
    tmp=a;
    a=b;
    b=tmp;
}
template<typename T>
void MinHeapify(T*arry,int size,int element)
{
	int lchild=element*2+1,rchild=lchild+1;//左右子树
	while(rchild<size)//子树均在范围内
	{
		if(arry[element]<=arry[lchild]&&arry[element]<=arry[rchild])//如果比左右子树都小，完成整理
		{
			return;
		}
		if(arry[lchild]<=arry[rchild])//如果左边最小
		{
			swap(arry[element],arry[lchild]);//把左面的提到上面
			element=lchild;//循环时整理子树
		}
		else//否则右面最小
		{
			swap(arry[element],arry[rchild]);//同理
			element=rchild;
		}
		lchild=element*2+1;
		rchild=lchild+1;//重新计算子树位置
	}
	if(lchild<size&&arry[lchild]<arry[element])//只有左子树且子树小于自己
	{
		swap(arry[lchild],arry[element]);
	}
	return;
}
//堆排序time:O(nlgn)
	template<typename T>
void HeapSort(T*arry,int size)
{
	int i;
	for(i=size-1;i>=0;i--)//从子树开始整理树
	{
		MinHeapify(arry,size,i);
	}
	while(size>0)//拆除树
	{
		swap(arry[size-1],arry[0]);//将根（最小）与数组最末交换
		size--;//树大小减小
		MinHeapify(arry,size,0);//整理树
	}
	return;
}
int main(void)
{
    int arr[10]={1,2,3,4,5,6,7,8,9,0};
    HeapSort(arr,10);
    for(int i=0;i<10;++i)
{    cout<<arr[i]<<endl;}
    cout<<arr[9]<<endl;
}
#endif

#if 1
#include <iostream>
using std::cout;
using std::endl;
template<typename T>
void swap(T &a, T &b)
{
    T tmp;
    tmp=a;
    a=b;
    b=tmp;
}
template<typename T>
void MinHeapify(T*arry,int size,int element)
{
	int lchild=element*2+1,rchild=lchild+1;//左右子树
	while(rchild<size)//子树均在范围内
	{
		if(arry[element]>=arry[lchild]&&arry[element]>=arry[rchild])//如果比左右子树都小，完成整理
		{
			return;
		}
		if(arry[lchild]>=arry[rchild])//如果左边最小
		{
			swap(arry[element],arry[lchild]);//把左面的提到上面
			element=lchild;//循环时整理子树
		}
		else//否则右面最小
		{
			swap(arry[element],arry[rchild]);//同理
			element=rchild;
		}
		lchild=element*2+1;
		rchild=lchild+1;//重新计算子树位置
	}
	if(lchild<size&&arry[lchild]>arry[element])//只有左子树且子树小于自己
	{
		swap(arry[lchild],arry[element]);
	}
	return;
}
//堆排序time:O(nlgn)
	template<typename T>
void HeapSort(T*arry,int size)
{
	int i;
	for(i=size-1;i>=0;i--)//从子树开始整理树
	{
		MinHeapify(arry,size,i);
    for(int i=0;i<size;++i)
{    cout<<arry[i];}
        cout<<endl;
	}
    for(int i=0;i<size;++i)
{    cout<<arry[i];}
        cout<<endl;
	while(size>0)//拆除树
	{
		swap(arry[size-1],arry[0]);//将根（最小）与数组最末交换
		size--;//树大小减小
		MinHeapify(arry,size,0);//整理树
    for(int i=0;i<size;++i)
{    cout<<arry[i];}
        cout<<endl;
	}
	return;
}
int main(void)
{
    int arr[5]={4,9,6,8,0};
    HeapSort(arr,5);
    for(int i=0;i<5;++i)
{    cout<<arr[i];}
    cout<<endl;
}
#endif
