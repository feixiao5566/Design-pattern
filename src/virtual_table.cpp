#include <iostream>

class Base
{
    public:
        virtual void f(){std::cout<<"Base::f"<<std::endl;}
        virtual void g(){std::cout<<"Base::g"<<std::endl;}
        virtual void h(){std::cout<<"Base::h"<<std::endl;}
    private:
        virtual void j(){std::cout<<"private menber!"<<std::endl;}
};
class Derive : public Base
{};
int main()
{
    typedef void(*Fun)(void*);
    Base b;
    Derive d;
    Fun pFun = (Fun)*((int*)*(int*)(&d));
    pFun(&d);
    Fun pFun = (Fun)*((int*)*(int*)(&d)+2);
    pFun(&d);
    Fun pFun = (Fun)*((int*)*(int*)(&d)+4);
    pFun(&d);

//以下,是浩哥写错的 O_O
//    Base* pBuf = new Devition();
//    pBuf->f();
//    std::cout<<"虚函数表地址: "<<(int*)(&b)<<std::endl;
//    std::cout<<"虚函数表---第一个函数地址: "<<(int*)*(int*)(&b)<<std::endl;

    //Invoke the first virtual function
//    pFun = (Fun)*((int*)*(int*)(&b));
//    pFun();
    return 0;
}
