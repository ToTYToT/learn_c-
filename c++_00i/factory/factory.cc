 ///
 /// @file    factory.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-11-12 15:02:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//1. 使用一致的创建对象的接口
//2. 针对复杂对象，推荐采用工厂模式
//3. 简单对象没必要
class ShapeI
{
    friend class ShapeFactory;
    public: 
	virtual void draw()=0;
};
class Shape:public ShapeI
{
    protected:
Shape(){};

public:
	//virtual void draw()=0;
};


class Circle :public Shape
{
public:
	Circle(){}
#if 0
	Circle(,,,,){
		
	}
#endif
	void draw()
	{
		cout << "Circle::draw()" << endl;
	}
private:
	//...
};

class Rectangle : public Shape
{
public:
	void draw()
	{
		cout << "Rectangle::draw()" << endl;
	}
};

class Square : public Shape
{
public:
	void draw()
	{
		cout << "Square::draw()" << endl;
	}
};

enum ShapeType
{
	CIRCLE,
	RECTANGLE,
	SQUARE
};

class ShapeFactory
{//1. 没有完全做到开闭原则
public:
	ShapeI * getShape(ShapeType type)
	{
		if(type == CIRCLE)
		{	
			//复杂对象
			return new Circle;
		}else if(type == RECTANGLE)
		{
			return new Rectangle;
		}else if(type == SQUARE)
		{
			return new Square;
		}
		return nullptr;
	}
};


int main(void)
{
	ShapeFactory sf;
    sf.getShape(CIRCLE)->draw();
    sf.getShape(SQUARE)->draw();
    sf.getShape(RECTANGLE)->draw();
	ShapeI * pShap = sf.getShape(CIRCLE);
	pShap->draw();
#if 0
	pShap = sf.getShape(SQUARE);
	pShap->draw();

	pShap = sf.getShape(RECTANGLE);
	pShap->draw();


	Shape * p = new Circle;
	p->draw();
#endif
	return 0;
}
