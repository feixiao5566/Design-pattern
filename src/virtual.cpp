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
//
//---------------2015年11月26日---------------
//重新回来看昨天的这段代码
//发觉林锐博士并没有错很多,而董俊杰也有点点道理,但他应该是没有理解林锐想要表达的意思
//
//今天学习了陈皓的C++虚函数表解析
//重新来评论下昨天的问题
//之所以会Base *b = new Derive()这样写. 因为父类指针是指向子类实例,来调用实际的函数的.
//因此作者董俊杰说的"决定bp和dp调用函数的是他们的指针类型"
//而林锐博士说"令人迷惑的隐藏规则"是每个虚函数的父类都有自己的虚函数表
//当子类和父类重名时,子类函数会在虚函数表上覆盖父类函数
//---先理解这么多,等我再长大一些再继续盖这个楼
//另外,很明显的是董俊杰并没有看明白林锐在说什么
//而林锐当时写书时对虚函数知其然不知其所以然
//陈皓大大好厉害~
//
