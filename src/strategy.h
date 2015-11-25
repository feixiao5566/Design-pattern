#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include <iostream>
#include <string>

//替换算法定义
//抽象接口
class ReplaceAlgorithm
{
    public:
        virtual void Replace() = 0;
};
//三种具体的替换算法
class LRU_ReplaceAlgorithm : public ReplaceAlgorithm
{
    public:
        void Replace()
        {
            std::cout<<"Least Recently Used repalce algorithm"<<std::endl;
        }
};
class FIFO_ReplaceAlgorithm : public ReplaceAlgorithm
{
    public:
        void Repalce()
        {
            std::cout<<"First in First out repalce algorithm"<<std::endl;
        }
};
class Random_RepalceAlgorithm : public ReplaceAlgorithm
{
    public:
        void Replace()
        {
            std::cout<<"Random repalce algorithm"<<std::endl;
        }
};
#endif
