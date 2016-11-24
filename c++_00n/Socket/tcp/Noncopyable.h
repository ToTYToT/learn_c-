/*********************************
 *@fileName: Noncopyable.h
 *@author  : lemon
 *@email   : haohb13@gmail.com
 *@created : 2015-05-08 11:00:46
**********************************/

#ifndef WD_NONCOPYABLE_H
#define WD_NONCOPYABLE_H

class Noncopyable
{
protected:
	Noncopyable(){}
	~Noncopyable(){}
private:
	Noncopyable(const Noncopyable &rhs);
	Noncopyable & operator=(const Noncopyable &rhs);
};


#endif

