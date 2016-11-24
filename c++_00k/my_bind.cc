 ///
 /// @file    my_bind.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-15 14:54:24
 ///

#include <functional>

int Func(int x, int y);
auto bf1 = std::bind(Func, 10, std::placeholders::_1);
bf1(20); ///< same as Func(10, 20)

class A
{
    public:
    int Func(int x, int y);
};

int main(void)
{
    A a;
    auto bf2 = std::bind(&A::Func, a, std::placeholders::_1, std::placeholders::_2);
    bf2(10, 20); ///< same as a.Func(10, 20)

    std::function< int(int)> bf3 = std::bind(&A::Func, a, std::placeholders::_1, 100);
    bf3(10); ///< same as a.Func(10, 100)
}


//7.3 

void f(int n1, int n2, int n3, const int& n4, int n5)
{
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}

int g(int n1)
{
    return n1;
}

struct Foo {
    void print_sum(int n1, int n2)
    {
        std::cout << n1+n2 << '\n';
    }
    int data = 10;
};


int main()
{
    using namespace std::placeholders;  // for _1, _2, _3...

    // demonstrates argument reordering and pass-by-reference
    int n = 7;
    // (_1 and _2 are from std::placeholders, and represent future
    // arguments that will be passed to f1)
    auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n);
    n = 10;
    f1(1, 2, 1001); // 1 is bound by _1, 2 is bound by _2, 1001 is unused

    // bind to a member function
    Foo foo;
    auto f3 = std::bind(&Foo::print_sum, &foo, 95, _1);
    f3(5);

    // bind to member data
    auto f4 = std::bind(&Foo::data, _1);
    std::cout << f4(foo) << '\n';

    return 0;
}


