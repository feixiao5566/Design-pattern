#ifndef __FACTORY_H__
#define __FACTORY_H__
#include <iostream>
#include <string>

enum CTYPE {COREA, COREB};  //之前input用过的enum办法,A是0,B是1
//之所以这样定义,用户在使用时只知道标签,不知道具体的定义.
class SingleCore
{
public:
    virtual void Show() = 0;
};
//单核A
class SingleCoreA: public SingleCore
{
public:
    void Show()
    {
        std::cout<<"SingleCore A"<<std::endl;
    }
};
//单核B
class SingleCoreB: public SingleCore
{
public:
    void Show()
    {
        std::cout<<"SingleCore B"<<std::endl;
    }
};
//唯一的工厂,可以生产两种型号的处理器核,在内部判断
class Factory
{
public:
    SingleCore* CreateSingleCore(enum CTYPE ctype)
    {
        if(ctype == COREA)  //工厂内部判断
            return new SingleCoreA();  //生产核A
        else
            if(ctype == COREB)
                return new SingleCoreB();  //生产核B
            else
                return NULL;
    }
};

//工厂设计模式属于创建型模式.
//简单工厂模式,它的主要特点是需要在工厂类中做判断,从而创造相应的产品.
//当增加新的产品时 就需要修改工厂类. 这就违反了开放封闭原则:
//软件实体(类 模板 函数)可以扩展, 但是不可修改.
//于是, 工厂方法模式出现了.


