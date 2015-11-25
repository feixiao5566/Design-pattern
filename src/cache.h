#ifndef __CACHE_H__
#define __CACHE_H__

#include <iostream>
#include "strategy.h"

//Cache需要用到替换算法
template <class RA>
class Cache
{
    public:
        Cache(){}
        ~Cache(){}
        void Replace()
        {
            m_ra.Replace();
        }
    private:
        RA m_ra;    //这意思是给RA的对象么?     是的
                    //但这还只是个模板的声明,这个时候的RA与stratery没啥关系
                    //在main函数里,有
                    //Cache<Random_ReplaceAlgorithm> cache; //模板实参
                    //这句才..
                    //相当于把RA的构造函数写在Cache
                    //main中初始化Cache是顺便就把RA给初始化了o_o
};
#endif
