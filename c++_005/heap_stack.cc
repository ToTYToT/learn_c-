 ///
 /// @file    heap_stack.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-21 11:28:31
 ///
 
#include <iostream>
using std::cout;
using std::endl;
#if 0
class hellogirl
{
public:
    hellogirl()
    {
        cout<<"I love you!"<<endl;
    }
private:
    ~hellogirl()
    {
        cout<<"It's not your business!"<<endl;
    }
};
int main(void)
{
    //hellogirl li;
	//hellogirl * li=new hellogirl();
    hellogirl beatiful();
    return 0;
}
#endif


#if 1 
class hellogirl
{
public:
    hellogirl()
    {
        cout<<"I love you!"<<endl;
    }
    ~hellogirl()
    {
        new hellogirl();
        cout<<"It's not your business!"<<endl;
    }
private:
    static void * operator new (size_t size)
    {
        cout<<"so,heap is out"<<endl;
    }
};
int main(void)
{
    hellogirl li;
	//hellogirl * li=new hellogirl();
    hellogirl beatiful();
    return 0;
}
#endif
