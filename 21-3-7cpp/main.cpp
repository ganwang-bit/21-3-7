//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    cout << "Hello world!" << endl;
//    return 0;
//}
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//    cout << "Hello world!" << endl;
//    return 0;
//}
#include<iostream>
using namespace std;
#include<cstring>
template <class T>
class A
{
public:
    A(int number)
    {
        cout<<"A::A(int number)"<<endl;
        this->number=number;
        this->m_size=0;
        this->p=new T[number];
    }
    A(A&l)
    {
        cout<<"A::A(A&l)"<<endl;
        this->m_size=l.m_size;
        this->number=l.number;
        this->p=new T[number];
        memcpy(this->p,l.p,number*sizeof(T));
    }
    A& operator=(const A&tmp)
    {
        cout<<"operator"<<endl;
        this->m_size=tmp.m_size;
        this->number=tmp.number;
        delete [] p;
        p=new T[number];
        memcpy(this->p,tmp.p,sizeof(T)*number);
        return *this;
    }
    T& operator[](int tmp)
    {
        return p[tmp];
    }
    ~A()
    {
        cout<<"A::~A()"<<endl;
        if(this->p!=NULL)
            delete [] this->p;
    }
    void Push_back(const T&tmp)
    {
        if(m_size==number)
        {
            cout<<"????????"<<endl;
            return  ;
        }
        p[m_size++]=tmp;
    }
    void Pop_back()
    {
        if(!m_size)
            return ;
        m_size--;
    }
    int getnumber()
    {
        return number;
    }
    int getsize()
    {
        return m_size;
    }
    void show()
    {
        for(int i=0;i<m_size;i++)
        {
            cout<<p[i]<<endl;
        }
    }
private:
    T*p;
    int m_size;
    int number;
};
class Person
{
public:
    Person(){}
    friend ostream& operator<<(ostream& out,Person&tmp);
    Person(int age)
    {
        this->age=age;
    }
private:
    int age;
};
ostream&operator<<(ostream&out,Person&tmp)
{
    out<<"age:"<<tmp.age;
    return out;
}
int main()
{
//    A <int>a(10);
//    A <int>b(20);
//    A <int>c=b;
//    a=b;
//    a.Push_back(10);
//    cout<<a[0]<<endl;
//    a[0]=20;
//    a.show();
//    a=b;
//    for(int i=0;i<21;i++)
//    {
//        a.Push_back(i);
//    }
//    a.show();
//    cout<<a.getnumber()<<endl;
//    cout<<a.getsize()<<endl;
//    b=a;
//    b.Pop_back();
//    cout<<b.getnumber()<<endl;
//    cout<<b.getsize()<<endl;
//    b.show();
    A<Person>a(10);
    Person a1(20);
    Person a2(30);
    a.Push_back(a1);
    a.Push_back(a2);
    a.show();
    cout<<a.getnumber()<<endl;
    cout<<a.getsize()<<endl;
    return 0;
}
