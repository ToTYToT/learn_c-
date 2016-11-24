 ///
 /// @file    weak_ptr.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-05 11:18:50
 ///
#if 0 
#include <iostream>
#include <memory>

class Parent;
class Child;

typedef std::shared_ptr<Parent> parent_ptr;
typedef std::shared_ptr<Child> child_ptr;

class Child
{
    public:
    Child() {   std::cout << "Child..." << std::endl;   }
    ~Child() {  std::cout << "~Child..." << std::endl;  }
    parent_ptr parent_;
};

class Parent
{
    public:
    Parent() {  std::cout << "Parent..." << std::endl;  }
    ~Parent() { std::cout << "~Parent..." << std::endl; }
    std::weak_ptr<Child> child_;
};

int main(void)
{
    parent_ptr parent(new Parent);
    child_ptr child(new Child);
    parent->child_ = child;
    child->parent_ = parent;

    return 0;
}
#endif

#include <iostream>
#include <memory>

class Parent;
class Child;

typedef std::shared_ptr<Parent> parent_ptr;
typedef std::shared_ptr<Child> child_ptr;

class Child
{
    public:
    Child() {   std::cout << "Child..." << std::endl;   }
    ~Child() {  std::cout << "~Child..." << std::endl;  }
    parent_ptr parent_;
};

class Parent
{
    #include <iostream>
    #include <memory>

    class Parent;
    class Child;

    typedef std::shared_ptr<Parent> parent_ptr;
    typedef std::shared_ptr<Child> child_ptr;

    class Child
    {
        public:
        Child() {   std::cout << "Child..." << std::endl;   }
        ~Child() {  std::cout << "~Child..." << std::endl;  }
        parent_ptr parent_;
    };

    class Parent
    {
        public:
        Parent() {  std::cout << "Parent..." << std::endl;  }
        ~Parent() { std::cout << "~Parent..." << std::endl; }
        child_ptr child_;
    };

    int main(void)
    {
        parent_ptr parent(new Parent);
        child_ptr child(new Child);
        parent->child_ = child;
        //parent.operator->()->child_ = child;
        child->parent_ = parent;

        return 0;
    }

class Parent
{
    #include <iostream>
    #include <memory>

    class Parent;
    class Child;

    typedef std::shared_ptr<Parent> parent_ptr;
    typedef std::shared_ptr<Child> child_ptr;

    class Child
    {
        public:
        Child() {   std::cout << "Child..." << std::endl;   }
        ~Child() {  std::cout << "~Child..." << std::endl;  }
        parent_ptr parent_;
    };

    class Parent
    {
        public:
        Parent() {  std::cout << "Parent..." << std::endl;  }
        ~Parent() { std::cout << "~Parent..." << std::endl; }
        child_ptr child_;
    };

