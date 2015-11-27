#include <iostream>
#include <string>
#include <string.h>
#include "resume.h"
#include "resumeA.h"
#include "resumeB.h"

int main()
{
    Resume *r1 = new ResumeA("A");
    Resume *r2 = new ResumeB("B");
    Resume *r3 = r1->Clone();
    Resume *r4 = r2->Clone();
    r1->Show();
    r2->Show();
    //删除r1,r2
    delete r1;
    delete r2;
    r1 = r2 = NULL;
    //深拷贝所以对r3,r4无影响
    r3->Show();
    r4->Show();
    delete r3;
    delete r4;
    r3 = r4 = NULL;
    return 0;
}

//具体操作步骤
//一. 声明一个抽象类.并定义clone()函数为春虚函数
//二. 实例化各个子类,并且实现赋值构造函数,并实现clone()函数


//意图:
//      用原型实例指定创建对象的种类,并且通过拷贝这些原型创建新的对象
//适用性:
//      当一个系统应该独立于它的产品创建、构成和表示时，需要使用原型模式
//      当要实例化的类是在运行时刻指定时，如通过动态转载
//      为了避免创建一个与产品类层次平行的工厂类层次时
//
//当一个类的实例只能有几个不同状态组合中的一种时，建立相应数目的原型并克隆
//他们可能比每次用合适的状态手工实例化类更方便一些。
