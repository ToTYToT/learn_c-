 ///
 /// @file    Student.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-10-20 11:01:27
 ///
 
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class Student
{
public:
	Student(int id, const char * name)
	: _id(id)
	, _name(new char[strlen(name) + 1])
	{
		cout << "Student(int,const char *)" <<endl;
		strcpy(_name, name);
	}

	~Student()
	{
		delete [] _name;
		cout << "~Student()" << endl;
	}

	void display()
	{
		cout << "学号:" << _id << endl;
		cout << "姓名:" << _name << endl;
	}

	static void * operator new(size_t size)
	{
		cout << "void * operator new(size_t)" << endl;
		void * p = malloc(size);
		return p;
	}

	static void operator delete(void * p)
	{
		cout << "void operator delete(void*)" << endl;
		free(p);
	}
private:
	int _id;
	char * _name;
};

int main(void)
{
	Student * stu = new Student(100, "Mike");
	stu->display();

	delete stu;
	
	return 0;
}
