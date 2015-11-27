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
