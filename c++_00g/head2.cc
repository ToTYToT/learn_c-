 ///
 /// @file    head2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-07 14:41:17
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


//大量运用组合　
class Head
{
public:
	void look()
	{	_eye.look();	}

	void smell()
	{	_nose.smell();	}

	void eat()
	{	_mouth.eat();	}

	void listen()
	{	_ear.listen();	}
private:
	Eye   _eye;
	Nose  _nose;
	Mouth _mouth;
	Ear   _ear;
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

