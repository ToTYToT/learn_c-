 ///
 /// @file    observer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-12 16:12:56
 ///
 
#include <iostream>
#include <list>
#include <algorithm>
using std::cout;
using std::endl;
using std::list;

typedef int State;

class Observer;
class Subject
{
public:
	Subject(): _subjectState(-1){}

	void attach(Observer * ob);
	void detach(Observer * ob);
	void notify();

	virtual void setState(State state)
	{
		_subjectState = state;
	}

	virtual State getState(){
		return _subjectState;
	}

	virtual ~Subject(){}
protected:
	State _subjectState;
	list<Observer*> _list;
};

void Subject::attach(Observer * ob)
{
	auto it = std::find(_list.begin(), _list.end(), ob);
	if(it == _list.end()){
		cout << "attach observer" << endl;
		_list.push_back(ob);
	}
}

void Subject::detach(Observer * ob)
{
	auto it = std::find(_list.begin(), _list.end(), ob);
	if(it != _list.end()){
		cout << "erase observer" << endl;
		_list.erase(it);
	}
}

class Observer
{
public:
	Observer():_obState(-1)
	{}

	virtual void update(Subject * subject)=0;

protected:
	State _obState;
};

void Subject::notify()
{
	cout << "nofity()" << endl;
	list<Observer*>::iterator it;
	for(it = _list.begin();
		it != _list.end();
		++it)
	{
		(*it)->update(this);
	}
}

class ConcreateObserver : public Observer
{
public:
	ConcreateObserver(){}

	//推模式(被动,传消息本身):
	//拉模式(主动,传指针):
	void update(Subject * subject)
	{
		State subState = subject->getState();
		if(_obState != subState)
		{//发生变化
			_obState = subState;
			cout << this << ":subject is " << _obState << endl;
		}
	}
};


int main(void)
{
	Observer * p1 = new ConcreateObserver;
	Observer * p2 = new ConcreateObserver;

	Subject subject;
	subject.attach(p1);
	subject.attach(p2);

	subject.setState(10);
    subject.notify();

	subject.detach(p1);
	subject.setState(20);
	subject.notify();

	return 0;
}
