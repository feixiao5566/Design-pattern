#include <iostream>
using namespace std;
class Base
{
    public:
        virtual void f(float x){cout<<"Base::f(float)"<<x<<endl;}
        void g(float x){cout<<"Base::g(float)"<<x<<endl;}
        void h(float x){cout<<"Base::h(float)"<<x<<endl;}
};

class Derived : public Base
{
    public:
        virtual void f(float x){cout<<"Derived::f(float)"<<x<<endl;}
        void g(int x){cout<<"Derived::g(int)"<<x<<endl;}
        void h(float x){cout<<"Derived::h(float)"<<x<<endl;}
};

int main(void)
{
    Derived d;
    Base *pb = &d;
    Derived *pd = &d;
    //Good:behavior depends solely on type of the object
    pb->f(3.14f);   //Derived::f(float)3.14
    pd->f(3.14f);   //Derived::f(float)3.14
    //Bad:behavior depends on type of the pointer
    pb->g(3.14f);   //Base::g(float)3.14
    pd->g(3.14f);   //Derived::g(int)3(surprise!)
    //Bad:behavior depends on type of the pointer
    pb->h(3.14f);   //Bese::h(float)3.14(surprise!)
    pd->h(3.14f);   //Derived::h(folat)3.14
    return 0;
}

//bp和dp指向同一地址.按理说运行结果 应该是相同的.而事实上却不同
//林锐把原因归结为C++的隐藏规则,其实这一观点是错的.
//决定bp和dp调用函数运行的结果的不是他们指向的地址,而是他们的指针类型
//只有在通过基类指针或引用间接指向派生类子类型时多态性才会起作用
//pb是基类指针,pd是派生类指针,pd的所有函数调用都只是调用自己的函数,和多态性无关
//所以pd的所有函数调用的结果都输出Derived::是完全正常的;
//pb的函数调用如果有virtual则根据多态性调用派生类的,
//如果没有virtual则是正常的静态函数调用,还是调用基类的.
//所以有virtual的f函数调用输出Derived::,
//其它两个没有virtual则还是输出Base::很正常啊,nothing surprise!
//
//林锐博士大约陷入C指针大坑太深..
//
//只有在通过基类指针或引用间接指向派生类子类型时多态性才会起作用
