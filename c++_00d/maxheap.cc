/*************************************************************************
    > File Name: maxheap.h
    > Author:ToTYToT
    > Mail: 240008250@QQ.COM
    > Created Time: Tue 01 Nov 2016 10:07:08 PM CST
 ************************************************************************/

 /// @file    maxheap.h
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-01 22:07:08
 ///
 
#define DefaultSize 10;
template <class T, class E>
struct Element{
    T key;
    field otherdata;
    Element<T,E>&operator = (Element <T,E> &x)
    { key = x.key; otherdata= x.otherdata;}
    bool operator>=(Element<T,E>&x){return key >=x.key;}
    bool operator<(Element<T,E>&x){return key<x.key;}
};
template<class T,class E>
class MaxHeap{
public:
    MaxHeap(int sz=DefaultSize);
    MaxHeap(Element<T,E>arr[],int n);
    ~MaxHeap(){delete[]heap;}
    int Remove(Element <T,E>&x);
    bool IsEmpty()const{return currentSize==0;}
    bool IsFull()const{return currentSize==maxHeapSize;}
private:
    Element<T,E> *heap;
    int currentSize;
    int maxHeapSize;
    void siftDown(int start, int m);
    void siftUp(int start);
    Swap(const int i,const int j)
    {Element<T,E> tmp=heap[i];heap[i]=heap[j];heap[j]=tmp;}
};
    int main(void)
    {}
