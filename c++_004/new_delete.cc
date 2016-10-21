 ///
 /// @file    new_delete.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-10-20 11:04:16
 ///
 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Student
{
    public:
    int iId;
    char szName[10];
    public:
    Student()    {
        std::cout << "Student 构造函数被调用" << std::endl;
    }

    ~Student()
    {
        std::cout << "Student 析构函数被调用" << std::endl;
    }

    private:
    static void* operator new(std::size_t nSize);
    static void operator delete(void *pVoid);

#if 1
	static void* operator new(std::size_t nSize)
	{
		std::cout << "new 操作符被调用, size = " << nSize << std::endl;
		//void *pRet = new char[nSize];
		void *pRet = malloc(nSize);
		return pRet;
	}
	static void operator delete(void *pVoid)
	{
		std::cout << "delete操作符被调用." << std::endl;
		free(pVoid);
	}
#endif
};

int main(void)
{
	Student *pstu = new Student;
	pstu->iId = 101;
	strcpy(pstu->szName, "Tony");
	std::cout << std::endl;
	delete pstu;

	std::cout << std::endl;
	Teacher *pt = new Teacher();
	delete pt;
	return 0;
}

