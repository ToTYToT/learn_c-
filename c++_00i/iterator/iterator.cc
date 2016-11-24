 ///
 /// @file    iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-12 15:22:37
 ///
 
#include <iostream>
using std::cout;
using std::endl;

typedef int Data;


class Iterator;

class Aggregate
{
public:
	virtual Iterator* createIterator() =0;
	virtual int getSize()=0;
	virtual Data getItem(int nIdx)=0;
	virtual ~Aggregate(){}
};


class ConcreateAggregate : public Aggregate
{
public:
	ConcreateAggregate(int size)
	: _size(size)
	, _pData(new Data[_size])
	{
		for(int idx = 0; idx != _size; ++idx)
		{
			_pData[idx] = idx;
		}
	}

	Iterator * createIterator();

	int getSize()
	{
		return _size;
	}

	Data getItem(int idx)
	{
		return _pData[idx];
	}

	~ConcreateAggregate()

	{
		delete [] _pData;
	}

private:
	int _size;
	Data * _pData;
};

class Iterator
{
public:
	virtual void first()=0;
	virtual void next()=0;
	virtual bool isDone()=0;
	virtual Data currentItem()=0;
	virtual ~Iterator(){}
};

class ConcreateIterator : public Iterator
{
public:
	ConcreateIterator(Aggregate * pA)
	: _pA(pA)
	, _idx(0)
	{}

	void first()
	{
		_idx = 0;
	}
	void next()
	{
		++_idx;
	}
	bool isDone()
	{
		return _idx == _pA->getSize();
	}
	Data currentItem()
	{
		return _pA->getItem(_idx);
	}
private:
	Aggregate * _pA;
	int _idx;
};
	

Iterator * ConcreateAggregate::createIterator()
{
	return new ConcreateIterator(this);
}


int main(void)
{
	Aggregate * pAggregate = new ConcreateAggregate(10);
	Iterator * pIt = pAggregate->createIterator();

	for(pIt->first(); !(pIt->isDone()); pIt->next())
	{
		cout << pIt->currentItem() << " ";
	}
	cout << endl;

	delete pAggregate;
	delete pIt;

	return 0;
}

