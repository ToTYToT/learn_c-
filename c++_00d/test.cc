 ///
 /// @file    test.cc
 /// @author  ToTYToT(hongzimeng@foxmail.com)
 /// @date    2016-11-01 11:30:24
 ///
#if 0 
#include <iostream>
#include <algorithm>                        //使用for_each算法要包含的头文件  
#include <functional>                       //使用less<>类模板要用的头文件
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<int>::iterator VIP;
#if 0
int main()
{
        int sz[]={1,2,3,4,5,6};
        VI ob(sz,sz+6);
        less<int> lt;                           //创建less<int>类函数对象
        replace_if(ob.begin(),ob.end(),bind2nd(lt,3),7);    //将ob中小于3的元素全部替换成7
        //如果换成replace_if(ob.begin(), ob.end(), bind1st(lt, 3), 7); // 1 2 3 7 7 7

        for (VIP v=ob.begin();v!=ob.end();v++)
        {
                    cout<<(*v)<<"  ";
                }
        cout<<endl;

        getchar();
        return 0;
}
#endif
#if 0
int main(void)
{
        std::vector<std::string> vcs;
        vcs.push_back("this is A"); 
        std::vector<std::string>::iterator it = vcs.begin();
        int i = 9;
        for(; it != vcs.end(); ++it)
        {
					//unsigned p=it;
                    std::cout << "caplity of vector is : " << vcs.size() << std::endl;
                    //std::cout << it  << std::endl;
                    std::cout << "---> " << *it << std::endl;//直接coredump
                    if(i == 9)
                    {
                                    vcs.push_back("this is BBBB");
                                    std::cout << "vcs.push! " << std::endl;
                                }
                    i = 8;
                }
}
#endif

#if 0

int main(void)
{
	std::vector<int> v;
	v.reserve(10);
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	for(size_t i = 1; i <= 10; ++i)
	{
		v.push_back(i);
	}
	v[3] = v[5] = v[9] = 99;
	std::cout << "添加并修改完数据后:" << v.size() << std::endl;;
	for(auto it : v)
	{
		std::cout << it << std::endl;
	}
	remove(v.begin(), v.end(), 99);
	//v.erase(remove(v.begin(), v.end(), 99),
	//             v.end());
	std::cout << "remove完数据后：" << v.size() << std::endl;;
	for(auto it : v)
	{
		std::cout << it << std::endl;
	}
	return 0;

}
#endif 
#endif 
#if 0

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int sz[6]={1,2,3,4,5,6};
	vector<int> ob(sz,sz+6);					//创建vector<int>容器ob
	ostream_iterator<int,char> osi(cout," ");	//创建输出流迭代器osi, 将osi理解为容器
	copy(ob.begin(),ob.end(),osi);				//将ob复制到流中: copy是泛型算法
	cout<<endl;

	getchar();
	return 0;
}
#endif

#if 0

//13-15 输入流迭代器
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> ob;					//创建vector<int>容器ob
	istream_iterator<int,char> isi(cin);	//创建输入流迭代器osi
	copy(isi,istream_iterator<int,char>(),back_inserter(ob));		//将输入流插入到ob中
	//只作了解
	for (vector<int>::iterator it=ob.begin();it!=ob.end();it++)	//遍历输出ob中的元素
	{
		cout<<(*it)<<"  ";
}
cout<<endl;

getchar();
return 0;
}
#endif
#if 0

//13-16 for_each()用法示例
#include <iostream>
#include <algorithm>						//使用for_each算法要包含的头文件	
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef VI::iterator VIP;

void func(VI::value_type v)					//定义一元函数func，以元素类型为参数
{
	cout<<v<<"  ";

}

int main()
{
	int sz[]={1,2,3,4,5,6};
	VI ob(sz,sz+6);
	for_each(ob.begin(),ob.end(),func);		//对ob中所有元素执行func操作
	cout<<endl;

	getchar();
	return 0;
}

//对于for_each而言，如果是vector<int> ob;这样的，此时调用for_each(ob.begin(), ob.end(), func);函数的时候，
//func函数的参数是int(或vector<int>::value_type)
//如果是map<int, string> obM;这样的，此时调用for_each(obM.begin(), obM.end(), func);函数的时候，
//func函数的参数是pair<int, string>这种数据类型的。
//总结：对于for_each的第三个参数而言，写函数的时候，函数的参数就是其中的迭代器指向的类型。
//对于vector<CMyString> 则是CMyString
//对于map<CMyString, string>则是由CMyString和string组成的，所以是pair<CMyString, string>
#endif
#if 0 

//stack用法示例1
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main()
{
	stack<int, vector<int> > obi;	//使用vector取代其默认的deque做为stack的实现基础
	for (int i = 1; i <= 20; i++)
	{
		obi.push(i);
	}

	while (obi.size() > 0)
	{
		int x = obi.top();
		cout << x << "  ";
		obi.pop();
	}

	cout << endl << endl;

	stack<string, vector<string> > obs;
	for (char c = 'A'; c <= 'Z'; c++)
	{
		string s(2, c);
		obs.push(s);
	}

	while (obs.size() > 0)
	{
		string s = obs.top();
		cout << s << "  ";
		obs.pop();
	}

	//3. 
	getchar();
	return 0;
}

