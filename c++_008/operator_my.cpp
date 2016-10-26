//->操作符重载
#include <iostream>
using namespace std;

class CData
{
    public:
        int GetLen() {return 5;}
};

class CDataPtr
{
    private:
        CData *m_pData;

    public:
        CDataPtr()
        {
                    m_pData = new CData;
        }

        ~CDataPtr()
        {
                    delete m_pData;
        }

        //->操作符重载
        CData * operator->()
        {
                    cout << "->操作符重载函数被调用." << endl;
                    return m_pData;
                }
};

int main()
{
        CDataPtr p;
        cout << p->GetLen() << endl;endl//等价于下面1句:
        cout << (p.operator->())->GetLen() << endl;

        p.m_pData->GetLen();

        return 0;
}


