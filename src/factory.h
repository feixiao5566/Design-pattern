#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <iostream>
#include <string>
//单核
class SingleCore
{
    public:
        virtual void  Show() = 0;
};
class SingleCoreA: public SingleCore
{
    public:
        void Show()
        {
            std::cout<<"Single Core A"<<std::endl;
        }
};
class SingleCoreB: public SingleCore
{
    public:
        void Show()
        {
            std::cout<<"Single Core B"<<std::endl;
        }
};
//多核
class MultiCore
{
    public:
        virtual void Show() = 0;
};
class MultiCoreA: public MultiCore
{
    public:
        void Show()
        {
            std::cout<<"Multi Core A"<<std::endl;
        }
};
class MultiCoreB: public MultiCore
{
    public:
        void Show()
        {
            std::cout<<"Multi Core B"<<std::endl;
        }
};
//工厂
class CoreFactory
{
    public:
        virtual SingleCore* CreateSingleCore() = 0;
        virtual MultiCore* CreateMultiCore() = 0;
};
//工厂A,专门用来生产A型号的处理器
class FactoryA: public CoreFactory
{
    public:
        SingleCore* CreateSingleCore()
        {
            return new SingleCoreA();
        }
        MultiCore* CreateMultiCore()
        {
            return new MultiCoreA();
        }
}
//工厂B，专门用来生产B型号的处理器
class FactoryB : public CoreFactory
{
public:
    SingleCore* CreateSingleCore() { return new SingleCoreB(); }
        MultiCore* CreateMultiCore() { return new MultiCoreB(); }
};
