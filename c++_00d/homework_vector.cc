 ///
 /// @file    homework_vector.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-02 14:40:22
 ///
 
#include <iostream>
#include <memory>
#include <string>
using std::cout;
using std::endl;
using std::allocator;
using std::string;
template<typename T>
class Vector
{
public:
	Vector()
{
    _alloc;
    _elems=0;
    _end=0;
    _first_free=0;

}
	~Vector(){}

	void push_back(const T &t)
    {
        if(1==size())
        {
            _elems=_alloc.allocator((size_t)1);
            _alloc.construct(_elems,t);
            _first_free=_elems+1;
            _end=_first_free;
            return;
        }
        else if(capacity()-size()<1)
        {
            reallocate();
        }
            _alloc.construct(_first_free,t);
            ++_first_free;
        cout <<size()<<" "<<capacity()<<endl;
    }
	int size(){return _first_free-_elems;}
	int capacity(){return _end-_elems;}

	void reallocate()
    {
        int len=size();
        T * tmp=_alloc.allocate(size()*2);
        for(unsigned i=0;i<size();++i)
        {
            _alloc.construct(tmp+i,*(_elems+i));
            _alloc.destroy(_elems+i);
        }
        _alloc.deallocate(_elems,size());
        _elems=tmp;
        _first_free=_elems+len+1;
        _end=tmp+size()*2;
    }
    //重新分配内存,动态扩容要用的
private:
	static std::allocator<T> _alloc;
	T * _elems;   //指向数组中的第一个元素
	T * _end;        //指向数组本身之后的位置
	T * _first_free; //指向最后一个实际元素之后的那个元素
};
//typename Singleton<T>::AutoRelease Singleton<T>::_autoRelease;
template<typename T>
std::allocator<T> Vector<T>::_alloc;

int main(void)
{
    Vector<string> v;
    v.push_back("hello");
    cout<<v.size()<<" "<<v.capacity()<<endl;
    int i=0;
    while(i<10)
    {
    v.push_back("hello");
    cout<<v.size()<<" "<<v.capacity()<<endl;
    }

    cout<<v.size()<<" "<<v.capacity()<<endl;
}
