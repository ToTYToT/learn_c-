 ///
 /// @file    homework_vector.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-04 22:29:12
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

template <typename T>
class Vector
{
public:
    Vector();
    ~Vector();
    //Vector(const Vector & rth);
    //Vector & operator = (const Vector &rth);
    unsigned size(){return _first_free-_elem;}
    unsigned capacity(){return _end-_elem;}
    //void realloc();
    //T*& push();
    void push(const T &);
    //void pop(){_alloc.destroy(--_first_free);}
    void pop()
    {
        if(size())
        {
            _alloc.destroy(--_first_free);
        }
    }
private:
    void reallocate();    
private:
    //std::allocator<T> _alloc;
    static std::allocator<T> _alloc;
    T * _elem;
    T * _first_free;
    T * _end;
};

template <typename T>
std::allocator<T> Vector<T>::_alloc;
template <typename T>
Vector<T>::Vector()
:_elem(nullptr)
,_first_free(nullptr)
,_end(nullptr)
{}
template <typename T>
Vector<T>::~Vector()
{
    while(_first_free!=_elem)
        _alloc.destroy(--_first_free);
    _alloc.deallocate(_elem,capacity());
}
template <typename T>
void Vector<T>::push(const T & rth)
{
    if(size()==capacity())
        reallocate();
    _alloc.construct(_first_free,rth);
    ++_first_free;
}
#if 0
template <typename T>
void Vector<T>::reallocate()
{
    unsigned sz = size();
    unsigned newCap = 2 * (sz > 1 ? sz : 1);

    T * ptmp = _alloc.allocate(newCap);
    if(_elem != nullptr)
    {
        std::uninitialized_copy(_elem, _first_free, ptmp);

        while(_first_free != _elem)
        _alloc.destroy(--_first_free);
        _alloc.deallocate(_elem, sz);
    }

    _elem = ptmp;
    _first_free = _elem + sz;
    _end = _elem + newCap;
}
#endif

#if 1
template <typename T>
void Vector<T>::reallocate()
{
    unsigned sz=size();
    if(sz==0)
    {
        _elem=_alloc.allocate(2);
        _first_free=_elem+sz;
        _end=_elem+2;
    }else
    {
        T * ptmp=_alloc.allocate(2*size());
        std::uninitialized_copy(_elem,_first_free,ptmp);
        while(_first_free!=_elem)
            _alloc.destroy(--_first_free);
        _alloc.deallocate(_elem,sz);
        _elem=ptmp;
        _first_free=_elem+sz;
        _end=_elem+2*size();
    }
}
#endif

int main()
{
    Vector <int> a;
    for(int i=0;i<10;i++)
        a.push(i);
    for(int i=0;i<10;i++)
    {
        a.pop();
        cout<<a.size()<<endl;
        cout<<a.capacity()<<endl;
    }
}
