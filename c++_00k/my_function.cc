 ///
 /// @file    my_function.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-15 14:35:59
 ///

#include <functional>
#include <iostream>
#define THE_INFO_OF_RUN (std::cout<<"                FILE:"<<__FILE__<<" LINE:"<<__LINE__<<endl)

struct Foo {
    Foo(int num) : _num(num) {}
    void print_add(int i) const { std::cout << _num+i << '\n'; }
    int _num;
}; 

void print_num(int i)
{
    std::cout << i << '\n';
}

struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};

int main()
{
    // store a free function
    std::function<void(int)> f_display = print_num;
    f_display(-9);

    // store a call to a member function
    std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
    const Foo foo(314159);
    f_add_display(foo, 1);

    // store a call to a function object
    std::function<void(int)> f_display_obj = PrintNum();
    f_display_obj(18);

    // store the result of a call to std::bind
    std::function<void()> f_display_31337 = std::bind(print_num, 31337);
    f_display_31337();


    // store a call to a member function and object
    using std::placeholders::_1;
    std::function<void(int)> f_add_display2= std::bind( &Foo::print_add, foo, _1 );
    f_add_display2(2);

    // store a call to a member function and object ptr
    std::function<void(int)> f_add_display3= std::bind( &Foo::print_add, &foo, _1 );
    f_add_display3(3);

}
