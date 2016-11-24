 ///
 /// @file    head.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-07 14:37:03
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Eye
{
public:
	void look()
	{	cout << "Eye::look()" << endl;	}
};

class Nose
{
public:
	void smell()
	{	cout << "Nose::smell()" << endl;	}

};

class Mouth
{
public:
	void eat()
	{	cout << "Mouth::eat()" << endl;	}
};

class Ear
{
public:
	void listen()
	{	cout << "Ear::listen()" << endl;}
};


// 一般情况下不要轻易使用多重继承
// 如果出现多重继承，要考虑下是否
// 设计上出了问题
class Head
: public Eye
, public Nose
, public Mouth
, public Ear
{
};


int main(void)
{
	Head head;
	head.look();
	head.smell();
	head.eat();
	head.listen();

	return 0;
}
