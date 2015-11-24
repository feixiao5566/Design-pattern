#ifndef __FACTORY_H__
#define __FACTORY_H__
#include <iostream>
#include <string>

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
class Factory
{
    public:
        virtual SingleCore* CreateSingleCore() = 0;
};
//生产A核的工厂
class FactoryA: public Factory
{
    public:
        SingleCoreA* CreateSingleCore()
        {
            return new SingleCoreA;
        }
};
//生产B核的工厂
class FactoryB: public Factory
{
    public:
        SingleCoreB* CreateSingleCore()
        {
            return new SingleCoreB;
        }
};

//工厂方法模式,定义一个用于创建对象的接口,让子类决定实例化哪一个类.
//Factory Method使一个类的实例化延迟到其子类.
//缺点是,每增加一种产品,就需要增加一个对象的工厂.
//显然,相比于简单工厂模式,工厂方法模式需要更多的类定义