#endif
#if 0

//stack 用法示例2
#include <iostream>
using namespace std;
#include <stack>

int main()
{
	int i = 0;
	stack<int> v;
	for (i = 0; i < 10; i++)
	{
		v.push(i);		//把元素一个一个存入到stack中
		cout << v.top() << " 已入栈" << endl;

	}
	cout << "现在stack的容量: " << v.size() << endl << endl;
	for (i = 0; i < 10; i++)
	{
		cout << v.top() << " 准备出栈" << endl;
		v.pop();//把元素一个一个出栈
	}
	cout << "现在stack的容量: " << v.size() << endl << endl;

	system("pause");
	return 0;
}


#endif
#if 0

//queue用法示例
#include <iostream>
using namespace std;
#include <queue>

int main()
{
	int i = 0;
	queue<int> v;
	for (i = 0; i < 10; i++)
	{
		v.push(i);	//把元素一个一个存入到queue中
		cout << v.back() << " 已入队列" << endl;

	}
	cout << "现在queue的容量: " << v.size() << endl << endl;
	for (i = 0; i < 10; i++)
	{
		cout << v.front() << " 准备出队列" << endl;
		v.pop();//把元素一个一个出栈
	}
	cout << "现在queue的容量: " << v.size() << endl << endl;

	system("pause");
	return 0;
}


#endif
#if 0

#include <queue>
//priority_queue 用法示例
#include <iostream>
using namespace std;

//priority_queue允许对存储的元素设置优先级。
//优先级队列的一个实例是机场行李检查队列。30分钟后即将离港的航班的乘客通常会设置高的优先级别。
//优先队列的例子如下：
int main()
{
	int i = 0;
	int array[10] = {0, 1, 3, 2, 5, 6, 9, 8, 7, 4};
	priority_queue < int > v;
	for (i = 0; i < 10; i++)
	{
		v.push(array[i]);	//	把元素一个一个存入到priority_queue中,并且在内部进行排序
		cout << v.top() << " 是目前这个队列中优先级别最高的" << endl;

	}
	cout << "现在priority_queue的容量:" << v.size() << endl << endl;

	for (i = 0; i < 10; i++)
	{
		cout << v.top() << "准备出队列" << endl;
		v.pop();//把元素一个一个出栈
	}
	cout << "现在priority_queue的容量:" << v.size() << endl << endl;

	system("pause");
	return 0;
}
#endif
#if 0

#include <stdlib.h>
#include <iostream>
using namespace std;
int compare(const void *arg1, const void *arg2);

int main(void)
{
	const int max_size = 10;		// 数组允许元素的最大个数
	int num[max_size];			// 整型数组

	// 从标准输入设备读入整数，同时累计输入个数，
	// 直到输入的是非整型数据为止
	int n;
	for (n = 0; cin >> num[n]; n ++);

	// C标准库中的快速排序（quick-sort）函数
	qsort(num, n, sizeof(int), compare);

	// 将排序结果输出到标准输出设备
	for (int i = 0; i < n; i ++)
		cout << num[i] << "\n";
}

// 比较两个数的大小，
// 如果*(int *)arg1比*(int *)arg2小，则返回-1
// 如果*(int *)arg1比*(int *)arg2大，则返回1
// 如果*(int *)arg1等于*(int *)arg2，则返回0
int compare(const void *arg1, const void *arg2)
{
	return	(*(int *)arg1 < *(int *)arg2) ? -1 :
		(*(int *)arg1 > *(int *)arg2) ? 1 : 0;
}
#endif


#if 0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> num;		// STL中的vector容器
	int element;

	// 从标准输入设备读入整数， 
	// 直到输入的是非整型数据为止
	while (cin >> element)
		num.push_back(element);

	// STL中的排序算法
	sort(num.begin(), num.end());

	// 将排序结果输出到标准输出设备
	for (unsigned int i = 0; i < num.size(); i ++)
		cout << num[i] << "\n";
}

#endif
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void)
{
	typedef vector<int>				int_vector;
	typedef istream_iterator<int>				istream_itr;
	typedef ostream_iterator<int>				ostream_itr;
	typedef back_insert_iterator< int_vector >	back_ins_itr;

	// STL中的vector容器
	int_vector num;

	// 从标准输入设备读入整数， 
	// 直到输入的是非整型数据为止
	copy(istream_itr(cin), istream_itr(), back_ins_itr(num));

	// STL中的排序算法
	sort(num.begin(), num.end());

	// 将排序结果输出到标准输出设备
	copy(num.begin(), num.end(), ostream_itr(cout, " "));
}
#endif
#include <iostream>
using std::cout;
using std::endl;
class T
{
public:
    T(int i)
    {
        cout <<"T"<<endl;
    }
};
int main()
{
    //T b;
    T a(1);
    T * b;
}
