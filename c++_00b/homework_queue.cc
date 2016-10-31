///
/// @file    homework_queue.cc
/// @author  ToTYToT(hongzimeng@foxmail.com)
/// @date    2016-10-29 16:38:32
///

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
template <typename T,int SIZE=10>
class Queue
{
    public:
    //Queue(int size)
    Queue()
    : _front(0)
    , _rear(0)
//    , _size(size)
//    , _arr(new int[_size])
    {

    }

    ~Queue()
    {
//        delete [] _arr;
    }

    bool empty()
    {
        return _front == _rear;
    }
    bool full()
    {
        //return _front == (_rear + 1) % _size;
        return _front == (_rear + 1) % SIZE;
    }
    void push(T num)
    {
        if(!full())
        {
            _arr[_rear] = num;
            ++_rear;
            _rear %= SIZE;
        }
        else
        {
            cout << "queue is full" << endl;
        }
    }
    void pop()
    {
        if(!empty())
        {
            ++_front;
            _front %= SIZE;
        }
        else
        {
            cout << "queue is empty" << endl;
        }
    }
    T front()
    {
        if(!empty())
        {
            return _arr[_front];
        }
        else
        {
            cout << "queue is emtpy" << endl;
            //return (T) 0;
        }
    }
    T back()
    {
        if(!empty())
        {
            return _arr[(_rear - 1 + SIZE) % SIZE];
        }
        else
        {
            cout << "queue is empty" << endl;
            //return (T) 0;
        }
    }
private:
    int _front;
    int _rear;
    //int _size;
//    int * _arr;
    T _arr[SIZE];
};
#if 0
int main(void)
{
    Queue queue(4);

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);

    cout << "对头元素：" << queue.front() << endl;
    cout << "对头元素出队" << endl;
    queue.pop();
    queue.push(4);

    cout << "对尾元素:" << queue.back() << endl;

    return 0;
}
#endif
//#if 1
int main(void)
{
    Queue<int,10> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);

    cout << "对头元素：" << queue.front() << endl;
    cout << "对头元素出队" << endl;
    queue.pop();
    queue.push(4);

    cout << "对尾元素:" << queue.back() << endl;
//}
//#endif

//int main(void)
//{
    Queue<string> queue1;
    queue1.push("hello");
    queue1.push("world");
    queue1.push("nihao");
    queue1.push("meinv");

    cout << "对头元素：" << queue1.front() << endl;
    cout << "对头元素出队" << endl;
    queue1.pop();
    queue1.push("let'go");

    cout << "对尾元素:" << queue1.back() << endl;
}
