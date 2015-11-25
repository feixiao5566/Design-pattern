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
        RA m_ra;
};
#endif
