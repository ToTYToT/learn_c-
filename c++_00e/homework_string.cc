 ///
 /// @file    homework_string.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-04 22:02:34
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
    String()
    :_pstr(new char[1])
    {
        cout<<"String"<<endl;
    }
    String(const char* p)
    :_pstr(new char[strlen(p)+1])
    {
        cout<<"String(const char*)"<<endl;
        strcpy(_pstr,p);
    }
    ~String()
    {
        cout<<"~String"<<endl;
        delete [] _pstr;
    }
    String(const String &rth)
    :_pstr(new char[strlen(rth._pstr)+1])
    {
        cout<<"String(String&)"<<endl;
        strcpy(_pstr,rth._pstr);
    }
    String(String && rth)
    :_pstr(rth._pstr)
    {
        cout<<"String(String&&)"<<endl;
        rth._pstr=nullptr;
    }
    String & operator=(const String &rth)
    {
        delete [] _pstr;
        _pstr=new char[strlen(rth._pstr)+1];
        strcpy(_pstr,rth._pstr);
        return *this;
    }
    String & operator=(String &&rth)
    {
        char * tmp=_pstr;
        _pstr=rth._pstr;
        rth._pstr=tmp;
        return *this;
    }
    friend std::ostream & operator<< (std::ostream &os,const String &rth);
private:
    char * _pstr;
};
std::ostream & operator <<(std::ostream & os, const String & rhs)
{
    os << rhs._pstr;
    return os;
}
int test0(void)
{
    #if 1
    String s1 = "hello";
    cout << "s1 = " << s1 << endl;

    String s2("world");
    cout << "s2 = " << s2 << endl;
    cout << endl;
    #endif

    String s3 = String("shenzhen");
    cout << "s3 = " << s3 << endl;
    cout << endl;

    s3 = "wangdao";
    cout << "s3 = " << s3 << endl;


    return 0;
}

int main(void)
{
    test0();
}
